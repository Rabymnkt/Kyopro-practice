#include <iostream>
#include <vector>
#include <stack>

using namespace std;
using ll = long long;

int n;
int x, y;
char status = 0;

// メモリ使用量に注意！！！

// now : 今見ている頂点
void dfs(int now, char* flag, vector<vector<int> > &graph, vector<int> &path){
    static stack<int> stk;
    if(now == x){
        stk.push(x);
        flag[x-1] = 1;
        path.push_back(x);
    }
    if(now == y){
        status = 1;
        return;
    }
    else{
        // flag[i] == 0 のとき未訪問
        for(auto e : graph[now-1]){
            if(!flag[e-1] && !status){
                flag[e-1] = 1;
                path.push_back(e);
                dfs(e, flag, graph, path);
                if(!status){
                    flag[e-1] = 0;
                    path.pop_back();
                }
            }
        }
    }
}


int main(void){
    cin >> n >> x >> y;
    vector<int> path;
    vector<vector<int> > graph(n);
    char flag[n];
    for (int i = 0 ; i < n ; i++){
        flag[i] = 0;
    }
    for (int i = 0 ; i < n-1 ; i++){
        int s, e;
        cin >> s >> e;
        graph[s-1].push_back(e);
        graph[e-1].push_back(s);
    }
    dfs(x, flag, graph, path);
    for (int i = 0 ; i < path.size() ; i++){
        if(i) cout << ' ';
        cout << path[i];
    }
    cout << endl;
}
