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
##########################################################

# Model Architecture
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



def plotOutputImages(dataiter, model):
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

