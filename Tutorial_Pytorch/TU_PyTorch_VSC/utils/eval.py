import torch



def evaluate(dataloader, model, device):
    model.eval()
    total_samples = len(dataloader.dataset)
    correct = 0

    with torch.no_grad():
        for images, labels in dataloader:
            images = images.to(device)
            labels = labels.to(device)

            outputs = model(images)
            predicted = outputs.argmax(dim=1)
            correct += (predicted == labels).sum().item()

    accuracy = correct / total_samples
    print(f"Test Accuracy: {accuracy * 100:.2f}%")
    return accuracy