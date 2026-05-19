#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> check;
vector<vector<bool>> searched;
queue<pair<int, int>> q;
vector<int> sum;
vector<int> num;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, l, r;

int bfs(int sx, int sy, int cnt) {
    int grid_sum = 0;
    check[sx][sy] = cnt;
    q.push({sx, sy});
    grid_sum = grid_sum + grid[sx][sy];

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && check[nx][ny] == 0) {
                int sub = abs(grid[nx][ny] - grid[x][y]);
                if (sub >= l && sub <= r) {
                    q.push({nx, ny});
                    check[nx][ny] = cnt;
                    grid_sum = grid_sum + grid[nx][ny];
                }
            }
        }
    }
    return grid_sum;
}


int main() {
    // Please write your code here.

    cin >> n >> l >> r;
    grid.resize(n, vector<int>(n));
    check.resize(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    int res = 0;
    while(1){
        bool flag = false;
        searched.assign(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        if (abs(grid[i][j] - grid[ni][nj]) >= l && abs(grid[i][j] - grid[ni][nj]) <= r) {
                            flag = true;
                            searched[i][j] = true;

                        }
                    }
                }
            }
        }
        if (flag == false) break;

        res++;
        int cnt = 1;
        check.assign(n, vector<int>(n, 0));
        sum.assign(n * n + 1, 0);
        num.assign(n * n + 1, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(check[i][j] == 0 && searched[i][j] == true){
                    sum[cnt] = bfs(i, j, cnt);
                    cnt++;
                }
            }
        }
        for (int i = 1; i < cnt; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (check[j][k] == i) num[i]++;
                }
            }
        }
        for (int i = 1; i < cnt; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (check[j][k] == i) grid[j][k] = sum[i] / num[i];
                }
            }
        }
    }
    cout << res;


    return 0;
}