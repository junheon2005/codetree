#include <iostream>
using namespace std;
#define int long long
signed main() {
    // Please write your code here.
    int n;
    cin >> n;
    int arr[n + 1];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ldr, mbr;

    cin >> ldr >> mbr;

    int num = 0;
    for(int i = 0; i < n; i++){
        int left = arr[i] - ldr;
        num++;
        if(left > 0){
            if(left % mbr == 0) num = num + left / mbr;
            else num = num + left / mbr + 1;    
        }
    }
    cout << num;
    return 0;
}