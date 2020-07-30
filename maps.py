from tkinter import *
#import matplotlib.pyplot as plt
#from numpy import random
#import simpy

class Map:

    def map(self):

        self.root = Tk()
        self.root.config(background="grey")
        self.F = Canvas(self.root, width=1365,height=700,  bg="green")
        self.F.pack()
        #down e-w
        self.F.create_line(0,450,632,450,fill="black")
        self.F.create_line(792,450, 1365, 450, fill="black")
        #up e-w
        self.F.create_line(0, 290, 632, 290, fill="black")
        self.F.create_line(792, 290, 1365, 290, fill="black")
        #left n-s
        self.F.create_line(630, 0,630, 290, fill="black")
        self.F.create_line(630, 450, 630, 700, fill="black")
        #right n-s
        self.F.create_line(794, 0, 794, 290, fill="black")
        self.F.create_line(794, 450, 794, 700, fill="black")
        #e-w divider
        self.F.create_line(0,370,632,370,fill="white",arrow="last")
        self.F.create_line(792,370, 1365, 370, fill="white")
        #n-s divider
        self.F.create_line(712, 0,712, 290, fill="white")
        self.F.create_line(712, 450, 712, 700, fill="white")
        #dambar-E-W
        self.l=Label(self.root,text="--------->",bg="black",anchor="n",fg="white").place(x=331,y=315)
        self.l1 = Label(self.root, text="<---------", bg="black", anchor="n", fg="white").place(x=1031, y=415)
        self.F.create_rectangle(0,450,632,371, fill="black")
        self.F.create_rectangle(0,290,632,369, fill="black")
        self.F.create_rectangle(632, 290,792,450,fill="black")
        self.F.create_rectangle(792, 290,1365, 369,fill="black")
        self.F.create_rectangle(792,371,1365, 450,fill="black")
        #dambar N-S
        self.l=Label(self.root,text="--------->",bg="black",anchor="s",fg="white").place(x=1031,y=315)
        self.F.create_rectangle(630, 0,710, 290,fill="black")
        self.F.create_rectangle(714, 0,794, 290,fill="black")
        self.F.create_rectangle(630, 450, 710, 700,fill="black")
        self.F.create_rectangle(714, 450, 794, 700,fill="black")


        self.inp1=Entry(self.F,width=12)
        self.inp1.place(x=410,y=230)
        self.inp1.bind("<Return>",self.trfsig)
        #self.inp1.bind( "<Return>",self.trflogic)
        self.inp2=Entry(self.F,width=12)
        self.inp2.place(x=880,y=230)
        self.inp2.bind("<Return>", self.trfsig)

        self.inp3=Entry(self.F,width=12)
        self.inp3.place(x=930,y=490)
        self.inp3.bind("<Return>", self.trfsig)

        self.inp4=Entry(self.F,width=12)
        self.inp4.place(x=410,y=490)
        self.inp4.bind("<Return>", self.trfsig)


        self.trfsignal()
        self.root.mainloop()

    def trfsignal(self):

        #signal 1
        self.F.create_rectangle(532,220,612,255,fill="#484949")
        self.R1=self.F.create_oval(577,222,607,252,fill="red",outline="")
        #self.F.create_oval(470, 222, 500, 252, fill="dark grey",outline="")
        self.G1=self.F.create_oval(539, 222, 569, 252, fill="#AFB0B0",outline="")
        #signal 2
        self.F.create_rectangle(820,255,855,178,fill="#484949")
        self.R2=self.F.create_oval(824,222,853,252,fill="red",outline="")
        #self.F.create_oval(470, 222, 500, 252, fill="dark grey",outline="")
        self.G2=self.F.create_oval(824, 185, 853, 213, fill="#AFB0B0",outline="")
        #signal 3
        self.F.create_rectangle(820,476,900,507,fill="#484949")
        self.R3=self.F.create_oval(824,478,853,505,fill="red",outline="")
        #self.F.create_oval(470, 222, 500, 252, fill="dark grey",outline="")
        self.G3=self.F.create_oval(861, 478, 892, 505, fill="#AFB0B0",outline="")
        #signal 4
        self.F.create_rectangle(532,476,568,546,fill="#484949")
        self.R4=self.F.create_oval(536,478,564,505,fill="red",outline="")
        #self.F.create_oval(470, 222, 500, 252, fill="dark grey",outline="")
        self.G4=self.F.create_oval(536, 512, 564, 539, fill="#AFB0B0",outline="")

        #self.R1.configure(fill="grey")
        #self.G1.configure(fill="green")

    def trfsig(self,event):

        self.ip1 =float(self.inp1.get())
        self.ip2 = float(self.inp2.get())
        self.ip3 = float(self.inp3.get())
        self.ip4 = float(self.inp4.get())

        self.root.after(2000, self.trfsig1)
        #print(self.ip2+self.ip3+self.ip4)

    def trfsig1(self):

        self.ms=int(0.8*self.ip1*1000)
        print(self.ms)

        self.F.itemconfig(self.R1,fill="white")
        self.F.itemconfig(self.G1,fill="green")

        self.F.itemconfig(self.R2,fill="red")
        self.F.itemconfig(self.G2,fill="grey")

        self.F.itemconfig(self.R3,fill="red")
        self.F.itemconfig(self.G3,fill="grey")

        self.F.itemconfig(self.R4,fill="red")
        self.F.itemconfig(self.G4,fill="grey")

        self.root.after(self.ms,self.trfsig2)

    def trfsig2(self):
        self.ms =int(0.8*self.ip2*1000)
        print(self.ms)
        #self.str = self.inp.get()
        self.F.itemconfig(self.R1,fill="red")
        self.F.itemconfig(self.G1,fill="grey")

        self.F.itemconfig(self.R2,fill="white")
        self.F.itemconfig(self.G2,fill="green")

        self.F.itemconfig(self.R3, fill="red")
        self.F.itemconfig(self.G3, fill="grey")

        self.F.itemconfig(self.R4,fill="red")
        self.F.itemconfig(self.G4,fill="grey")

        self.root.after(self.ms,self.trfsig3)

    def trfsig3(self):
        self.ms =int(0.8*self.ip3*1000)
        print(self.ms)
        self.F.itemconfig(self.R1,fill="red")
        self.F.itemconfig(self.G1,fill="grey")

        self.F.itemconfig(self.R2,fill="red")
        self.F.itemconfig(self.G2,fill="grey")

        self.F.itemconfig(self.R3, fill="white")
        self.F.itemconfig(self.G3, fill="green")

        self.F.itemconfig(self.R4,fill="red")
        self.F.itemconfig(self.G4,fill="grey")

        self.root.after(self.ms, self.trfsig4)

    def trfsig4(self):
        self.ms =int(0.8*self.ip4*1000)
        print(self.ms)
        #self.str = self.inp.get()
        self.F.itemconfig(self.R1,fill="red")
        self.F.itemconfig(self.G1,fill="grey")

        self.F.itemconfig(self.R2,fill="red")
        self.F.itemconfig(self.G2,fill="grey")

        self.F.itemconfig(self.R4,fill="white")
        self.F.itemconfig(self.G4,fill="green")

        self.F.itemconfig(self.R3, fill="red")
        self.F.itemconfig(self.G3, fill="grey")

        self.root.after(self.ms,self.trfsig1)





m = Map()
m.map()
