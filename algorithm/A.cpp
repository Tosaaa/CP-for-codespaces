#include <bits/stdc++.h>

using namespace std;

#ifndef __TOSAAA
#define debug(...) 0
#else
#define debug(...) cout << " [-] ", _dbg(#__VA_ARGS__, __VA_ARGS__)
template<class TH> void _dbg(const char *sdbg, TH h){ cout << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
    while(*sdbg != ',') cout << *sdbg++;
    cout << '=' << (h) << ',';
    _dbg(sdbg+1, a...);
}
#endif

#define TYPEMAX(type)   numeric_limits<type>::max()
#define TYPEMIN(type)   numeric_limits<type>::min()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RREP(i, a, b) for (int i = a - 1; i >= b; i--)
#define endl '\n'

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vi b(n+1);
    REP(i, 1, n+1) {
        cin >> b[i];
    }
    vi S(n+1);
    REP(i, 1, n+1) {
        if (i == 1) {
            S[i] = b[i];
        } else if (i == 2) {
            S[i] = b[i-1] + b[i];    
        } else if (i == 3) {
            S[i] = max(S[i-2], b[i-1]) + b[i];    
        } else {
            S[i] = max(S[i-2], S[i-3] + b[i-1]) + b[i];
        }
        
    }
    cout << S[n] << endl;   


    return 0;
}