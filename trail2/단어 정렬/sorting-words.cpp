#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> v;
string word;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word;
        v.push_back(word);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        cout << v[i] << "\n";
    }


    // Please write your code here.

    return 0;
}