// https://www.acmicpc.net/problem/2448

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

char matrix[3073][6145];
void draw(int row, int column) {
    matrix[row][column] = '*';
    matrix[row + 1][column - 1] = '*';
    matrix[row + 1][column + 1] = '*';
    for (int i = column - 2; i <= column + 2; i++) matrix[row + 2][i] = '*';
}

void solve(int size, int row, int col) {
    if (size == 0)
        draw(row, col);
    else {
        int height = 3 * pow(2, size);
        solve(size - 1, row + height / 2, col - 3 * pow(2, size - 1));
        solve(size - 1, row + height / 2, col + 3 * pow(2, size - 1));
        solve(size - 1, row, col);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k = -1;
    cin >> N;

    N /= 3;
    while (N) {
        N /= 2;
        k++;
    }

    memset(matrix, ' ', sizeof(matrix));
    int len = pow(2, k) * 6 - 1;

    solve(k, 0, len / 2);

    for (int i = 0; i < len / 2 + 1; i++) {
        for (int j = 0; j < len; j++) {
            cout << matrix[i][j];
        }
        cout << '\n';
    }
    return 0;
}

/*
  최소로 그려지는 k = 0 을 기준으로 draw 함수를 작성

  그 후 재귀적으로 어디에(꼭짓점) 그릴 것인지 전달.
  
*/