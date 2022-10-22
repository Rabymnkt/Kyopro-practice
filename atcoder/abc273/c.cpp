#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
using ll = int_least64_t;

int main(void){
    ll n;
    cin >> n;
    vector<ll> vec(n);
    unordered_map<ll, int> m;
    for (int i = 0 ; i < n ; i++){
        cin >> vec[i];
        m[vec[i]]++;
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    ll now_cnt = 0;
    ll now_pos = vec.size() - 1;
    for (int i = 0 ; i < n ; i++){
        if(now_pos < 0 || now_cnt != i){
            cout << 0 << endl;
        }else{
            cout << m[vec[now_pos]] << endl;
            now_cnt++;
            now_pos--;
        }
    }
}
