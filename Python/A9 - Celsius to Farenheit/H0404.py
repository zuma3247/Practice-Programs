import tkinter

class Saturn:
    def __init__(self):
        self.main_window = tkinter.Tk()
        self.main_window.title('Saturn Shape')
        self.saturn = tkinter.Canvas(self.main_window, width=700, height=700)
        self.saturn.create_oval(165, 150, 340, 340, outline='orange', width=6)
        self.saturn.create_oval(100, 275, 400, 250, outline='grey', width=10)
        self.saturn.pack()
        tkinter.mainloop()

if __name__ == "__main__":
    saturn = Saturn()