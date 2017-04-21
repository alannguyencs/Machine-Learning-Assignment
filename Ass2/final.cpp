/*
Assignment 2 - Nguyen Huu Thanh

Input: learning_data2.txt
Output: result.txt

Run time: ~88 seconds
*/


#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define el '\n'

const long double eps = 1e-9;

// declare ========================================================
double X[25][150], Y[150], sum_x[25], sum_yx[25], theta[25], temp[25];
double run, T, tmp, alpha, er, rms, mean_x, mean_y, Sxx, Sxy, A, B, min_rms, best_M;
int n = 100;
bool first_time;

int sol(){
    cout << "Presenting polynomial regression model by their parameters from A0 to Am" << el;
    cout << "RMS Error is picked by Leave-One-Out crossing validation" << el << el << el;
    For(i,1,n) cin >> X[1][i] >> Y[i];
    For(i,1,n){
        run = 1.0;
        For(j,0,22){
            if(j != 1) X[j][i] = run;
            sum_x[j] += run;
            sum_yx[j] += run * Y[i];
            run *= X[1][i];
        }
    }
    //===================================================
    //Linear Regression Model y = A * x + B
    mean_x = sum_x[1] / n;
    mean_y = sum_yx[0] / n;
    Sxx = sum_x[2] / n - mean_x * mean_x;
    Sxy = sum_yx[1] / n - mean_x * mean_y;
    A = Sxy / Sxx;
    B = mean_y - A * mean_x;
    cout << "Linear:" << el << fixed << setprecision(3) << A << " " << fixed << setprecision(3) << B << el;
    //Calculate RMS
    For(id,1,n){
        mean_x = (sum_x[1] - X[1][id]) / (n - 1);
        mean_y = (sum_yx[0] - Y[id]) / (n - 1);
        Sxx = (sum_x[2] - X[2][id]) / (n - 1) - mean_x * mean_x;
        Sxy = (sum_yx[1] - X[1][id] * Y[id]) / (n - 1) - mean_x * mean_y;
        A = Sxy / Sxx;
        B = mean_y - A * mean_x;
        rms += (A * X[1][id] + B - Y[id]) * (A * X[1][id] + B - Y[id]);
    }
    rms = sqrt(rms / n);
    cout << "RMS Error: " << fixed << setprecision(9) << rms << el << el;
    min_rms = rms;
    best_M = 2;
    //=======================================================
    //Polynomial Regression model using the method of Steepest Descent
    For(M,2,10){
        //Calculate parameters for model
        For(i,1,M) theta[i] = 1.0;
        alpha = 1.0; er = 1.0;
        first_time = true;
        while(er > eps){
            For(i,0,M) temp[i] = 0.0;
            For(i,0,M){
                For(k,0,M) temp[i] += theta[k] * sum_x[i+k];
                temp[i] -= sum_yx[i];
                temp[i] = theta[i] - alpha * temp[i] / n;
            }
            tmp = 0.0;
            For(i,1,n){
                run = 0.0;
                For(k,0,M) run += temp[k] * X[k][i];
                run -= Y[i];
                tmp += run * run;
            }
            tmp /= n;
            if(first_time){ //get first value of Theta
                first_time = false;
                T = tmp;
                For(i,0,M) theta[i] = temp[i];
                continue;
            }

            if(tmp > T) alpha *= 0.5; //change stepsize
            else{
                alpha *= 1.05;
                T = tmp;
                er = 0.0;
                For(i,0,M) er += (theta[i] - temp[i]) * (theta[i] - temp[i]);
                er /= (M + 1);
                For(i,0,M) theta[i] = temp[i];
            }
        }
        cout << "Degree " << M << ":" << el;
        For(i,0,M) cout << fixed << setprecision(3) << theta[i] << " ";
        cout << el;


        //Calculate RMS
        rms = 0.0;
        For(id,1,n){
            For(i,1,M) theta[i] = 1.0;
            alpha = 1.0; er = 1.0;
            first_time = true;
            while(er > eps){
                For(i,0,M) temp[i] = 0.0;
                For(i,0,M){
                    For(k,0,M) temp[i] += theta[k] * (sum_x[i + k] - X[i+k][id]);
                    temp[i] -= (sum_yx[i] - Y[id] * X[i][id]);
                    temp[i] = theta[i] - alpha * temp[i] / (n - 1);
                }
                tmp = 0.0;
                For(i,1,n) if(i != id){
                    run = 0.0;
                    For(k,0,M) run += temp[k] * X[k][i];
                    run -= Y[i];
                    tmp += run * run;
                }
                tmp /= (n - 1);
                if(first_time){ //get first value of Theta
                    first_time = false;
                    T = tmp;
                    For(i,0,M) theta[i] = temp[i];
                    continue;
                }

                if(tmp > T) alpha *= 0.5; //change stepsize
                else{
                    alpha *= 1.05;
                    T = tmp;
                    er = 0.0;
                    For(i,0,M) er += (theta[i] - temp[i]) * (theta[i] - temp[i]);
                    er /= (M + 1);
                    For(i,0,M) theta[i] = temp[i];
                }
            }
            run = 0.0;
            For(i,0,M) run += theta[i] * X[i][id];
            run -= Y[id];
            rms += run * run;
        }

        rms = sqrt(rms / n);
        cout << "RMS Error: " << fixed << setprecision(9) << rms << el << el;
        if(min_rms > rms){
            min_rms = rms;
            best_M = M;
        }
    }

    //Best polynomial model
    cout << "The best M = " << best_M << " " << "with RMS Error = " << min_rms << el;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("learning_data2.txt", "r", stdin);
	freopen("result.txt", "w", stdout);

	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

    sol();

    return 0;
}
