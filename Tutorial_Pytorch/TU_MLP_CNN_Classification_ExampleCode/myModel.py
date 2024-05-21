##########################################################
# PyTorch Tutorial:  MLP & CNN Model Architecture
#
# Author: Y.K.Kim
# mod: 2024-5-21 
#
# Descr: User defined ANN & CNN Model & Modules for Training and Testing
#
# Model: MLP, LeNet
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
##  Model Architecture   
##########################################################


# Model Architecture: MLP
class MLP(nn.Module):
    def __init__(self):
        super(MLP, self).__init__()
        self.flatten = nn.Flatten()
        self.linear1 = nn.Linear(28*28, 250)
        self.linear2 = nn.Linear(250, 100)
        self.linear3 = nn.Linear(100, 10)

        
    def forward(self, x):
        x=self.flatten(x)
        x= F.relu(self.linear1(x))
        x = F.relu(self.linear2(x))
        y_pred = F.log_softmax(self.linear3(x))
        return y_pred


# Model Architecture: LeNet
class LeNet5(nn.Module):

    def __init__(self):
        super(LeNet5, self).__init__()
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



# Model Architecture: LeNet using Sequential
class LeNet5v2(nn.Module):

    def __init__(self):
        super(LeNet5v2, self).__init__()
        
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
##  Train Module
##########################################################

# Train Module
def train(dataloader, model, loss_fn,optimizer, device, print_interval=100):
    # Dataset Size
    size = len(dataloader.dataset)
    
    # Batch size
    batch_size = dataloader.batch_size
    print(f"batch size : {batch_size}")

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

        # Print avg. loss for every mini-batch in an epoch
        running_loss+=loss.item()
        if batch % print_interval == 0:
            running_loss=running_loss/print_interval            
            current = batch * batch_size
            print(f"loss: {running_loss:>7f}  [{current:>5d}/{size:>5d}]")
            running_loss=0




##########################################################
##  Test Model Module 
##########################################################

def test(dataloader, model, device):
    # Dataset Size
    size = len(dataloader.dataset)

    # Batch Size
    num_batches = len(dataloader)
    
    # Model in Evaluation Mode
    model.eval()

    #test_loss=0
    correctN = 0
    
    # Disable grad() computation to reduce memory consumption.
    with torch.no_grad():
        for X, y in dataloader:
            X, y = X.to(device), y.to(device)
            
            # Compute average prediction loss 
            pred = model(X)            
            #test_loss += loss_fn(pred, y).item()

            # Predict Label
            y_pred=pred.argmax(1);
            correctN += (y_pred == y).type(torch.float).sum().item()
            
    #test_loss /= num_batches
    correctN /= size
    #print(f"Test Error: \n Accuracy: {(100*correctN):>0.1f}%, Avg loss: {test_loss:>8f} \n")
    print(f"Test Error: \n Accuracy: {(100*correctN):>0.1f}% \n")

