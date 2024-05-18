from ultralytics import YOLO

# Load a model
model = YOLO('best.pt')  # load a custom model

# Predict with the model
results = model('image.jpg')  # predict on an image
