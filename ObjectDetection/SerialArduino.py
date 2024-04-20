import serial

# Define the COM port and baud rate
COM_PORT = 'COM3'  # Change this to match your Arduino's COM port
BAUD_RATE = 9600

# Initialize serial communication
arduino = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)

# Function to send data to Arduino
def send_to_arduino(data):
    arduino.write(data.encode())  # Send the data to Arduino
    print(f"Sent: {data}")

# Function to receive feedback from Arduino
def receive_from_arduino():
    feedback = arduino.readline().decode().strip()  # Read the feedback from Arduino
    print(f"Received: {feedback}")

# Main program loop
def sendSerial(SerialData):
    try:
        while True:
            command = SerialData
            if command in ('A', 'B','C'):
                send_to_arduino(command)  # Send command to Arduino
                receive_from_arduino()    # Receive feedback from Arduino
            else:
                print("Invalid command. Please enter 'A' or 'B'.")
    except KeyboardInterrupt:
        print("\nProgram terminated by user.")
    finally:
        arduino.close()  # Close serial connection when done
