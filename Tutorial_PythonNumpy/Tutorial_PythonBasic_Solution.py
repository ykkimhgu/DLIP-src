
################################################################################

# Exercise 1:  Create a function that returns a list of The Fibonacci Sequence for n
## Exercise Solution 
  def fibonacci(n):
      sequence = [0,1]
      if (n < 1):
        print (" n must be greater than 1")
      if (n < 3):
          return sequence[:n]         
      else : 
          for i in range(2,n): 
            sequence.append(sequence[i-1]+sequence[i-2])
          return sequence

  # Print 
  FibList=fibonacci(10)
  FibList



################################################################################


# Exercise 2:  Find minimum and maximum values for X,Y coordinates in a List
## Exercise Solution 
  positions = [
             ('car',1,  10),
             ('ped',5,  20),
             ('cycle',6, 15)
             ]

  def minmaxPos(objects):
      minx = 1e20 # These are set to really big numbers
      miny = 1e20
      maxx = -1e20 
      maxy = -1e20
      for obj in objects:
          name,x,y = obj
          if x < minx: 
              minx = x
          elif x > maxx: 
              maxx = x
          if y < miny:
              miny = y
          elif y > maxy: 
              maxy = y
      return minx,maxx, miny, maxy

  x0,x1,y0,y1 = minmaxPos(positions)

  print('min max of X are (%d, %d)' % (x0,x1))
  print('min max of Y are (%d, %d)' % (y0,y1))




################################################################################


# Exercise 3:  Create functions that return min/max elements and their index.
## Exercise Solution 

import myDLIP as dp 

# Create a List 
a = [1,2,3,44,-1,4,22]

# Display min/max value and index

print(dp.minVal(a))
print(dp.maxVal(a))
print(dp.minIdx(a))
print(dp.maxIdx(a))