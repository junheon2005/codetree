#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    for(int i = min(n, m); i >= 1; i--){
        if(n % i == 0 && m % i == 0){
            cout << i;
            break;
        }
    }
    return 0;
}