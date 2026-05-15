#include <iostream>
#include <vector>
using namespace std;


vector<int> t;
vector<int> p;
vector<bool> used;
vector<bool> timed;
int n;
int res = 0;

void get(int cnt, int price, int idx){
    if(idx == n){
        res = max(res, price);
        return;
    }
    if(timed[idx] == true){
        get(cnt, price, idx + 1);
    }
    else{
        get(cnt, price, idx + 1);
        if(idx + t[idx] - 1 < n){
        for(int i = 0; i < t[idx]; i++){
            timed[idx + i] = true;
        }
        get(cnt + 1, price + p[idx], idx + 1);
        for(int i = 0; i < t[idx]; i++){
            timed[idx + i] = false;
        }
        }
    }

}

int main() {
    // Please write your code here.
    cin >> n;
    t.resize(n + 1);
    p.resize(n + 1);
    used.resize(n + 1);
    timed.resize(n + 1);
    for(int i = 0; i < n; i++){
        cin >> t[i] >> p[i];
    }
    get(0, 0, 0);
    cout << res;

    return 0;
}
