import numpy as np



################################################################################
# Exercise 1:  Find minimum and maximum values for X,Y coordinates in a List
## Solution

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

def minIdxVal(input):
    min = input[0]
    for i in range(len(input)):
        if (input[i] < min):
            min = input[i]
            minIdx = i
    return minIdx, min

def maxIdxVal(input):
    max = input[0]
    for i, elem in enumerate(input):
        if (elem > max):
            max = elem
            maxIdx = i
    return maxIdx, max


vecA_test = [11,12,13, 1, 2, 3, 4, 5, 6, 7]

minVal=minVal(vecA_test)
print(f"minVal={minVal}")

minIdx, minVal=minIdxVal(vecA_test)
print(f"minVal={minVal},  minIndex={minIdx}")





################################################################################
# Exercise 2: Calculate the following formulas using numpy with given Matrix X and Y
## Solution

# input/output data (w/ bias)
X = np.array([
    [0,0,1],
    [0,1,1],
    [1,1,1],
    [1,0,1]])
Y = np.array([
    [1,0],
    [0,1],
    [1,0],
    [0,1]])

W0=  np.array([[-3,  0, -1,  1],
 [ 0, -2,  0,  0],
 [-1, -5,  1, -2]])

W1=  np.array([[ 0, -3],
 [ 0, -2],
 [ 3, -1],
 [-1,  0]])


print('W0= ',W0)
print('W1= ',W1)

# Your code goes here
'''
    S0 = XW0;
    L1 = 1./(1+exp(-S0)); # elementwise division
    S1 = L1W1;
    Yh = 1./(1+exp(-S1)); # elementwise division
    dE_dS1 = -(Y-Yh).Yh.(1-Yh) # elementwise multiplication
    dE_dL1 = dE_dS1 W1' # matrix multiplication with transpose of W1
    dE_dS0 = dE_dL1.L1.*(1-L1) # elementwise multiplication
'''

S0 = np.matmul(X, W0)                                   # S0 = X*W0;
L1 = np.divide(1,(1+np.exp(-S0)))                       # L1 = 1./(1+exp(-S0));
S1 = np.matmul(L1, W1)                                  # S1 = L1*W1;
Yh = np.divide(1,(1+np.exp(-S1)))                       # Yh = 1./(1+exp(-S1));
# error backpropagation
dE_dS1 = np.multiply(np.multiply(-(Y-Yh), Yh), 1-Yh)    # dE_dS1 = -(Y-Yh).*Yh.*(1-Yh)
dE_dL1 = np.matmul(dE_dS1, np.transpose(W1))            # dE_dL1 = dE_dS1 *W1'
dE_dS0 = np.multiply(np.multiply(dE_dL1, L1), 1-L1)     # dE_dS0 = dE_dL1.*L1.*(1-L1)

print("\n",dE_dS0)