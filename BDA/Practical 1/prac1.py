#Map Function

items = [6,12,18,24,30]
a = list(map(lambda x: x*2, items))
print(a)

#Filter Function

a = [2,4,6,8,10,12]
b = [3,4,7,8,12]
c = list(filter(lambda x: x in a,b))
print(c)

#Reduce Function

from functools import reduce
a = reduce((lambda x,y: x*y), [5,6,7,8,9,10,11,12])
print(a)