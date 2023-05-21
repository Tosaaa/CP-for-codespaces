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
    char curr;
    char next;
    REP(i, 0, 3){
        int max = 1;
        int len = 1;
        cin >> curr;
        REP(j, 0, 7) {
            cin >> next;
            if (curr == next) len++;
            if (max < len) max = len;
            if (curr != next) len = 1;
            curr = next;
        }
        cout << max << endl;
    }
    
    return 0;
}