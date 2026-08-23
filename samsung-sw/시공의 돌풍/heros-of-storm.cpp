#include <iostream>
#include <vector>
using namespace std;


int n, m, t;
vector<vector<int>> grid;
vector<vector<int>> value;
vector<int> point;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void diffusion(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j] < 0) continue;

            for(int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 1 && nj >= 1 && ni <= n && nj <= m && grid[ni][nj] != -1) {
                    value[ni][nj] = value[ni][nj] + grid[i][j] / 5;
                    value[i][j] = value[i][j] - grid[i][j] / 5;
                }
            }
        }
    }
}

void add(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            grid[i][j] = grid[i][j] + value[i][j];
        }
    }
}

void upper_wind(){
    int x = point[0];
    int cur_x = point[0] - 1;
    int cur_y = 1;

    while (cur_x > 1) {
        grid[cur_x][1] = grid[cur_x - 1][1];
        cur_x--;
    }
    while (cur_y < m) {
        grid[1][cur_y] = grid[1][cur_y + 1];
        cur_y++;
    }
    while (cur_x < x) {
        grid[cur_x][m] = grid[cur_x + 1][m];
        cur_x++;
    }
    while (cur_y > 2) {
        grid[x][cur_y] = grid[x][cur_y - 1];
        cur_y--;
    }
    grid[x][2] = 0;
}
void lower_wind() {
    int x = point[1];
    int cur_x = point[1] + 1;
    int cur_y = 1;

    while (cur_x < n) {
        grid[cur_x][1] = grid[cur_x + 1][1];
        cur_x++;
    }
    while (cur_y < m) {
        grid[n][cur_y] = grid[n][cur_y + 1];
        cur_y++;
    }
    while (cur_x > x) {
        grid[cur_x][m] = grid[cur_x - 1][m];
        cur_x--;
    }
    while (cur_y > 2) {
        grid[x][cur_y] = grid[x][cur_y - 1];
        cur_y--;
    }
    grid[x][2] = 0;

}

int main() {

    cin >> n >> m >> t;
    grid.resize(n + 1, vector<int>(m + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
            if (grid[i][j] == -1) point.push_back(i);
        }
    }

    while(t--){
        value.assign(n + 1, vector<int>(m + 1, 0));
        diffusion();
        add();
        upper_wind();
        lower_wind();
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (grid[i][j] >= 0) res = res + grid[i][j];
        }
    }

    cout << res;
    return 0;
}