// https://www.acmicpc.net/problem/1937

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int map[501][501];
int dp[501][501];
int res = 0;
int n;

int dfs(int row, int col, int lastValue) {
    if (row == 0 or col == 0 or row == n + 1 or col == n + 1 or lastValue >= map[row][col]) return 0;
    if (dp[row][col] != 0) return dp[row][col];

    return dp[row][col] = max(dfs(row + 1, col, map[row][col]),
                              max(dfs(row - 1, col, map[row][col]),
                                  max(dfs(row, col - 1, map[row][col]), dfs(row, col + 1, map[row][col])))) +
                          1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // memset(dp, 0, sizeof(dp));
            res = max(res, dfs(i, j, 0));
        }
    }

    cout << res;

    return 0;
}

/*
  처음 구현에서는 시작점을 잡고 dfs 탐색을 시작하기 전에 memset으로 
  dp 2차원 배열을 0으로 초기화하였다 -> 시간초과

  시작점과 관계없이 dp를 항상 기록하도록 (초기화하지 않도록) 수정했더니 정답.

  dp[i][j]에는 i,j에서 출발하여 가장 많이 이동할 수 있는 경우의 수가 저장되므로
  굳이 초기화할 필요가 없었다.

  처음에는 지나온 지점을 못 지나가므로 매번 초기화해주어야 한다고 생각했지만 어차피 대나무의 개수가
  증가하는 방향으로만 이동하므로 최대 경우의 수는 유일한 것이다.
*/