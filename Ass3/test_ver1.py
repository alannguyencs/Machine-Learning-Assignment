#Nguyen Huu Thanh
#Kernel Density Estimator.

import numpy as np
import matplotlib.pyplot as plt
import math

learn_data = np.genfromtxt('learning_data2.txt')
test_data = np.genfromtxt('out.txt')
X = []; Y = []; 
for value in learn_data:
    X.append(value[0])
    Y.append(value[1])

plt.plot(X, Y, 'x', label = r"Learning data")

X = []; Y = []; 
for value in test_data:
    X.append(value[0])
    Y.append(value[1])

plt.plot(X, Y, '.', label = r"Estimating data")
plt.plot(label = r"RMSE = 0.02417")


plt.legend(loc = "upper right")
plt.grid(True)
plt.savefig('figure.pdf')
plt.show()

