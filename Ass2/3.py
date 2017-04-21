import numpy as np
import matplotlib.pyplot as plt
import matplotlib as mpl
import math

learn_data = np.genfromtxt('learning_data2.txt')
n = len(learn_data)

X = [[] for i in range (21)] #define X[i][j] equal to X[j] ^ i
sum_x = [0.0 for i in range (21)] #define sum_x[i] equal to sum of X[j] ^ i
sum_yx = [0.0 for i in range (21)] #define sum_yx[i] equal to sum of Y[j] * [X[j] ^ i
sum_y = 0.0
Y = []; x = np.linspace(0, 1, 200)
for value in learn_data:
    run = 1.0    
    for i in range(21):
        X[i].append(run)
        sum_x[i] += run
        sum_yx[i] += value[1] * run
        run *= value[0]
        
    Y.append(value[1])
    sum_y += value[1]

plt.plot(X[1], Y, 'x', label = r"Learning data")
cmap = mpl.cm.autumn
#------------------------------------------------------------
#LINEAR REGRESSION
rms = 0.0

for i in range(n):
    mean_x = sum_x[1] / n
    mean_y = sum_y / n
    Sxx = sum_x[2] / n - mean_x * mean_x
    Sxy = sum_yx[1] / n - mean_x * mean_y
    A1 = Sxy / Sxx
    A0 = mean_y - A1 * mean_x
    plt.plot(x, A1 * x + A0, '-')

for i in range(n):
    mean_x = (sum_x[1] - X[1][i]) / (n - 1)
    mean_y = (sum_y - Y[i]) / (n - 1)
    Sxx = (sum_x[2] - X[2][i]) / (n - 1) - mean_x * mean_x
    Sxy = (sum_yx[1] - Y[i] * X[1][i]) / (n - 1) - mean_x * mean_y
    A1 = Sxy / Sxx
    A0 = mean_y - A1 * mean_x
    rms += (A1 * X[1][i] + A0 - Y[i]) ** 2    
   # plt.plot(x, A1 * x + A0, '-')
    
rms = math.sqrt(rms / n)
print ("Linear Regression model - RMS error by Leave-one-out cross validation:", rms, "\n\n")
    
#------------------------------------------------------------
#Polymial Regression model with degree (M) from 2 to 10
#by using the method of Steepest Descent

#complexity: M * n^2 * number of loops to converge
rms = 0.0
for M in range(5,6):
    T = 0.0
    theta = []
    for j in range(M + 1):
        theta.append(1.0)
    for j in range(n):
        tmp = 0.0
        for k in range (M + 1):
            tmp += theta[k] * X[k][j]
        tmp -= Y[j]
        T += tmp ** 2
    T /= n
    print ("T = ", T)
    

    alpha = 0.1
    loop = 0
    while(loop < 1):
        loop += 1        
        temp = []
        for j in range(M + 1):
            temp.append(0.0)
        
        for j in range(M + 1):
            for k in range(M + 1):
                temp[j] += theta[k] * sum_x[j + k]
            temp[j] -= sum_yx[j]
            temp[j] = theta[j] - alpha * 2.0 / n * temp[j]

        for j in range(M + 1):
            theta[j] = temp[j]

        T = 0.0
        for j in range(n):
            tmp = 0.0
            for k in range (M + 1):
                tmp += theta[k] * X[k][j]
            tmp -= Y[j]
            T += tmp ** 2
        T /= n
        #print (T)

    print ("M = ", M, "then T = ", T)
    XX = []; YY = []
    for i in range (100):
        xx = 1.0 * i / 100
        XX.append(xx)
        tmp = 0.0; run = 1.0
        for j in range(M + 1):
            tmp += run * theta[j]
            run *= xx
        YY.append(tmp)
        #plt.plot(XX, YY, color = cmap(M / float(4)))
       
       
    plt.plot(x, -6.681363508 * x**5 + 5.343683194 * x**4 + 8.756878820 * x**3 +
             -10.438147523 * x**2 + 3.002770830 * x + 0.309698772, '-', label = r"Degree 5 -- 0.002702910")

    plt.plot(x, -2.671249142 * x**6 + -1.605489635 * x**5 + 4.050905143 * x**4 + 6.222070392 * x**3 +
             -8.725676952 * x**2 + 2.700136053 * x + 0.317699261, '-', label = r"Degree 6 -- 0.003010626")












#------------------------------------------------------------
plt.legend(loc = "upper right")
plt.grid(True)
plt.show()  
