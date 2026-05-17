#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

vector<int> op_count(4);
vector<int> num;
vector<int> seq;
int res_min = INT_MAX;
int res_max = INT_MIN;
int n;


int calc(){
    int res = num[0];
    for(int i = 1; i < n; i++){
        if(seq[i - 1] == 1) res = res + num[i];
        else if(seq[i - 1] == 2) res = res - num[i];
        else res = res * num[i];
    }
    return res;

}

void select(int cnt){
    if(cnt == n - 1){
        int x = calc();
        res_min = min(res_min, x);
        res_max = max(res_max, x);
    }

    for(int i = 1; i <= 3; i++){
        if(op_count[i] == 0) continue;
        op_count[i]--;
        seq[cnt] = i;
        select(cnt + 1);
        op_count[i]++;
        seq[cnt] = 0;
    }



}


int main() {
    // Please write your code here.
    cin >> n;

    num.resize(n);
    seq.resize(n - 1, 0);

    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    for(int i = 1; i <= 3; i++){
        cin >> op_count[i];
    }

    select(0);

    cout << res_min << " " << res_max;

    return 0;
}