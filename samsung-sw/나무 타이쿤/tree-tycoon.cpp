#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, d, p;
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};
vector<vector<int>> grid;
vector<pair<int, int>> fert;

void movfert(int dir, int amount) {
    vector<pair<int, int>> temp;

    for (auto [x, y] : fert) temp.push_back({(x + dx[dir] * amount - 1 + n) % n + 1, (y + dy[dir] * amount - 1 + n) % n + 1});
    fert.clear();
    for (auto [a, b] : temp) fert.push_back({a, b});
}

void addition() {
    int nx, ny;
    for (auto [x, y] : fert) {
        for (int i = 2; i <= 8; i = i + 2) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                if (grid[nx][ny] >= 1) grid[x][y]++;
            }
        }
    }
}

void findfert() {
    vector<pair<int, int>> temp;
    for (auto [a, b] : fert) temp.push_back({a, b});
    fert.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] >= 2 && find(temp.begin(), temp.end(), make_pair(i, j)) == temp.end()) {
                grid[i][j] = grid[i][j] - 2;
                fert.push_back({i, j});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    fert.push_back({n - 1, 1});
    fert.push_back({n, 1});
    fert.push_back({n - 1, 2});
    fert.push_back({n, 2});

    while (m--) {
        cin >> d >> p;
        movfert(d, p);
        for (auto [x, y] : fert) grid[x][y]++;
        addition();
        findfert();
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res = res + grid[i][j];
        }
    }
    cout << res;
    return 0;
}