import cv2
import numpy as np

def segment(frame):
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # Definisikan rentang warna hijau
    lower_green = np.array([30, 40, 40])
    upper_green = np.array([100, 255, 255])

    # Buat mask untuk warna hijau
    mask_green = cv2.inRange(hsv, lower_green, upper_green)

    # Gabungkan frame asli dengan mask untuk mendapatkan area warna hijau saja
    result = cv2.bitwise_and(frame, frame, mask=mask_green)
    return result
