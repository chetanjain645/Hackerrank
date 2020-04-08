import math

mean = 12
stdev = 5
x = 2.5


pdf_value = (1/(stdev*math.sqrt(2*math.pi)))*math.e**(-0.5*((x-mean)/stdev)**2)
print(pdf_value)
