import torch
import torch.nn as nn
import torchvision.transforms as transforms
from torch.utils.data import DataLoader
from torchvision import datasets



# Train Module
def train(dataloader, model, loss_fn, optimizer, device, print_interval=100):
    # Dataset Size
    size = len(dataloader.dataset)

    # Batch size
    batch_size = dataloader.batch_size
    print(f"batch size : {batch_size}")

    # Model in Training Mode
    model.train()

    running_loss = 0.0

    for iter, (X, y) in enumerate(dataloader):
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
        running_loss += loss.item()
        if iter % print_interval == 0:
            running_loss = running_loss / print_interval
            current = iter * batch_size
            print(f"loss: {running_loss:>7f}  [{current:>5d}/{size:>5d}]")
            running_loss = 0