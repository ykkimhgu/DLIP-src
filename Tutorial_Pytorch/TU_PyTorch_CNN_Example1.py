
##########################################################
# PyTorch Tutorial:  Overview of ANN Model Train and Test
#
# This example is creating and testing a MLP model 
# Used MNIST
#
##########################################################


import torch 
import torch.nn as nn
import torch.nn.functional as F
import torchvision
import torchvision.transforms as transforms
from torch.utils.data import DataLoader
from torchvision import datasets
from torchvision.transforms import ToTensor
import numpy as np 
import matplotlib.pyplot as plt

import myModel # User defined modules


# Select GPU or CPU for training.
device = "cuda" if torch.cuda.is_available() else "cpu"
print(f"Using {device} device")


##########################################################
## Part 1:  Prepare Dataset
##########################################################

# Download Dataset from TorchVision MNIST
# Once, downloaded locally, it does not download again.
#
# NOTE: LeNet uses 1x32x32 input. 
# Reshape MNIST from 1x28x28 to  1x32x32

# transformation for resize
data_transform = transforms.Compose([
            transforms.Resize((32, 32)),
            transforms.ToTensor(),
])


training_data = datasets.MNIST(
    root="data",
    train=True,
    download=True,
    transform=data_transform,   #converts data size
)
test_data = datasets.MNIST(
    root="data",
    train=False,
    download=True,
    transform=data_transform,
)

# Create DataLoader with Batch size N
# MNIST and MLP Input Dim:  [N, C, H, W]=[N,1,28,28]
batch_size = 64
train_dataloader = DataLoader(training_data, batch_size=batch_size, shuffle=True)
test_dataloader = DataLoader(test_data, batch_size=batch_size, shuffle=True)

for X, y in test_dataloader:
    print(f"Shape of X [N, C, H, W]: {X.shape}")
    print(f"Shape of y: {y.shape} {y.dtype}")
    break

# Visualize Some Input Datasets




##########################################################
## Part 2:  Create Model Instance - LeNET 
##########################################################

# Model Class Construction
model = myModel.LeNet5().to(device)
print(model)



##########################################################
## Part 3:  Train Model
##########################################################

# Run Train for k epoch
epochs = 1
for t in range(epochs):
    print(f"Epoch {t+1}\n-------------------------------")
    myModel.train(train_dataloader, model)    
print("Done!")

# Save Train Model
torch.save(model,"MNIST_model.pth")




##########################################################
## Part 4:  Test Model - Evaluation
##########################################################

myModel.test(test_dataloader, model)




##########################################################
## Part 5:  Visualize Evaluation Results
##########################################################

# Select one batch of images
dataiter = iter(test_dataloader)
images, labels = next(dataiter)
print(images.size())


# Evaluate on one batch test images
with torch.no_grad():
  for X, y in dataiter:
      X, y = X.to(device), y.to(device)
      
      # Prediction Label 
      pred = model(X)
      _, predicted = torch.max(pred.data, 1)

# Plot 
figure = plt.figure()
num_of_images = 9
for index in range(num_of_images):
    plt.subplot(3, 3, index+1)
    plt.axis('off')    
    plt.title("Predicted: {}".format(predicted[index].item()))
    plt.imshow(images[index].cpu().numpy().squeeze(), cmap='gray_r')
plt.show()
