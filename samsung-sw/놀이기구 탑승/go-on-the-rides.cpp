#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> close;
vector<int> seq;
int n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    // Please write your code here.
    int num, a, b, c, d;
    cin >> n;
    grid.resize(n + 1, vector<int>(n + 1, 0));
    close.resize(n * n + 1);
    seq.resize(n * n + 1);
    for(int i = 1; i <= n * n; i++){
        cin >> num >> a >> b >> c >> d;
        seq[i] = num;
        close[num].push_back(a);
        close[num].push_back(b);
        close[num].push_back(c);
        close[num].push_back(d);
    }
    
    for (int idx = 1; idx <= n * n; idx++) {
        int new_x, new_y, cur = seq[idx];
        int max_empty = 0;
        int max_clo = 0;
        bool flag = false, set = false;
        int set_i, set_j;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) continue;
                if (!set) {
                    set_i = i;
                    set_j = j;
                    set = true;
                }
                int empty = 0, clo = 0;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                        if (grid[nx][ny] == 0) empty++;
                        for (int element : close[cur]) {
                            if (grid[nx][ny] == element) clo++;
                        }
                    }
                }
                if (clo > max_clo || (clo == max_clo && empty > max_empty)) {
                    max_clo = clo;
                    max_empty = empty;
                    new_x = i;
                    new_y = j;
                    flag = true;
                }


            }
        }
        if (flag == false) grid[set_i][set_j] = cur;
        else grid[new_x][new_y] = cur;
    }

    int score = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n) {
                    for (int element : close[grid[i][j]]) {
                        if (element == grid[ni][nj]) count++;
                    }
                }
            }
            if (count == 4) score = score + 1000;
            else if (count == 3) score = score + 100;
            else if (count == 2) score = score + 10;
            else if (count == 1) score = score + 1;
        }
    }
    cout << score;
}