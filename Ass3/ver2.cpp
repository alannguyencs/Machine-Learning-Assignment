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
int n = 100;
double sum_x, sum_x2, x, y, rms, h, mean_x;
double X[105], Y[105], R[100000];
bool b[100000];
// create function========================================================

int sol(){
    double rms_min = 100.0;

    For(i,1,n) cin >> X[i] >> Y[i];
    For(i,1,n) {
        sum_x += X[i];
        sum_x2 += X[i] * X[i];
    }

    int M = 1000; //--> find best h
    //int L = M / 10, U = M / 100 * 13;
    int L = 1, U = M;
    For(k,L,U){
        rms = 0;
        For(id,1,n){
            x =  X[id];
            mean_x = (sum_x - x) / (n - 1);
            h = sqrt((sum_x2 - x * x) / (n - 1) - mean_x * mean_x);
            h = h * k / M;

            double A = 1.0 / (h * sqrt(2.0 * PI));


            double num = 0.0, dem = 0.0;
            For(i,1,n) if(i != id){
                double p = A * exp(-(x - X[i]) * (x - X[i]) / (2.0 * h * h));
                dem += p;
                num += p * Y[i];

//                if(abs(x - X[i]) <= h){
//                    num += Y[i];
//                    dem += 1;
//                }
            }

            if(dem <= eps){
                b[k] = true;
                rms = 100.0;
                break;
            }
            y = num / dem;
            rms += (y - Y[id]) * (y - Y[id]);
           // cout << fixed << setprecision(12) << x << " " << fixed << setprecision(12) << y << el;

        }

        rms /= n;
        rms = sqrt(rms);
        if(rms < rms_min) cout << k << " " << fixed << setprecision(9) << rms << el;
        rms_min = min(rms, rms_min);
        R[k] = rms;

      //  cout << k << " " << fixed << setprecision(9) << rms << el;
    }

    debug(rms_min);



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
