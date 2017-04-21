from numpy import linalg as LA
from numpy import matrix
import numpy as np

inf = 10**9 * 1.0

def func(sigma, getResult):
    M = np.matrix([[0., sigma, sigma, 0., sigma], [sigma, 0., 0., sigma, 0.],
                 [sigma, 0., 0., 0., 0.], [0., sigma, 0., 0., sigma],
                 [sigma, 0., 0., sigma, 0.]])

    #===================================================
    I = np.zeros((5,5))
    for i in range(5):
        I[i][i] = 1.0

    #===================================================
    w, P = LA.eig(M)    
    print(w)    
    if not getResult:
        return
   #====================================================
    A = M - I
    inv_A = np.linalg.inv(A)
    inv_A = -inv_A
  #====================================================
    X0 = np.matrix([[1.0], [0.0], [0.0], [0.0], [0.0]])
    X_t = inv_A * X0
    print(X_t)



run = 0.0
for i in range(100):
    run += 0.01
    print (run)
    func(run, False)

func(0.33, True)



