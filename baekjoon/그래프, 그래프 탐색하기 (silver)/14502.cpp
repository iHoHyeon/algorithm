// https://www.acmicpc.net/problem/14502

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int matrix[8][8];
int tempMatrix[8][8];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int res = 0;
int tempRes = 0;
vector<pair<int, int>> virus;
vector<pair<int, int>> e;

void bfs(int x, int y) {
    for (int j = 0; j < 4; j++) {
        int newX = x + dx[j];
        int newY = y + dy[j];
        if (newX >= 0 && newY >= 0 && newX < N && newY < M && tempMatrix[newX][newY] == 0) {
            tempMatrix[newX][newY] = 2;
            tempRes++;
            bfs(newX, newY);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0)
                e.push_back(make_pair(i, j));
            else if (matrix[i][j] == 2)
                virus.push_back(make_pair(i, j));
        }
    }

    for (int a = 0; a < e.size() - 2; a++) {
        for (int b = a + 1; b < e.size() - 1; b++) {
            for (int c = b + 1; c < e.size(); c++) {
                copy(&matrix[0][0], &matrix[0][0] + 64, &tempMatrix[0][0]);
                tempRes = 0;
                tempMatrix[e[a].first][e[a].second] = 1;
                tempMatrix[e[b].first][e[b].second] = 1;
                tempMatrix[e[c].first][e[c].second] = 1;
                for (int i = 0; i < virus.size(); i++) {
                    int x = virus[i].first;
                    int y = virus[i].second;
                    bfs(x, y);
                }
                res = max(res, (int)e.size() - 3 - tempRes);
            }
        }
    }
    cout << res;

    return 0;
}

/*
  8 x 8 이므로 모든 경우를 탐색해주었다.
*/