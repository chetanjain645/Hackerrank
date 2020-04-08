import math
lis = [10, 12, 23, 23, 16, 23, 21, 16]
calculate = 0
mean = sum(lis)/len(lis)
for i in lis:
    calculate = calculate + ((i - mean)**2)/len(lis)
calculate = math.sqrt(calculate)
print(calculate)
