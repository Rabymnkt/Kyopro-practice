#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;
using ll = int_least64_t;
using pii = pair<int, int>;

int main(void){
    ll n, m;
    cin >> n >> m;

    vector<pii> pattern;
    int ans[n][n];
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            ans[i][j] = -1;
        }
    }

    // mの有効性判定
    for (int i = 0 ; i*i <= m ; i++){
        for (int j = 0 ; j*j <= m-i*i ; j++){
            if(i*i + j*j == m){
                pattern.emplace_back(i, j);
            }
        }
    }
    queue<pii> next;
    next.emplace(0, 0);

    vector<pii> direc;
    direc.emplace_back(1, 1);
    direc.emplace_back(1, -1);
    direc.emplace_back(-1, 1);
    direc.emplace_back(-1, -1);

    ans[0][0] = 0;
    while(!next.empty()){
        pii tmp = next.front();
        next.pop();
        for(auto d : direc){
            for(auto p : pattern){
                int next_x = tmp.first + d.first * p.first;
                int next_y = tmp.second + d.second * p.second;
                if(0 <= next_x && next_x < n 
                && 0 <= next_y && next_y < n
                && ans[next_x][next_y] == -1)
                {
                    ans[next_x][next_y] = ans[tmp.first][tmp.second] + 1;
                    next.emplace(next_x, next_y);
                }
            }
        }
    }
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if(j != 0) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
}
