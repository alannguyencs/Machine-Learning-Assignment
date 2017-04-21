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
ld mean_x, mean_y, var_x, var_y, s_x, s_y, cov, r_xy, rms, b, m;
ld x[105], y[105];
// create function========================================================


int sol(){
    //initialize array, vector, .........................


   //solve...............................................
    For(i,1,n) cin >> x[i] >> y[i];

    For(i,1,n) mean_x += x[i], mean_y += y[i];
    mean_x /= n;
    mean_y /= n;

    For(i,1,n) {
        var_x += (x[i] - mean_x) * (x[i] - mean_x);
        var_y += (y[i] - mean_y) * (y[i] - mean_y);
    }
    var_x /= n; var_y /= n;
    s_x = sqrt(var_x); s_y = sqrt(var_y);

    debug(mean_x);
    debug(mean_y);
    debug(var_x);
    debug(var_y);

    For(i,1,n) cov += (x[i] - mean_x) * (y[i] - mean_y);
    cov /= (n);
    debug(cov);

    r_xy = cov / (s_x * s_y);

    m = r_xy * s_y / s_x;
    b = mean_y - m * mean_x;

    For(i,1,n) rms += (m * x[i] + b - y[i]) * (m * x[i] + b - y[i]);
    rms /= n;
    rms = sqrt(rms);


    debug(m);
    debug(b);
    debug(rms);
    cout << el << el;
    //display result......................................
    ld Sxx = 0.0, Sxy = 0.0, mean_x2 = 0.0, Sxx2 = 0.0, Sx2x2 = 0.0, Sx2y = 0.0, A, B, C, rms_2 = 0.0;

    For(i,1,n) Sxx += x[i] * x[i];
    Sxx /= n;
    Sxx -= mean_x * mean_x;
    debug(Sxx);

    For(i,1,n) Sxy += x[i] * y[i];
    Sxy /= n;
    Sxy -= mean_x * mean_y;
    debug(Sxy);

    For(i,1,n) mean_x2 += x[i] * x[i];
    mean_x2 /= n;
    debug(mean_x2)

    For(i,1,n) Sxx2 +=  x[i] * x[i] * x[i];
    Sxx2 /= n;
    Sxx2 -= mean_x * mean_x2;
    debug(Sxx2);

    For(i,1,n) Sx2x2 += x[i] * x[i] * x[i] * x[i];
    Sx2x2 /= n;
    Sx2x2 -= mean_x2 * mean_x2;

    For(i,1,n) Sx2y += x[i] * x[i] * y[i];
    Sx2y /= n;
    Sx2y -= mean_x2 * mean_y;

    B = (Sxy * Sx2x2 - Sx2y * Sxx2) / (Sxx * Sx2x2 - Sxx2 * Sxx2);
    C = (Sx2y * Sxx - Sxy * Sxx2) / (Sxx * Sx2x2 - Sxx2 * Sxx2);
    A = mean_y - B * mean_x - C * mean_x2;
    debug(C);
    debug(B);
    debug(A);

    For(i,1,n) rms_2 += (C * x[i] * x[i] + B * x[i] + A - y[i]) * (C * x[i] * x[i] + B * x[i] + A - y[i]);
    rms_2 /= n;
    rms_2 = sqrt(rms_2);
    cout << "rms_2 " << fixed << setprecision(10) << rms_2 << el;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("learning_data.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);


    sol();

    return 0;
}
