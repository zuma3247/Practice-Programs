#****************************************************************************************************
#
#       Name:         Muazuddin Mohammed
#       Course:       COSC 2110 Computer Languages: Python
#       Assignment:   ShoppingList.py
#       Due Date:     04/11/2025
#       Description:
#               This program creates a GUI for managing a grocery shopping list.
#
#****************************************************************************************************

import tkinter
from tkinter import messagebox

class ShoppingList:
    def __init__(self):
        self.main_window = tkinter.Tk()
        self.main_window.title("Shopping List")

        self.top_frame = tkinter.Frame(self.main_window)
        self.top_frame.pack(pady=10)
        self.title_label = tkinter.Label(self.top_frame, text="Grocery Shopping List",
                                         font=("Helvetica", 14, "bold"))
        self.title_label.pack()

        self.frame2 = tkinter.Frame(self.main_window)
        self.frame2.pack(padx=10, pady=5)

        self.frame2_1 = tkinter.Frame(self.frame2)
        self.frame2_1.pack()

        self.scrollbar_y = tkinter.Scrollbar(self.frame2_1, orient=tkinter.VERTICAL)
        self.listbox = tkinter.Listbox(self.frame2_1, width=30, height=10, yscrollcommand=self.scrollbar_y.set)
        self.listbox.pack(side='left')
        self.scrollbar_y.config(command=self.listbox.yview)
        self.scrollbar_y.pack(side='right', fill='y')

        self.frame2_2 = tkinter.Frame(self.frame2)
        self.frame2_2.pack(fill='x')

        self.scrollbar_x = tkinter.Scrollbar(self.frame2_2, orient=tkinter.HORIZONTAL, command=self.listbox.xview)
        self.listbox.config(xscrollcommand=self.scrollbar_x.set)
        self.scrollbar_x.pack(fill='x')

        self.frame3 = tkinter.Frame(self.main_window)
        self.frame3.pack(pady=10)
        self.entry = tkinter.Entry(self.frame3, width=20)
        self.entry.pack(side='left', padx=5)
        self.add_button = tkinter.Button(self.frame3, text="Add", command=self.add_item)
        self.add_button.pack(side='left', padx=5)

        self.bottom_frame = tkinter.Frame(self.main_window)
        self.bottom_frame.pack(pady=10)
        self.delete_button = tkinter.Button(self.bottom_frame, text="Delete Selected", command=self.delete_selected)
        self.delete_button.pack(side='left', padx=5)
        self.clear_button = tkinter.Button(self.bottom_frame, text="Clear the list", command=self.clear_list)
        self.clear_button.pack(side='left', padx=5)
        self.quit_button = tkinter.Button(self.bottom_frame, text="Quit", command=self.main_window.destroy)
        self.quit_button.pack(side='left', padx=5)

        self.main_window.mainloop()

    #****************************************************************************************************

    def add_item(self):
        item = self.entry.get()
        if item.strip() == "":
            messagebox.showerror("Input Error", "Please enter an item to add.")
        else:
            self.listbox.insert(tkinter.END, item)
            self.entry.delete(0, 'end')

    #****************************************************************************************************

    def delete_selected(self):
        try:
            index = self.listbox.curselection()[0]
            self.listbox.delete(index)
        except IndexError:
            messagebox.showerror("Selection Error", "Please select an item to delete.")

    #****************************************************************************************************

    def clear_list(self):
        if self.listbox.size() == 0:
            messagebox.showerror("List Error", "The list is already empty.")
        else:
            self.listbox.delete(0, tkinter.END)

#****************************************************************************************************

if __name__ == '__main__':
    app = ShoppingList()

