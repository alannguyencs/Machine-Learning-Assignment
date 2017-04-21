#Nguyen Huu Thanh
#Linear Regression and Quadratic Regression Model.

import numpy as np
import numpy.polynomial.polynomial as poly
import matplotlib.pyplot as plt
import math

learn_data = np.genfromtxt('learning_data2.txt')
fit_data = np.genfromtxt('best_fit.txt')
X = []; Y = []; 
for value in learn_data:
    X.append(value[0])
    Y.append(value[1])

plt.plot(X, Y, 'x', label = r"Learning data")


coefs = poly.polyfit(X, Y, 6)
#x_new = np.linspace(X[0], X[-1], num = len(X) * 10)
x_new = np.linspace(0, 1, 300)
ffit = poly.polyval(x_new, coefs)
plt.plot(x_new, ffit, label = r"Python library")

x = np.linspace(0,1,100)
plt.plot(x, 13.0329 * x**6 + -25.6622 * x**5 + -1.0534 * x**4 + 30.4674 * x**3 + -21.3492 * x**2 + 4.66618 * x + 0.270161, '-')

X = []; Y = []; 
for value in fit_data:
    X.append(value[0])
    Y.append(value[1])

plt.plot(X, Y, '-', label = r"Gradient descent")




plt.legend(loc = "upper right")
plt.grid(True)
plt.show()
