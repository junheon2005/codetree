#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> movwalk;
vector<int> stabvalue;
vector<bool> stand;


bool count(){
    int cnt = 0;
    for(int i = 1; i <= 2 * n; i++){
        if(stabvalue[movwalk[i]] == 0) cnt++;
    }
    if(cnt >= k) return false;
    else return true;
}

//무빙워크 회전
void rotate(){
    int temp = movwalk[2 * n];
    for(int i = 2 * n; i > 1; i--) movwalk[i] = movwalk[i - 1];

    movwalk[1] = temp;

    //만약 n번째 칸 위라면 비움
    if(stand[movwalk[n]] == true) stand[movwalk[n]] = false;
}

//한 칸씩 이동
void move(){
    for (int i = n - 1; i >= 1; i--) {
        if (stand[movwalk[i]] && !stand[movwalk[i + 1]] && stabvalue[movwalk[i + 1]] > 0) {
            stabvalue[movwalk[i + 1]]--;
            stand[movwalk[i]] = false;
            if (i + 1 != n) stand[movwalk[i + 1]] = true;  //만약 n번째 칸 위라면 비움
        }
    }
}

int main() {
    cin >> n >> k;

    movwalk.resize(2 * n + 1);
    stand.resize(2 * n + 1, false);
    stabvalue.resize(2 * n + 1);

    for(int i = 1; i <= 2 * n; i++){
        movwalk[i] = i;
        cin >> stabvalue[i];
    }
    int turn = 0;

    while(count()){
        rotate();
        move();
        if(!stand[movwalk[1]] && stabvalue[movwalk[1]] > 0) {
            stand[movwalk[1]] = true;
            stabvalue[movwalk[1]]--;
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