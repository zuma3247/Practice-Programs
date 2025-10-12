#****************************************************************************************************
#
#   Name:       Muazuddin Mohammed
#   Course:     COSC 2110 Computer Languages: Python
#   Assignment: CelsiusGUI.py
#   Due Date:   04/04/2025
#   Description:
#       This program creates a GUI for temperature conversions.
#
#****************************************************************************************************

import tkinter

#****************************************************************************************************

class CelsiusGUI:
    def __init__(self):
        self.main_window = tkinter.Tk()
        self.main_window.title("Temperature Converter")

        # Top Frame Widgets (Celsius)
        self.top_frame = tkinter.Frame(self.main_window)
        self.celsius_label = tkinter.Label(self.top_frame, text="Celsius:", width=10, anchor='w')
        self.celsius_label.pack(side='left', padx=5, pady=10)

        self.celsius_entry = tkinter.Entry(self.top_frame, width=15)
        self.celsius_entry.pack(side='left', padx=5, pady=10)

        self.convert_c_button = tkinter.Button(self.top_frame,
                                               text="Convert Celsius to Fahrenheit",
                                               command=self.convert_c_to_f)
        self.convert_c_button.pack(side='left', padx=5, pady=10)
        self.top_frame.pack()

        # Middle Frame Widgets (Fahrenheit)
        self.mid_frame = tkinter.Frame(self.main_window)
        self.fahrenheit_label = tkinter.Label(self.mid_frame, text="Fahrenheit:", width=10, anchor='w')
        self.fahrenheit_label.pack(side='left', padx=5, pady=10)

        self.fahrenheit_entry = tkinter.Entry(self.mid_frame, width=15)
        self.fahrenheit_entry.pack(side='left', padx=5, pady=10)

        self.convert_f_button = tkinter.Button(self.mid_frame,
                                               text="Convert Fahrenheit to Celsius",
                                               command=self.convert_f_to_c)
        self.convert_f_button.pack(side='left', padx=5, pady=10)
        self.mid_frame.pack()

        # Bottom Frame Widgets (Quit)
        self.bottom_frame = tkinter.Frame(self.main_window)
        self.quit_button = tkinter.Button(self.bottom_frame,
                                          text="Quit",
                                          command=self.main_window.destroy)
        self.quit_button.pack(side='bottom', padx=15, pady=10)
        self.bottom_frame.pack()

        tkinter.mainloop()

    def convert_c_to_f(self):
        celsius = float(self.celsius_entry.get())
        fahrenheit = (9.0 / 5.0) * celsius + 32
        self.fahrenheit_entry.delete(0, tkinter.END)
        self.fahrenheit_entry.insert(0, f"{fahrenheit:.2f}")

    def convert_f_to_c(self):
        fahrenheit = float(self.fahrenheit_entry.get())
        celsius = (fahrenheit - 32) * (5.0 / 9.0)
        self.celsius_entry.delete(0, tkinter.END)
        self.celsius_entry.insert(0, f"{celsius:.2f}")

#****************************************************************************************************

if __name__ == "__main__":
    app = CelsiusGUI()

#****************************************************************************************************
