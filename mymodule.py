# mymodule.py
 
class Person:
    def __init__(self, fname, lname):
        self.firstname = fname
        self.lastname = lname

    def printname(self):
        print(self.firstname, self.lastname)
 
 
person1 = {
  "name": "John",
  "age": 36,
  "country": "Norway"
}

def greeting(name):
    print("Hello, " + name)