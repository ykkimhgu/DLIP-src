##########################################################
# PyTorch Tutorial:  ANN Model Train and Test Modules
#
# This example is creating model architecture in modules
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


##########################################################
## Part 1:  Setup
##########################################################

# Select GPU or CPU for training.
device = "cuda" if torch.cuda.is_available() else "cpu"



##########################################################
## Part 2:  Create Model Architecture   
##          (Modify Part 2 for Different Models)
##########################################################

# Model Architecture
class LeNet(nn.Module):

    def __init__(self):
        super(LeNet, self).__init__()
        self.flatten = nn.Flatten()

        # Feature Extraction 
        # Conv2d(input ch, output ch, convolution,stride=1)
        # (1,6,5) = Input ch=1, Output ch=6 with 5x5 conv kernel        
        self.conv1 = nn.Conv2d(1, 6, 5)
        self.conv2 = nn.Conv2d(6, 16, 5)
                
        # Classifier
        self.fc1 = nn.Linear(16*5*5,120) 
        self.fc2 = nn.Linear(120, 84)
        self.fc3 = nn.Linear(84, 10)

    def forward(self, x):        
        # C1
        x=self.conv1(x)
        x=F.relu(x)
        # S2 MaxPool 2x2
        x = F.max_pool2d(x, 2)                
        # C3
        x = F.relu(self.conv2(x))
        # S4 
        x = F.max_pool2d(x, 2)
        # Flatten              
        x = self.flatten(x)
        # F5
        x = F.relu(self.fc1(x))        
        # F6 
        x = F.relu(self.fc2(x))
        # OUTPUT
        logits = self.fc3(x)

        probs = F.softmax(logits,dim=1) # y_pred: 0~1 
        return probs



# Model Architecture - 2nd version 
class LeNet2(nn.Module):

    def __init__(self):
        super(LeNet, self).__init__()
        
        # Feature Extraction 
        self.conv_layers = nn.Sequential(
            # C1
            nn.Conv2d(1, 6, 5),
            nn.ReLU(),
            # S2
            nn.MaxPool2d(2, 2),
            # C3
            nn.Conv2d(6, 16, 5),
            nn.ReLU(),
            # S4
            nn.MaxPool2d(2, 2)
        )
            
        
        self.flatten = nn.Flatten()
        
        # Classifier
        self.fc_layers = nn.Sequential(
            # F5
            nn.Linear(16*5*5,120),
            nn.ReLU(),
            # F6
            nn.Linear(120, 84),
            nn.ReLU(),
            # Output
            nn.Linear(84, 10)            
        )
        

    def forward(self, x):        
        # Feature Extraction
        x=self.conv_layers(x)        
        # Flatten              
        x = self.flatten(x)
        # Classification
        logits = self.fc_layers(x)
        
        probs = F.softmax(logits,dim=1) # y_pred: 0~1 
        return probs




##########################################################
## Part 3:  Train Model
##########################################################


# Loss Function
loss_fn = nn.CrossEntropyLoss()

# Train Module
def train(dataloader, model, loss_fn=loss_fn):

    # Optimizer
    optimizer = torch.optim.SGD(model.parameters(), lr=1e-3)

    # Dataset Size
    size = len(dataloader.dataset)
    
    # Model in Training Mode
    model.train()

    running_loss=0.0

    for batch, (X, y) in enumerate(dataloader):
        X, y = X.to(device), y.to(device)

        # zero gradients for every batch
        optimizer.zero_grad()   

        # Compute prediction loss 
        pred = model(X)
        loss = loss_fn(pred, y)

        # Backpropagation and Update        
        loss.backward()
        optimizer.step()        

        # Print loss for every 100 batch in an epoch
        running_loss+=loss.item()
        if batch % 100 == 0:
            running_loss=running_loss/100
            current = batch * len(X)
            print(f"loss: {running_loss:>7f}  [{current:>5d}/{size:>5d}]")
            running_loss=0


##########################################################
## Part 4:  Test Model - Evaluation
##########################################################

def test(dataloader, model, loss_fn=loss_fn):
    # Dataset Size
    size = len(dataloader.dataset)

    # Batch Size
    num_batches = len(dataloader)
    
    # Model in Evaluation Mode
    model.eval()

    test_loss, correctN = 0, 0
    
    # Disable grad() computation to reduce memory consumption.
    with torch.no_grad():
        for X, y in dataloader:
            X, y = X.to(device), y.to(device)
            
            # Compute average prediction loss 
            pred = model(X)            
            test_loss += loss_fn(pred, y).item()

            # Predict Label
            y_pred=pred.argmax(1);
            correctN += (y_pred == y).type(torch.float).sum().item()
            
    test_loss /= num_batches
    correctN /= size
    print(f"Test Error: \n Accuracy: {(100*correctN):>0.1f}%, Avg loss: {test_loss:>8f} \n")


