from math import floor   

def a():
   with open("input.txt") as f:
      result = 0
      current = 50

      for line in f:
         sign = -1 if line[0] == 'R' else 1
         current =  (current + sign * int(line[1:])) % 100
         result += int(current == 0)
      
      print("Result for a is: ", result)

""" def b():

   with open("input.txt") as f:
      result = 0
      current = 50

      for line in f:
         sign = -1 if line[0] == 'R' else 1
         
         for i in range(0, int(line[1:])):   
            current = (current + sign) % 100
            result += int(current == 0)
            
         
   print("Result for b is: ", result) """

def b():
   
   with open("input.txt") as f:
      result = 0
      current = 50

      for line in f:
         signedValue = int( line[1:] ) if line[0] == 'R' else -1 * int( line[1:] )
         floorValue = floor( ( current + signedValue ) / 100 )
         
         current =  (current + signedValue) % 100
         result +=  abs( floorValue )
   
   print("Result for b is: ", result)   


a()
b()

