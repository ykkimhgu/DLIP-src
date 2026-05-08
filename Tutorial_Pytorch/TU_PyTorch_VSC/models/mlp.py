##########################################################
# PyTorch Tutorial:  MLP & CNN Model Architecture
#
# Author: Y.K.Kim
# mod: 2024-5-21 
#
# Description: User defined ANN & CNN Model & Modules for Training and Testing
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
        y_pred = F.log_softmax(self.linear3(x), dim=1)
        return y_pred