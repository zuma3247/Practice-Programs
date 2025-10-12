#****************************************************************************************************
#
#       Name:         Muazuddin Mohammed
#       Course:       COSC 2110 Computer Languages: Python
#       Assignment:   Cities.py
#       Due Date:     04/30/25
#       Description:
#               This program connects to the cities.db database and allows the user
#               to display city information.
#
#****************************************************************************************************

import sqlite3
import tkinter

#****************************************************************************************************

class Cities:
    def __init__(self):
        self.main_window = tkinter.Tk()
        self.main_window.title('Population')

        self.top_label = tkinter.Label(self.main_window,
                                       text='',
                                       height=25,
                                       width=40,
                                       anchor='nw',
                                       justify=tkinter.LEFT)
        self.top_label.pack(padx=10, pady=10)

        self.show_all()

        btn_frame = tkinter.Frame(self.main_window)
        btn_frame.pack(pady=(0, 10))

        self.pop_btn = tkinter.Button(btn_frame,
                                      text=' 1 - Display cities sorted by population, ascending order',
                                      width=50,
                                      anchor='w',
                                      command=self.show_by_pop)
        self.pop_btn.pack(padx=10, pady=2)

        self.name_btn = tkinter.Button(btn_frame,
                                       text=' 2 - Display cities sorted by name',
                                       width=50,
                                       anchor='w',
                                       command=self.show_by_name)
        self.name_btn.pack(padx=10, pady=2)

        self.total_btn = tkinter.Button(btn_frame,
                                        text=' 3 - Display total population of all the cities',
                                        width=50,
                                        anchor='w',
                                        command=self.show_total)
        self.total_btn.pack(padx=10, pady=2)

        self.highest_btn = tkinter.Button(btn_frame,
                                          text=' 4 - Display city with the highest population',
                                          width=50,
                                          anchor='w',
                                          command=self.show_highest)
        self.highest_btn.pack(padx=10, pady=2)

        tkinter.mainloop()

    # ****************************************************************************************************

    def show_all(self):
        conn = None
        try:
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT CityID, CityName, Population FROM Cities'''
            cur.execute(my_query)
            results = cur.fetchall()

            output = 'Contents of cities.db/Cities table:\n' + '-' * 40 + '\n'

            for city_id, name, pop in results:
                output += f'{city_id:<4}{name:<20} {pop:,}\n'

            self.top_label.config(text=output)
        except sqlite3.Error as e:
            self.top_label.config(text=f'Database error:\n{e}')
        finally:
            if conn:
                conn.close()

    # ****************************************************************************************************

    def show_by_pop(self):
        conn = None
        try:
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT CityID, CityName, Population FROM Cities ORDER BY Population'''
            cur.execute(my_query)
            results = cur.fetchall()

            output = 'Cities Sorted By Population (Ascending)\n' + '-' * 40 + '\n'
            output += f"{'City':<20}{'Population':>18}\n" + '-' * 40 + '\n'
            for city_id, name, pop in results:
                output += f'{name:<20} {pop:>18,}\n'

            self.top_label.config(text=output)
        except sqlite3.Error as e:
            self.top_label.config(text=f'Database error:\n{e}')
        finally:
            if conn:
                conn.close()

    # ****************************************************************************************************

    def show_by_name(self):
        conn = None
        try:
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT CityID, CityName, Population FROM Cities ORDER BY CityName'''
            cur.execute(my_query)
            results = cur.fetchall()

            output = 'Cities Sorted By Name\n' + '-' * 40 + '\n'
            output += f"{'City':<20}{'Population':>18}\n" + '-' * 40 + '\n'
            for city_id, name, pop in results:
                output += f'{name:<20} {pop:>18,}\n'

            self.top_label.config(text=output)
        except sqlite3.Error as e:
            self.top_label.config(text=f'Database error:\n{e}')
        finally:
            if conn:
                conn.close()

    # ****************************************************************************************************

    def show_total(self):
        conn = None
        try:
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT SUM(Population) FROM Cities'''
            cur.execute(my_query)
            total = cur.fetchone()[0]

            self.top_label.config(text=f'Total Population: {total:,}')
        except sqlite3.Error as e:
            self.top_label.config(text=f'Database error:\n{e}')
        finally:
            if conn:
                conn.close()

    # ****************************************************************************************************

    def show_highest(self):
        conn = None
        try:
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT CityName, MAX(Population) FROM Cities'''
            cur.execute(my_query)
            city, pop = cur.fetchone()

            self.top_label.config(text=f'{city} has the Highest Population: {pop:,}')
        except sqlite3.Error as e:
            self.top_label.config(text=f'Database error:\n{e}')
        finally:
            if conn:
                conn.close()

#****************************************************************************************************

if __name__ == '__main__':
    app = Cities()

