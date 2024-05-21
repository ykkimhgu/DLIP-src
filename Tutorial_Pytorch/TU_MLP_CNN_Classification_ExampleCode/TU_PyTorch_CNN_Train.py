##########################################################
# PyTorch Tutorial:  Classification CNN Model for Training
#
# Author: Y.K.Kim
# mod: 2024-5-21 
#
# Descr: This example is creating and training a CNN model for classification
#
# Model: LeNet
# Dataset: MNIST
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

# User defined Model
import myModel  as myModel 

# Model weight directory
ModelPATH='./weights/'

##########################################################
## Part 0:  GPU setting
##########################################################

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

# TRAIN DATA
training_data = datasets.MNIST(
    root="data",
    train=True,
    download=True,
    transform=data_transform,   #converts data size
)


# Create DataLoader with Batch size N
# Input Dim:  [N, C, H, W]
batch_size = 64
train_dataloader = DataLoader(training_data, batch_size=batch_size, shuffle=True)


for X, y in train_dataloader:
    print(f"Shape of X [N, C, H, W]: {X.shape}")
    print(f"Shape of y: {y.shape} {y.dtype}")
    break




##########################################################
## Part 2:  Create Model Instance - CNN
##########################################################

# Model Class Construction
model = myModel.LeNet5().to(device)
print(model)



##########################################################
## Part 3:  Train Model
##########################################################

# Loss Function
loss_fn = nn.CrossEntropyLoss()

# Optimizer
optimizer = torch.optim.SGD(model.parameters(), lr=1e-3)

# Run Train for k epoch
epochs = 1
for t in range(epochs):
    print(f"Epoch {t+1}\n-------------------------------")
    myModel.train(train_dataloader, model,loss_fn, optimizer,device)    
print("Done!")


# Save Train Model
# * Need to create a new folder PATH priorly
torch.save(model,ModelPATH+'LeNet_MNIST_model.pth')




# Evaluate the trained model in **Eval.py