from tkinter import * 
from PIL import ImageTk,Image 
import tkinter as tk
import os
import sys 

path = "C:/Users/Sharat/Desktop/Sharat Projects/Application Based/Python/General Login System/UserLoginProject/login2.png"

def command1(event):
	if username_entry.get() == "admin" and password_entry.get() == "password" or username_entry.get() == "test" and password_entry == "pass":
		window.deiconify ()
		top.destroy()

def command2():
	top.destroy()
	window.destroy()
	sys.exit()

def main_window():
	 wd = tk.Toplevel(window)

def register_window():
    wd = tk.Toplevel(window)

def password_show():
	if var1.get() == 1:
		password_entry.set(" ")
	else:
		password_entry = Entry(to,borderwidth = 2, relief = "groove")


window = tk.Tk()
top = Toplevel()
var1 = tk.IntVar()

top.geometry("550x460")
top.title("Administration Screen")
top.configure(background = "white")

image = Image.open(path)
image3 = image.resize((150, 140), Image.ANTIALIAS)

tk_image3 = ImageTk.PhotoImage(image3)
label_image3 = Label(top, image = tk_image3, bg = "White")
label_image3.grid(row = 0,column = 0, padx = (140,10), pady = (0,300))


username_lbl = Label(top,text = "Username:", font = ("Helvetica",13), bg = "white")
username_lbl.grid(row = 0, column = 0, padx = (130,0), pady = (100,180))
username_entry = Entry(top,textvariable = 10, borderwidth = 2, relief = "groove")
username_entry.grid(row = 0, column = 0, padx = (130,0), pady = (160,180), ipady = 4, ipadx = 40)


password_lbl = Label(top,text = "Password:", font = ("Helvetica",13), bg = "white")
password_lbl.grid(row = 0, column = 0, padx = (130,0), pady = (230,180))
password_entry = Entry(top, show = "*",borderwidth = 2, relief = "groove")
password_entry.grid(row = 0, column = 0, padx = (130,0), pady = (110,0), ipady = 4, ipadx = 40)

show_password_checkbox = Checkbutton(top, text = "Show Password", variable = var1, onvalue = 1,offvalue = 0, command = password_show)
show_password_checkbox.grid(row = 0, column = 1, padx = (20,10), pady = (110,0))

login_button = Button(top,text = "Login", font = ("Helvetica",10),command = command1 )
login_button.grid(row = 0, column = 0, rowspan = 100, padx = (130,10), pady = (200,10))
# entry1 = Entry(top)

register_button = Button(top,text = "Register", font=("Helvetica",10), command = register_window)
register_button.grid(row = 0, column = 0,rowspan =100, padx = (130,10), pady = (300,10)) 

button2 = Button(top,text = "Cancel",command = lambda:command2())
button2.grid(row = 0 , column = 0, rowspan = 100,padx = (130,10), pady = (400,10))

window.grid_rowconfigure(4,minsize = 100)

password_entry.bind("<Return>",command1)



#entry1.pack()

#entry2.pack()
window.title("Login Screen")
window.configure(background = "White")
window.geometry("300x260")

window.withdraw()
window.mainloop()