#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<string> vs;

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define RepP(i,n) for(int i = 1; i <= (n); i++) //Repeat Pascal style
#define RepdP(i, n) for(int i = n; i > 0; i--) //Repeat backward Pascal style
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define var(a, b) typeof(b) a(b)
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define last(a) (sz(a) - 1)
#define ms(a,x) memset(a, x, sizeof(a))
#define Exist(a, b) (find(all(a), (b)) != (a).end())
#define Sort(a) sort(all(a))
#define Gsort(a) sort(all(a), greater<typeof(*((a).begin()))>())
#define Unique(a) Sort(a); (a).resize(unique(all(a)) - (a).begin())
#define Enum(a) Fit(it, (a)) cout << *it << " "; cout << endl;
#define el '\n'
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define debug(x) { cout << #x << " = "; cout << (x) << endl; }

template<class F, class T> T convert(F a, int p = -1) { stringstream ss; if (p >= 0) ss << fixed << setprecision(p); ss << a; T r; ss >> r; return r; }
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> T sqr(T x) { return x * x; }
template<class T> T cube(T x) { return x * x * x; }
template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return s == 0 ? 0 : cntbit(s >> 1) + (s & 1); } //number of bit 1
template<class T> int disp(T s) { Rep(i,sz(s)) cout << s[i] << " "; cout << el; }
template<class T> int disp(T s,int n) { For(i,1,n) cout << s[i] << " "; cout << el; }
const ld PI = acos(-1.0);
const ld eps = 1e-12;
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const ll mod = (ll)1e9 + 7;
const int MX = 1e5 + 7;
const int MAX = 15 + 7;

// paste source code========================================================


// declare ========================================================
double X[25][150], Y[150], sum_x[25], sum_yx[25], theta[25], temp[25];
double run, T, tmp, alpha, er, rms, mean_x, mean_y, Sxx, Sxy, A, B, min_rms, best_M;
int n = 100;
bool first_time;
// create function========================================================

int sol(){
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
    For(M,5,5){
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

        double y, x;
        For(i,0,300){
            cout << fixed << setprecision(12) << double(i) / 300 << " ";
            x = 1.0; y = 0.0;
            For(j,0,M){
                y += x * theta[j];
                x = x * i / 300;
            }
            cout << fixed << setprecision(12) << y << el;
        }



//        //Calculate RMS
//        rms = 0.0;
//        For(id,1,n){
//            For(i,1,M) theta[i] = 1.0;
//            alpha = 1.0; er = 1.0;
//            first_time = true;
//            while(er > eps){
//                For(i,0,M) temp[i] = 0.0;
//                For(i,0,M){
//                    For(k,0,M) temp[i] += theta[k] * (sum_x[i + k] - X[i+k][id]);
//                    temp[i] -= (sum_yx[i] - Y[id] * X[i][id]);
//                    temp[i] = theta[i] - alpha * temp[i] / (n - 1);
//                }
//                tmp = 0.0;
//                For(i,1,n) if(i != id){
//                    run = 0.0;
//                    For(k,0,M) run += temp[k] * X[k][i];
//                    run -= Y[i];
//                    tmp += run * run;
//                }
//                tmp /= (n - 1);
//                if(first_time){ //get first value of Theta
//                    first_time = false;
//                    T = tmp;
//                    For(i,0,M) theta[i] = temp[i];
//                    continue;
//                }
//
//                if(tmp > T) alpha *= 0.5; //change stepsize
//                else{
//                    alpha *= 1.05;
//                    T = tmp;
//                    er = 0.0;
//                    For(i,0,M) er += (theta[i] - temp[i]) * (theta[i] - temp[i]);
//                    er /= (M + 1);
//                    For(i,0,M) theta[i] = temp[i];
//                }
//            }
//            run = 0.0;
//            For(i,0,M) run += theta[i] * X[i][id];
//            run -= Y[id];
//            rms += run * run;
//        }
//
//        rms = sqrt(rms / n);
//        cout << "RMS Error: " << fixed << setprecision(9) << rms << el << el;

    }

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("learning_data2.txt", "r", stdin);
	freopen("best_fit.txt", "w", stdout);

	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

    sol();

    return 0;
}
