#****************************************************************************************************
#
#       Name:         Muazuddin Mohammed
#       Course:       COSC 2110 Computer Languages: Python
#       Assignment:   SuperStar.py
#       Due Date:     04/18/25
#       Description:
#               This program displays a Hollywood star with my name in the center.
#
#****************************************************************************************************

import tkinter

#****************************************************************************************************

class StarApp:
    def __init__(self):
        self.main_window = tkinter.Tk()
        self.main_window.title("Hollywood Star")

        self.canvas = tkinter.Canvas(self.main_window, width=400, height=350, bg="lightblue")
        self.canvas.pack(pady=10)

        self.draw_star()

        canvas_center_x = 400 / 2
        canvas_center_y = 350 / 2

        self.name_text = self.canvas.create_text(canvas_center_x, canvas_center_y,
                                                 text="Muaz",
                                                 fill="black",
                                                 font=("Helvetica", 20, "bold"))

        self.radio_frame = tkinter.Frame(self.main_window)
        self.radio_frame.pack(pady=10, padx=10, side="top", anchor="w")

        self.selected_color = tkinter.StringVar()
        self.selected_color.set("black")

        self.red_radio = tkinter.Radiobutton(self.radio_frame,
                                             text="Red",
                                             variable=self.selected_color,
                                             value="red",
                                             command=self.update_color)

        self.green_radio = tkinter.Radiobutton(self.radio_frame,
                                               text="Green",
                                               variable=self.selected_color,
                                               value="green",
                                               command=self.update_color)

        self.blue_radio = tkinter.Radiobutton(self.radio_frame,
                                              text="Blue",
                                              variable=self.selected_color,
                                              value="blue",
                                              command=self.update_color)

        self.red_radio.pack(side="top", anchor="w")
        self.green_radio.pack(side="top", anchor="w")
        self.blue_radio.pack(side="top", anchor="w")

        self.main_window.mainloop()

    #****************************************************************************************************

    def draw_star(self):
        star_points = [200, 40,
                       240, 140,
                       340, 140,
                       260, 210,
                       300, 320,
                       200, 250,
                       100, 320,
                       140, 210,
                       60, 140,
                       160, 140]

        self.canvas.create_polygon(star_points, outline="black", fill="white", width=2)

    #****************************************************************************************************

    def update_color(self):
        selected_color = self.selected_color.get()
        self.canvas.itemconfig(self.name_text, fill=selected_color)

#****************************************************************************************************

if __name__ == '__main__':
    app = StarApp()




  """
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

        self.populate_cities()

        self.bottom_frame = tkinter.Frame(self.main_window)

        self.asc_popn_button = tkinter.Button(self.bottom_frame,
                                              text=' 1 - Display cities sorted by population, ascending order',
                                              width=50,
                                              anchor='w',
                                              command=self.sort_by_popn)
        self.asc_popn_button.pack(padx=10, pady=2)

        self.asc_name_button = tkinter.Button(self.bottom_frame,
                                              text=' 2 - Display cities sorted by name',
                                              width=50,
                                              anchor='w',
                                              command=self.sort_by_name)
        self.asc_name_button.pack(padx=10, pady=2)

        self.total_button = tkinter.Button(self.bottom_frame,
                                           text=' 3 - Display total population of all the cities',
                                           width=50,
                                           anchor='w',
                                           command=self.total_popn)
        self.total_button.pack(padx=10, pady=2)

        self.highest_button = tkinter.Button(self.bottom_frame,
                                             text=' 4 - Display city with the highest population',
                                             width=50,
                                             anchor='w',
                                             command=self.highest_popn)
        self.highest_button.pack(padx=10, pady=2)

        self.bottom_frame.pack(pady=(0, 10))
        tkinter.mainloop()

    #****************************************************************************************************

    def populate_cities(self):
        conn = None
        display = 'Error reading database.'
        try:
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT CityID, CityName, Population FROM Cities'''
            cur.execute(my_query)
            results = cur.fetchall()
            display = 'Contents of cities.db/Cities table:\n'
            display += '-' * 40 + '\n'
            for city_id, city_name, popn in results:
                display += f'{city_id:<4}{city_name:<20} {int(popn):,}\n'
            self.top_label.config(text=display)
        except sqlite3.Error as e:
            print(f'Database error in populate_cities: {e}')
            self.top_label.config(text=f"Database error:\n{e}")
        except Exception as e:
            print(f'Other error in populate_cities: {e}')
            self.top_label.config(text=f"An error occurred:\n{e}")
        finally:
            if conn:
                conn.close()

    #****************************************************************************************************

    def sort_by_popn(self):
        conn = None
        display = 'Error reading database.'
        try:
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT CityID, CityName, Population FROM Cities
                        ORDER BY Population'''
            cur.execute(my_query)
            results = cur.fetchall()
            display = 'Cities Sorted By Population (Ascending)\n'
            display += '-' * 40 + '\n'
            display += f"{'City':<20}{'Population':>18}\n"
            display += '-' * 40 + '\n'
            for city_id, city_name, popn in results:
                display += f'{city_name:<20} {int(popn):>18,}\n'
            self.top_label.config(text=display)
        except sqlite3.Error as e:
            print(f'Database error in sort_by_popn: {e}')
            self.top_label.config(text=f"Database error:\n{e}")
        except Exception as e:
            print(f'Other error in sort_by_popn: {e}')
            self.top_label.config(text=f"An error occurred:\n{e}")
        finally:
            if conn:
                conn.close()

    #****************************************************************************************************

    def sort_by_name(self):
        """Sorts and displays cities by name, matching the example."""
        conn = None
        display = 'Error reading database.'
        try:
             # Use 'cities.db' directly
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT CityID, CityName, Population FROM Cities ORDER BY CityName'''
            cur.execute(my_query)
            results = cur.fetchall()
            display = 'Cities Sorted By Name\n'
            display += '-' * 40 + '\n'
            display += f"{'City':<20}{'Population':>18}\n"
            display += '-' * 40 + '\n'
            for city_id, city_name, popn in results:
                display += f'{city_name:<20} {int(popn):>18,}\n'
            self.top_label.config(text=display)
        except sqlite3.Error as e:
            print(f'Database error in sort_by_name: {e}')
            self.top_label.config(text=f"Database error:\n{e}")
        except Exception as e:
            print(f'Other error in sort_by_name: {e}')
            self.top_label.config(text=f"An error occurred:\n{e}")
        finally:
            if conn:
                conn.close()

    #****************************************************************************************************

    def total_popn(self):
        """Calculates and displays the total population, matching the example."""
        conn = None
        display = 'Error reading database.'
        try:
             # Use 'cities.db' directly
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT SUM(Population) FROM Cities'''
            cur.execute(my_query)
            results = cur.fetchone()
            if results and results[0] is not None:
                total = results[0]
                display = f'Total Population: {int(total):,}'
            else:
                display = 'Could not calculate total population.'
            self.top_label.config(text=display)
        except sqlite3.Error as e:
            print(f'Database error in total_popn: {e}')
            self.top_label.config(text=f"Database error:\n{e}")
        except Exception as e:
            print(f'Other error in total_popn: {e}')
            self.top_label.config(text=f"An error occurred:\n{e}")
        finally:
            if conn:
                conn.close()

    #****************************************************************************************************

    def highest_popn(self):
        """Finds and displays the city with the highest population, matching the example."""
        conn = None
        display = 'Error reading database.'
        try:
             # Use 'cities.db' directly
            conn = sqlite3.connect('cities.db')
            cur = conn.cursor()
            my_query = '''SELECT CityName, MAX(Population) FROM Cities'''
            cur.execute(my_query)
            results = cur.fetchone()
            if results and results[0] is not None and results[1] is not None:
                cityname, popn = results
                display = f'{cityname} has the Highest Population: {int(popn):,}'
            else:
                display = 'Could not determine highest population.'
            self.top_label.config(text=display)
        except sqlite3.Error as e:
            print(f'Database error in highest_popn: {e}')
            self.top_label.config(text=f"Database error:\n{e}")
        except Exception as e:
            print(f'Other error in highest_popn: {e}')
            self.top_label.config(text=f"An error occurred:\n{e}")
        finally:
            if conn:
                conn.close()

#****************************************************************************************************

if __name__ == '__main__':
    cities_app = Cities()

#****************************************************************************************************

"""
