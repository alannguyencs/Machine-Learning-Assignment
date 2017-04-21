import numpy as np
import matplotlib.pyplot as plt
import math

learn_data = np.genfromtxt('learning_data2.txt')

X = []; Y = []; x = np.linspace(0, 1, 200)
for value in learn_data:
    X.append(value[0])
    Y.append(value[1])

plt.plot(X, Y, 'x', label = r"Learning data")

#Statistic calculation
mean_x = 0.0; mean_y = 0.0; mean_x2 = 0.0;
Sxx = 0.0; Sxy = 0.0; Sxx2 = 0.0; Sx2x2 = 0.0; Sx2y = 0.0
for value in learn_data:
    mean_x += value[0]
    mean_y += value[1]
    mean_x2 += value[0] * value[0]
    Sxx    += value[0] * value[0]
    Sxy    += value[0] * value[1]
    Sxx2   +=  value[0] * value[0] * value[0]
    Sx2x2   +=  value[0] * value[0] * value[0] * value[0]
    Sx2y    += value[0] * value[0] * value[1]
    
mean_x /= len(learn_data)
mean_y /= len(learn_data)
mean_x2 /= len(learn_data)
Sxx = Sxx / len(learn_data) - mean_x * mean_x
Sxy = Sxy / len(learn_data) - mean_x * mean_y
Sxx2 = Sxx2 / len(learn_data) - mean_x * mean_x2
Sx2x2 = Sx2x2 / len(learn_data) - mean_x2 * mean_x2
Sx2y = Sx2y / len(learn_data) - mean_x2 * mean_y


#Linear Regression y = Ax + B
print ("Using Linear Regression model:")
A = Sxy / Sxx
B = mean_y - A * mean_x
rms = 0.0
print ("y = ", A, "x + ", B)
for value in learn_data:
    rms += (A * value[0] + B - value[1]) * (A * value[0] + B - value[1])

rms = math.sqrt(rms / len(learn_data))

print ("RMS value for test_data:", rms, "\n \n")
plt.plot(x, A * x + B, '-', label = r"Linear Regression model")


plt.legend(loc = "upper right")
plt.grid(True)
plt.show()
