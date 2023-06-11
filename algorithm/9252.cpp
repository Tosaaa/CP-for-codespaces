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

string s1, s2;
int LCS[1001][1001];

void backtrace(int x, int y) {
    if (LCS[x][y] == 0) return;

    if (LCS[x-1][y] == LCS[x][y-1] && LCS[x-1][y-1] + 1 == LCS[x][y]) {
        backtrace(x-1, y-1);
        cout << s1[x-1];
    } else if (LCS[x-1][y] > LCS[x][y-1]) {
        backtrace(x-1, y);
    } else {
        backtrace(x, y-1);
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s1 >> s2;
    // 개같다.. Top down 이었는데 -1 때문에 케이스 나누기 힘들어서 bottom up으로 구현함.
    int x, y;
    REP(i, 0, s1.size()) {
        REP(j, 0, s2.size()) {
            if (s1[i] == s2[j]) LCS[i+1][j+1] = LCS[i][j] + 1;
            else LCS[i+1][j+1] = max(LCS[i][j+1], LCS[i+1][j]);
            x = i; y = j;
        }
    }
    x++; y++;

    cout << LCS[x][y] << endl;

    // REP(i, 0, s1.size()+1) {
    //     REP(j, 0, s2.size()+1) {
    //         // if (LCS[i][j] == -1) LCS[i][j] = 0;
    //         cout << LCS[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    backtrace(x, y);

    return 0;
}