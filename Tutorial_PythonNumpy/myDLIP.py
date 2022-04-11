# Example 3
## Create functions that return min/max elements and their index.
## Save this in  myDLIP.py

def minVal(input):
    min = input[0]
    for i in range(0,len(input),1):   # for (i = 0; i < len(input); i++)
        if (input[i] < min):
            min = input[i]
    return min

def maxVal(input):
    max = input[0]
    for elem in input:
        if (elem > max):
            max = elem
    return max

def minIdx(input):
    min = input[0]
    for i in range(len(input)):
        if (input[i] < min):
            min = input[i]
            minIdx = i
    return minIdx, min

def maxIdx(input):
    max = input[0]
    for i, elem in enumerate(input):
        if (elem > max):
            max = elem
            maxIdx = i
    return maxIdx, max