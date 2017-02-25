import serial
import time
import sys 
import os

kolor = sys.argv[1]
arduino = serial.Serial('COM6', 9600, timeout=.1)

time.sleep(2)

arduino.write(kolor) 

