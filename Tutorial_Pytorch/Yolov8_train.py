from ultralytics import YOLO

def train():
    # Load a pretrained YOLO model
    model = YOLO('yolov8n.pt')

    # Train the model using the 'coco8.yaml' dataset for 3 epochs
    results = model.train(data='maskdataset.yaml', epochs=3)
    
if __name__ == '__main__':
    train()

