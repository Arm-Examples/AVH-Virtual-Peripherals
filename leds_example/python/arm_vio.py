# Copyright (c) 2021-2022 Arm Limited. All rights reserved.

# Virtual Streaming Interface instance 0 Python script

##@addtogroup arm_vio_py
#  @{
#
##@package arm_vio
#Documentation for VIO peripherals module.
#
#More details.

import logging
from tkinter import Tk, Canvas, Frame, BOTH, ttk


## Set verbosity level
#verbosity = logging.INFO
verbosity = logging.ERROR

# [debugging] Verbosity settings
level = { 10: "DEBUG",  20: "INFO",  30: "WARNING",  40: "ERROR" }
logging.basicConfig(format='Py: VIO:  [%(levelname)s]\t%(message)s', level = verbosity)
logging.info("Verbosity level is set to " + level[verbosity])

# VIO Signals
SignalOut = 0
SignalIn  = 0

# LEDs
redMask   = 1 << 0
greenMask = 1 << 1
blueMask  = 1 << 2;


class Example(Frame):

    def __init__(self, r, g, b):
        super().__init__()
        self.master.title("Example LEDs")
        self.pack(fill=BOTH, expand=1)
        self.canvas = Canvas(self, bg='black')
        self.bRed = ttk.Button(self, text= "Red", command=self.clickRed)
        self.bGreen = ttk.Button(self, text= "Green", command=self.clickGreen)
        self.bBlue = ttk.Button(self, text= "Blue", command=self.clickBlue)
        self.canvas.pack(fill=BOTH, expand=1)


    def draw(self):
        global SignalIn, SignalOut, redMask, greenMask, blueMask

        if(SignalOut & redMask == 1):
            self.canvas.create_oval(10, 10, 80, 80, outline='white',
                    fill='red', width=3)
        else:
            self.canvas.create_oval(10, 10, 80, 80, outline='white',
                    fill='black', width=3)
        if(SignalOut & greenMask == 2):
            self.canvas.create_oval(110, 10, 180, 80, outline='white',
                    fill='green', width=3)
        else:
            self.canvas.create_oval(110, 10, 180, 80, outline='white',
                    fill='black', width=3)
        if(SignalOut & blueMask == 4):
            self.canvas.create_oval(210, 10, 280, 80, outline='white',
                    fill='blue', width=3)
        else:
            self.canvas.create_oval(210, 10, 280, 80, outline='white',
                    fill='black', width=3)

        self.bRed.place(x=3, y=90)
        self.bGreen.place(x=100, y=90)
        self.bBlue.place(x=200, y=90)

        self.canvas.pack()

    def clickRed(self):
        global SignalIn, redMask
        logging.info("Python function clickRed() called")
        if(SignalIn & redMask):
            SignalIn &= ~redMask
        else:
            SignalIn |= redMask
        self.draw()

    def clickGreen(self):
        global SignalIn, greenMask
        logging.info("Python function clickGreen() called")
        if(SignalIn & greenMask):
            SignalIn &= ~greenMask
        else:
            SignalIn |= greenMask
        self.draw()

    def clickBlue(self):
        global SignalIn, blueMask
        logging.info("Python function clickBlue() called")
        if(SignalIn & blueMask):
            SignalIn &= ~blueMask
        else:
            SignalIn |= blueMask
        self.draw()


# GUI
root = Tk()
ex = Example(0, 0, 0)


## Initialize
#  @return None
def init():
    logging.info("Python function init() called")
    root.geometry("290x130+100+100")
    root.update()


## Read Signal
#  @param mask bit mask of signals to read
#  @return signal signal value read
def rdSignal(mask):
    global SignalIn, root
    #logging.info("Python function rdSignal() not implemented")
    logging.info("Python function rdSignal() called")

    # Update GUI
    root.update()

    signal = SignalIn & mask
    logging.debug("Read signal: {}, mask: {}".format(SignalIn, mask))

    #return 0
    return signal


## Write Signal
#  @param mask bit mask of signals to write
#  @param signal signal value to write
#  @return None
def wrSignal(mask, signal):
    global SignalOut, root, ex
    logging.info("Python function wrSignal() called")

    SignalOut &= ~mask
    SignalOut |=  mask & signal

    logging.debug("Write signal: {}, mask: {}".format(signal, mask))

    # Update GUI
    ex.draw()
    root.update()

    return


## Read Value
#  @param index value index (zero based)
#  @return value value read (32-bit)
def rdValue(index):
    logging.error("Python function rdValue() not implemented")

    return -1


## Write Value
#  @param index value index (zero based)
#  @param value value to write (32-bit)
#  @return None
def wrValue(index, value):
    logging.error("Python function wrValue() not implemented")

    return


## @}

