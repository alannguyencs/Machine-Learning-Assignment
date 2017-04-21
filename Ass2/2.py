import numpy as np
import matplotlib.pyplot as plt
import math

learn_data = np.genfromtxt('learning_data2.txt')

X = []; Y = []; x = np.linspace(0, 1, 200)
for value in learn_data:
    X.append(value[0])
    Y.append(value[1])

plt.plot(X, Y, 'x', label = r"Learning data")




n = len(learn_data)
theta_0 = 1.0; theta_1 = 1.0; theta = 0.0
for value in learn_data:
        theta += (theta_1 * value[0] + theta_0 - value[1]) ** 2
theta /= n
print ("theta = ", theta)

delta = 1000.0; alpha = 0.1; cnt = 0
##while abs(delta) > 0.000001:
while cnt < 300:
    temp_0 = 0.0; temp_1 = 0.0; temp = 0.0
    for value in learn_data:
        temp_0 += theta_0 + theta_1 * value[0] - value[1]
        temp_1 += (theta_0 + theta_1 * value[0] - value[1]) * value[0]
    temp_0 = theta_0 - 2.0 * alpha / n * temp_0
    temp_1 = theta_1 - 2.0 * alpha / n * temp_1

##    print ("temp_0 = ", temp_0)
##    print ("temp_1 = ", temp_1)

    for value in learn_data:
        temp += (temp_0 + temp_1 * value[0] - value[1]) ** 2
    temp /= n

    theta_0 = temp_0
    theta_1 = temp_1
    delta = theta - temp
    theta = temp
    cnt += 1
   # print (cnt, theta, delta)
##    if cnt % 20 == 0:
##        plt.plot(x, theta_1 * x + theta_0, '-')

print ("theta: ", theta_1, theta_0, theta)
print (cnt)
plt.plot(x, theta_1 * x + theta_0, '-')
plt.legend(loc = "upper right")
plt.grid(True)
plt.show()    
