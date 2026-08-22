#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> box;
vector<pair<pair<int, int>, pair<int, int>>> position;
vector<bool> use;
int n, m, k, h, w, c;

void gravity() {
    bool moved = true;

    while (moved) {
        moved = false;
        for (int i = 1; i <= 100; i++) {
            if (!use[i]) continue;
            int pos_left = position[i].first.second;
            int pos_right = position[i].second.second;
            int upper = position[i].first.first;
            int lower = position[i].second.first;

            if (lower == n) continue;
            int temp = lower;
            bool check = false;

            while (temp < n) {
                for (int j = pos_left; j <= pos_right; j++) {
                    if (box[temp + 1][j] != 0) {
                        check = true;
                        break;
                    }
                }
                if (check) break;
                else temp++;
            }

            if (temp == lower) continue;
            moved = true;
            int upper_x = upper + temp - lower, lower_x = temp;
            for (int p = upper; p <= lower; p++) {
                for (int q = pos_left; q <= pos_right; q++) {
                    box[p][q] = 0;
                }
            }
            for (int p = upper_x; p <= lower_x; p++) {
                for (int q = pos_left; q <= pos_right; q++) {
                    box[p][q] = i;
                }
            }
            position[i] = make_pair(make_pair(upper_x, pos_left), make_pair(lower_x, pos_right));
        }
    }
}

int left_pull(){
    int ret = -1;

    for (int i = 1; i <= 100; i++) {
        bool check = false;
        if (!use[i]) continue;
        int pos_left = position[i].first.second;
        int upper = position[i].first.first;
        int lower = position[i].second.first;

        for (int p = upper; p <= lower; p++) {
            for (int q = 1; q < pos_left; q++) {
                if (box[p][q] != 0) {
                    check = true;
                    break;
                }
            }
            if (check) break;
        }
        if (!check) {
            ret = i;
            break;
        }
    }
    if (ret == -1) return -1;

    for (int p = position[ret].first.first; p <= position[ret].second.first; p++) {
        for (int q = position[ret].first.second; q <= position[ret].second.second; q++) {
            box[p][q] = 0;
        }
    }
    use[ret] = false;
    gravity();
    return ret;
}

int right_pull(){
    int ret = -1;

    for (int i = 1; i <= 100; i++) {
        bool check = false;
        if (!use[i]) continue;
        int pos_right = position[i].second.second;
        int upper = position[i].first.first;
        int lower = position[i].second.first;

        for (int p = upper; p <= lower; p++) {
            for (int q = pos_right + 1; q <= n; q++) {
                if (box[p][q] != 0) {
                    check = true;
                    break;
                }
            }
            if (check) break;
        }
        if (!check) {
            ret = i;
            break;
        }
    }
    if (ret == -1) return -1;

    for (int p = position[ret].first.first; p <= position[ret].second.first; p++) {
        for (int q = position[ret].first.second; q <= position[ret].second.second; q++) {
            box[p][q] = 0;
        }
    }
    use[ret] = false;
    gravity();
    return ret;
}

int main() {
    cin >> n >> m;

    box.resize(n + 1, vector<int>(n + 1, 0));
    position.resize(101);
    use.resize(101, false);

    for(int i = 0; i < m; i++){
        cin >> k >> h >> w >> c;
        for(int p = 1; p < 1 + h; p++){
            for(int q = c; q < c + w; q++){
                box[p][q] = k;
            }
        }
        use[k] = true;
        position[k] = make_pair(make_pair(1, c), make_pair(h, c + w - 1));

        gravity();
    }

    bool flag = false;

    for (int i = 0; i < m; i++){
        if(!flag) {
            cout << left_pull() << "\n";
            flag = true;
        }
        else {
            cout << right_pull() << "\n";
            flag = false;
        }
    }
    return 0;
}