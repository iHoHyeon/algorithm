// https://www.acmicpc.net/problem/11403

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int N;
int matrix[100][100];
bool visit[100][100];

void dfs(int i, int j) {
    visit[i][j] = true;
    for (int k = 0; k < N; k++) {
        if (!visit[i][k] && matrix[j][k]) {
            matrix[i][k] = 1;
            dfs(i, k);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(matrix, 0, sizeof(matrix));
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j] && matrix[i][j]) {
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/*
*/