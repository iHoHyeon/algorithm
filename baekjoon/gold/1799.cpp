// https://www.acmicpc.net/problem/1799

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int board[11][11];
int tempBoard[11][11];
int SIZE;
int ans1 = 0, ans2 = 0;

bool isPossible(int r, int c) {
    int R = r - 1;
    int C = c - 1;
    while (R >= 1 and C >= 1) {
        if (tempBoard[R][C]) return false;
        R--;
        C--;
    }

    R = r - 1;
    C = c + 1;
    while (R >= 1 and C <= SIZE) {
        if (tempBoard[R][C]) return false;
        R--;
        C++;
    }

    return true;
}

void dfs(int r, int c, int cnt, bool color) {
    if (c > SIZE) {
        r++;
        c = (c % 2 == 1) ? 2 : 1;
    }
    if (r > SIZE) {
        if (color)
            ans1 = max(ans1, cnt);
        else
            ans2 = max(ans2, cnt);
        return;
    }

    if (board[r][c] and isPossible(r, c)) {
        tempBoard[r][c] = 1;
        dfs(r, c + 2, cnt + 1, color);
        tempBoard[r][c] = 0;
    }
    dfs(r, c + 2, cnt, color);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> SIZE;

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            cin >> board[i][j];
        }
    }

    dfs(1, 1, 0, true);
    dfs(1, 2, 0, false);

    cout << ans1 + ans2;

    return 0;
}

/*
*/