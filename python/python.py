import serial
import time
import psutil
import platform
from datetime import datetime


arduino = serial.Serial(port='COM9', baudrate=9600, timeout=.1)
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    print(x)
    
while 0 == 0:
    
    svmem = psutil.virtual_memory()
    write_read(f"CPU:{psutil.cpu_percent()}% "+f"RAM:{svmem.percent}%")
    time.sleep(1.2)
          
arduino.close()
          
