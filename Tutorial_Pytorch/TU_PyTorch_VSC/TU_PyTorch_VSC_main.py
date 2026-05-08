# """
# Image Processing with Deep Learning in Handong Global University
# 
# Author        : Y.K.Kim
# Created       : 2026-05-07
# Language      : PyTorch
#   
# Decription    : [PyTorch Tutorial] This example is creating and training a MLP model for classification
#  """

import os
import torch
import torch.nn as nn
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
from torch.utils.data import DataLoader
from torchvision import datasets
from torchvision.transforms import ToTensor

from models import MLP
from utils.train import train as training
from utils.eval import evaluate


# === Parameter === #
DATA_DIR_PATH = "data"
MODEL_DIR_PATH = "models"
MODEL_FILENAME = "MLP_MNIST_model.pth"

BATCH_SIZE = 64
TOTAL_EPOCHS = 2
LEARNING_RATE = 1e-3



##########################################################
## Part 0:  GPU setting
##########################################################

# Select GPU or CPU for training.
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
print(f"Using {device} device")



##########################################################
## Part 1:  Prepare Dataset 
##########################################################

# Download Dataset from TorchVision MNIST
# Once, downloaded locally, it does not download again.
#
#  MNIST shape:  1x28x28 

# transformation to tensor:  converts 0~255 value to 0~1 value.
data_transform = transforms.Compose([
    transforms.ToTensor()
    ])

# TRAIN DATA
training_data = datasets.MNIST(
    root=DATA_DIR_PATH,
    train=True,
    download=True,
    transform=data_transform,
    # transforms=ToTensor(),
    )

# EVAL DATA
test_data = datasets.MNIST(
    root=DATA_DIR_PATH,
    train=False,
    download=True,
    transform=data_transform,
    )

# Create DataLoader with Batch size N
# Input Dim:  [N, C, H, W]
train_dataloader = DataLoader(
    training_data, 
    batch_size=BATCH_SIZE, 
    shuffle=True,
    )

test_dataloader = DataLoader(
    test_data,
    batch_size=BATCH_SIZE,
    shuffle=False,
    )

for X, y in train_dataloader:
    print(f"Shape of X [N, C, H, W]: {X.shape}")
    print(f"Shape of y: {y.shape} {y.dtype}")
    break




##########################################################
## Part 2:  Create Model Instance 
##########################################################

# Model Class Construction
model = MLP().to(device)
print(model)



##########################################################
## Part 3:  Train Model
##########################################################

# Loss Function
loss_fn = nn.CrossEntropyLoss()

# Optimizer
optimizer = torch.optim.SGD(model.parameters(), lr=LEARNING_RATE)

def train():
    # Run Train for k epoch
    for epoch in range(TOTAL_EPOCHS):
        print(f"Epoch {epoch + 1}\n-------------------------------")
        training(train_dataloader, model, loss_fn, optimizer, device)
    print("Done!")

    # Save Train Model
    # * Need to create a new folder PATH priorly
    save_model_path = os.path.join(MODEL_DIR_PATH, MODEL_FILENAME)
    torch.save(model, save_model_path)



##########################################################
## Part 4:  Test Model - Evaluation
##########################################################

def test():
    load_model_path = os.path.join(MODEL_DIR_PATH, MODEL_FILENAME)
    model = MLP().to(device)
    model = torch.load(load_model_path, map_location=device, weights_only=False)

    evaluate(test_dataloader, model, device)



##########################################################
## Part 5:  Visualize Evaluation Results
##########################################################

def visualize():
    # # Get some random test  images // BatchSize at a time
    dataiter = iter(test_dataloader)
    images, labels = next(dataiter)
    print(images.size())


    # Evaluate mode
    # Prediction of some sample images 
    images, labels = images.to(device), labels.to(device)
    with torch.no_grad():
        pred = model(images)
        _, predicted = torch.max(pred.data, 1)


    # Plot 9 output images
    figure = plt.figure()
    num_of_images = 9
    for index in range(num_of_images):
        plt.subplot(3, 3, index+1)
        plt.axis('off')    
        plt.title("Predicted: {}".format(predicted[index].item()))
        plt.imshow(images[index].cpu().numpy().squeeze(), cmap='gray_r')
    plt.show()





##########################################################
## MAIN
##########################################################
if __name__ == "__main__":
    train()
    test()
    visualize()
