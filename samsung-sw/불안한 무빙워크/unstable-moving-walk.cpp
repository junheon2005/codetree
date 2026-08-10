#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> movwalk;
vector<int> value;
vector<bool> charge;


bool count(){
    int cnt = 0;
    for(int i = 1; i <= 2 * n; i++){
        if(value[movwalk[i]] <= 0) cnt++;
    }
    if(cnt >= k) return false;
    else return true;
}

void rotate(){
    int temp = movwalk[2 * n];

    for(int i = 2 * n; i > 1; i--){
        movwalk[i] = movwalk[i - 1];
    }
    movwalk[1] = temp;
    if(charge[movwalk[n]] == true) charge[movwalk[n]] = false;
}

void move(){
    if(charge[movwalk[n - 1]] == true && value[movwalk[n]] > 0){
        value[movwalk[n]]--;
        charge[movwalk[n - 1]] = false;
    }
    for(int i = n - 2; i >= 1; i--){
        if(charge[movwalk[i]] == true && charge[movwalk[i + 1]] == false && value[movwalk[i + 1]] > 0){
            charge[movwalk[i + 1]] = true;
            charge[movwalk[i]] = false;
            value[movwalk[i + 1]]--;

        }
    }
}

int main() {
    cin >> n >> k;

    movwalk.resize(2 * n + 1);
    charge.resize(2 * n + 1, false);
    value.resize(2 * n + 1);

    for(int i = 1; i <= 2 * n; i++){
        movwalk[i] = i;
        cin >> value[i];
    }
    int turn = 0;

    while(count()){
        rotate();
        move();
        if(!charge[movwalk[1]] && value[movwalk[1]] > 0) {
            charge[movwalk[1]] = true;
            value[movwalk[1]]--;
        }
        turn++;
        /*
        cout << turn << "\n";
        for(int i = 1; i <= 2 * n; i++){
            cout << movwalk[i] << " ";
        }
        cout << "\n";
        for(int i = 1; i <= 2 * n; i++){
            cout << charge[movwalk[i]] << " ";
        }
        cout << "\n";
        for(int i = 1; i <= 2 * n; i++){
            cout << value[movwalk[i]] << " ";
        }
        cout << "\n";
        */
    }

    cout << turn;


    // Please write your code here.
    return 0;
}