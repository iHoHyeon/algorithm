// https://www.acmicpc.net/problem/2583

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int tempSize;
bool matrix[100][100];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void bfs(int x, int y) {
    matrix[x][y] = true;
    tempSize++;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX >= 0 && newY >= 0 && newX < M && newY < N && !matrix[newX][newY]) {
            bfs(newX, newY);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    while (K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                matrix[x][y] = true;
            }
        }
    }

    vector<int> res;

    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            if (matrix[x][y]) continue;

            tempSize = 0;
            bfs(x, y);
            res.push_back(tempSize);
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (auto i = res.begin(); i != res.end(); i++) cout << *i << ' ';

    return 0;
}

/*
*/