import serial
import time

#framework for reading in a number from an arduino

#setting up ability to execute serial port
arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)



def write_to_serial(x):
    #write turn number to the serial line
    arduino.write(bytes(x,'utf-8'))
    time.sleep(0.05)   


while True:
    num = input("Enter a number: ")
    value   = write_to_serial(num)
    #wait until all clear is set
    #pyserial documentation is unclear on how this command works
    #working under the assumption it will keep reading the serial port until the finished statement is sent
    #this allows safety for 2 commands to not be sent at one 
    value = arduino.read_until("\n")
    print(value)
