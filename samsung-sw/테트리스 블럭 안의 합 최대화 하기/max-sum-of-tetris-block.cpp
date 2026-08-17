#include <iostream>
#include <vector>
using namespace std;

int n, m, cur_max = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> selected;


void find_max(int count){
    if (count == 4) {
        int res = 0;
        for (auto [a, b] : selected) res = res + grid[a][b];
        cur_max = max(cur_max, res);
        return;
    }

    for (auto [x, y] : selected) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == false) {
                selected.push_back({nx, ny});
                visited[nx][ny] = true;
                find_max(count + 1);
                selected.pop_back();
                visited[nx][ny] = false;
            }
        }
    }

}


int main() {
    // Please write your code here.
    cin >> n >> m;
    grid.resize(n, vector<int>(m));
    visited.resize(n, vector<bool>(m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = true;
            selected.push_back({i, j});
            find_max(1);
            selected.pop_back();
            visited[i][j] = false;
        }
    }
    cout << cur_max;
    return 0;
}