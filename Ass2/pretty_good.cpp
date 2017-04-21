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
const ld eps = 1e-9;
const int dr[] = {-1, 0, +1, 0};
const int dc[] = {0, +1, 0, -1};
const int inf = (int)1e9 + 5;
const ll linf = (ll)1e16 + 5;
const ll mod = (ll)1e9 + 7;
const int MX = 1e5 + 7;
const int MAX = 15 + 7;

// paste source code========================================================


// declare ========================================================
long double X[25][150], Y[150], sum_x[25], sum_yx[25], theta[25], temp[25];
long double tmp, T, run, rms, mean_x, mean_y, Sxx, Sxy, A1, A0;
double alpha[] = {1.0, 1.2, 1.3};
int n = 100;
// create function========================================================

int sol(){
    For(i,1,n){
        X[0][i] = 1.0;
        cin >> X[1][i] >> Y[i];
    }

    For(i,1,n){
        run = 1.0;
        For(j,0,20){
            X[j][i] = run;
            sum_x[j] += run;
            sum_yx[j] += Y[i] * run;
            run *= X[1][i];
        }
    }

    //===========================================================================
    //Linear Regression
    rms = 0.0;
    For(i,1,n){
        mean_x = (sum_x[1] - X[1][i]) / (n - 1);
        mean_y = (sum_yx[0] - Y[i]) / (n - 1);
        Sxx = (sum_x[2] - X[2][i]) / (n - 1) - mean_x * mean_x;
        Sxy = (sum_yx[1] - Y[i] * X[1][i]) / (n - 1) - mean_x * mean_y;
        A1 = Sxy / Sxx;
        A0 = mean_y - A1 * mean_x;
        rms += (A1 * X[1][i] + A0 - Y[i]) * (A1 * X[1][i] + A0 - Y[i]);
    }
    rms = sqrt(rms / n);
    cout << "Linear Regression model - RMS error by Leave-one-out cross validation: " << rms << el;
    //=============================================================================
    For(M, 1, 10) For(i_alpha, 0, 2){
        rms = 0.0;
        For(id, 1, n){
            //Initialize parameter theta[i]
            For(i,0,M) theta[i] = 1.0;
            //repeat several time to get convergent value
            int loop = 10000;
            if(M == 7 && i_alpha == 2) loop = 1000000;
            while(loop --){
                For(i,0,M) temp[i] = 0.0;
                For(i,0,M){
                    For(k,0,M) temp[i] += theta[k] * (sum_x[i + k] - X[i+k][id]);
                    temp[i] -= sum_yx[i] - Y[id] * X[i][id];
                    temp[i] = theta[i] - alpha[i_alpha] * temp[i] / n;
                }
                For(i,0,M) theta[i] = temp[i];
            }

            tmp = 0.0;
            For(i,0,M) tmp += theta[i] * X[i][id];
            tmp -= Y[id];
            rms += tmp * tmp;

        }
        rms = sqrt(rms / n);
        cout << "M = " << M << " and alpha = " << alpha[i_alpha] << " then RMS error = " << fixed << setprecision(9) << rms << el;
    }






}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("learning_data2.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);

    sol();

    return 0;
}
