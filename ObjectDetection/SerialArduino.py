import serial

def sendSerial(SerialData):
    COM_PORT = 'COM3'  # Change this to match your Arduino's COM port
    BAUD_RATE = 9600

# Initialize serial communication
    arduino = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)
    command = SerialData
    if command in ('A', 'B', 'C'):
        arduino.write(command.encode())  # Send the data to Arduino
    arduino.close()
