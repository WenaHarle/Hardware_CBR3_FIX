import cv2

# Open the video file
video_capture = cv2.VideoCapture('output1.mp4')

# Get the width and height of the video
width = int(video_capture.get(cv2.CAP_PROP_FRAME_WIDTH))
height = int(video_capture.get(cv2.CAP_PROP_FRAME_HEIGHT))

# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'XVID')
output_video = cv2.VideoWriter('output_video_gray.avi', fourcc, 30, (width, height), isColor=False)

# Process each frame of the video
while video_capture.isOpened():
    ret, frame = video_capture.read()
    if not ret:
        break

    # Convert frame to grayscale
    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    # Write the grayscale frame to the output video
    output_video.write(gray_frame)

    # Display the grayscale frame
    cv2.imshow('Grayscale Video', gray_frame)

    # Check for the 'q' key press to exit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture and writer objects
video_capture.release()
output_video.release()

# Close all OpenCV windows
cv2.destroyAllWindows()
