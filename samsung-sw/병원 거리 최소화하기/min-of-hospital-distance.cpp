#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n, m;
vector<vector<int>> grid;
vector<pair<int, int>> place;
vector<pair<int, int>> selected;
int res = INT_MAX;

int calc(){
    int res_dist = 0;


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(grid[i][j] == 1){
                int dist = 100;
                for(auto [x, y] : selected){
                    dist = min(dist, abs(x - i) + abs(y - j));
                }
                res_dist = res_dist + dist;

            }

        }
    }
    return res_dist;

}



void select(int cnt, int idx){
    if(cnt == m){
        res = min(res, calc());
        return;
    }

    if(m - cnt > place.size() - idx) return;

    if(idx == place.size()) return;
    


    for(int i = idx; i < place.size(); i++){
        select(cnt, i + 1);
        selected.push_back(place[i]);
        select(cnt + 1, i + 1);
        selected.pop_back();
    }

}

int main() {
    // Please write your code here.

    cin >> n >> m;
    grid.resize(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2) place.push_back({i, j});
        }
    }

    select(0, 0);

    cout << res;



    
    return 0;
}