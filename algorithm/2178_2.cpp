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

int graph[101][101];
int visited[101][101];
int N, M;
int m;
void BFS(int X, int Y) {
    queue<tuple<int, int, int>> q;
    visited[X][Y] = 1;
    m = TYPEMAX(int);
    q.push(make_tuple(X, Y, 1));
    while (!q.empty()) {
        int x, y, d;
        tie(x, y, d) = q.front();
        q.pop();

        if (x == N && y == M) {
            m = min(m, d);
        }
        if (x > 1 && graph[x-1][y] && !visited[x-1][y]) {
            visited[x-1][y] = 1;
            q.push(make_tuple(x-1, y, d+1));
        }
        if (y > 1 && graph[x][y-1] && !visited[x][y-1]) {
            visited[x][y-1] = 1;
            q.push(make_tuple(x, y-1, d+1));
        }
        if (x < N+1 && graph[x+1][y] && !visited[x+1][y]) {
            visited[x+1][y] = 1;
            q.push(make_tuple(x+1, y, d+1));
        }
        if (y < M+1 && graph[x][y+1] && !visited[x][y+1]) {
            visited[x][y+1] = 1;
            q.push(make_tuple(x, y+1, d+1));
        }    
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N >> M;

    REP(i, 1, N+1) {
        string line;
        cin >> line;
        REP(j, 1, M+1) {
            graph[i][j] = line[j-1] - '0';
        }    
    }
    
    // REP(i, 1, N+1) {
    //     REP(j, 1, M+1) {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    BFS(1, 1);
    cout << m << endl;
    
    return 0;
}