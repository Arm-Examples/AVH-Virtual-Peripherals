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
from tkinter import Tk, Canvas, Frame, BOTH


## Set verbosity level
#verbosity = logging.DEBUG
verbosity = logging.ERROR

# [debugging] Verbosity settings
level = { 10: "DEBUG",  20: "INFO",  30: "WARNING",  40: "ERROR" }
logging.basicConfig(format='Py: VIO:  [%(levelname)s]\t%(message)s', level = verbosity)
logging.info("Verbosity level is set to " + level[verbosity])


class Example(Frame):

    def __init__(self, r, g, b):
        super().__init__()
        self.red=r
        self.green=g
        self.blue=b
        self.master.title("Example LEDs")
        self.pack(fill=BOTH, expand=1)
        self.canvas = Canvas(self, bg='black')
        self.canvas.pack(fill=BOTH, expand=1)

    def draw(self):
        if(self.red == 1):
            self.canvas.create_oval(10, 10, 80, 80, outline='white',
                    fill='red', width=3)
        else:
            self.canvas.create_oval(10, 10, 80, 80, outline='white',
                    fill='black', width=3)
        if(self.green == 1):
            self.canvas.create_oval(110, 10, 180, 80, outline='white',
                    fill='green', width=3)
        else:
            self.canvas.create_oval(110, 10, 180, 80, outline='white',
                    fill='black', width=3)
        if(self.blue == 1):
            self.canvas.create_oval(210, 10, 280, 80, outline='white',
                    fill='blue', width=3)
        else:
            self.canvas.create_oval(210, 10, 280, 80, outline='white',
                    fill='black', width=3)

        self.canvas.pack(fill=BOTH, expand=1)

# GUI
root = Tk()
ex = Example(0, 0, 0)

## Initialize
#  @return None
def init():
    logging.info("Python function init() called")
    ex.draw()
    root.geometry("290x100+100+100")
    root.update_idletasks()


## Read Signal
#  @param mask bit mask of signals to read
#  @return signal signal value read
def rdSignal(mask):
    logging.error("Python function rdSignal() not implemented")

    return -1


## Write Signal
#  @param mask bit mask of signals to write
#  @param signal signal value to write
#  @return None
def wrSignal(mask, signal):
    logging.error("Python function wrSignal() not implemented")

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
    global root
    global ex
    logging.info("Python function wrValue() called")

    if(index == 0):
      ex.red = value
      logging.debug("Turning red LED to {}".format(value))
    elif(index == 1):
      ex.green = value
      logging.debug("Turning green LED to {}".format(value))
    elif(index == 2):
      ex.blue = value
      logging.debug("Turning blue LED to {}".format(value))
    else:
      logging.debug("No LED connected at index {}".format(index, value))

    ex.draw()
    root.update_idletasks()
    
    return


## @}

