import serial
import keyboard

# Define your serial port and baud rate
serial_port = '/dev/ttyACM0'  # Adjust this based on your system
baud_rate = 9600  # Adjust if your device uses a different baud rate

# Open the serial connection
ser = serial.Serial(serial_port, baud_rate)

try:
    while True:
        if keyboard.is_pressed('q'):
            # Send 'A' when 'q' is pressed
            ser.write(b'A\n')
finally:
    # Close the serial connection
    ser.close()
