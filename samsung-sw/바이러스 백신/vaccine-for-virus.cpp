#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int res = 1000;
queue<pair<int, int>> q;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<vector<int>> turn;
vector<pair<int, int>> hospital;
vector<bool> used;
vector<pair<int, int>> selected;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ret_max(){
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0 && !visited[i][j]) return -1;
            if (turn[i][j] > ret && grid[i][j] == 0) ret = turn[i][j];
        }
    }
    return ret;
}

int bfs(){
    visited.assign(n, vector<bool>(n, false));
    turn.assign(n, vector<int>(n, 0));

    for (auto [a, b] : selected) {
        q.push({a, b});
        visited[a][b] = true;
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                turn[nx][ny] = turn[x][y] + 1;
                q.push({nx, ny});
            }
        }

    }
    return ret_max();

}

void select(int idx, int num){
    if(num == m){
        int a = bfs();
        if (a != -1) res = min(res, a);
        return;
    }

    for (int i = idx; i < hospital.size(); i++) {
        if ((int)hospital.size() - idx < m - num) return;

        selected.push_back(hospital[i]);
        select(i + 1, num + 1);
        selected.pop_back();
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<int>(n));
    visited.resize(n, vector<bool>(n));
    turn.resize(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 2) hospital.push_back(make_pair(i, j));
        }
    }
    used.resize(hospital.size(), false);
    select(0, 0);

    if (res == 1000) cout << -1;
    else cout << res;
    return 0;
}