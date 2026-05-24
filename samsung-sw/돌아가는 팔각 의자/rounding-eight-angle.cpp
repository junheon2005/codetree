#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> table[5];

int main() {
    // Please write your code here.
    int k, n, d;
    string s;

    for(int i = 1; i <= 4; i++){
        cin >> s;
        for(char c : s) table[i].push_back(c - '0');
    }
    cin >> k;
    while(k--){
        cin >> n >> d;
        int left = n - 1, right = n + 1;
        bool left_flag = false, right_flag = false;
        if (n >= 2 && table[n][6] != table[left][2]) left_flag = true;
        if (n <= 3 && table[n][2] != table[right][6]) right_flag = true;

        if (d == -1) {
            int temp = table[n][0];
            for (int i = 1; i <= 7; i++) {
                table[n][i - 1] = table[n][i];
            }
            table[n][7] = temp;
        }
        else {
            int temp = table[n][7];
            for (int i = 7; i >= 1; i--) {
                table[n][i] = table[n][i - 1];
            }
            table[n][0] = temp;
        }
        int left_d = d;
        int right_d = d;
        while (left >= 1 && left_flag) {
            left_d = -left_d;
            left_flag = false;
            if (left >= 2 && table[left - 1][2] != table[left][6]) left_flag = true;
            if (left_d == -1) {
                int temp = table[left][0];
                for (int i = 1; i <= 7; i++) {
                    table[left][i - 1] = table[left][i];
                }
                table[left][7] = temp;
            }
            else {
                int temp = table[left][7];
                for (int i = 7; i >= 1; i--) {
                    table[left][i] = table[left][i - 1];
                }
                table[left][0] = temp;
            }
            left--;
        }
        while (right <= 4 && right_flag) {
            right_d = -right_d;
            right_flag = false;
            if (right <= 3 && table[right + 1][6] != table[right][2]) right_flag = true;
            if (right_d == -1) {
                int temp = table[right][0];
                for (int i = 1; i <= 7; i++) {
                    table[right][i - 1] = table[right][i];
                }
                table[right][7] = temp;
            }
            else {
                int temp = table[right][7];
                for (int i = 7; i >= 1; i--) {
                    table[right][i] = table[right][i - 1];
                }
                table[right][0] = temp;
            }
            right++;
        }
    }
    cout << table[1][0] + 2 * table[2][0] + 4 * table[3][0] + 8 * table[4][0];

    return 0;
}