// https://www.acmicpc.net/problem/10835

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int N, A[2001], B[2001];
int dp[2001][2001];

int solve(int i, int j) {
    if (i == N + 1 || j == N + 1)
        return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (A[i] > B[j])
        dp[i][j] = solve(i, j + 1) + B[j];
    else
        dp[i][j] = max(solve(i + 1, j), solve(i + 1, j + 1));

    return dp[i][j];
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(1, 1);
    return 0;
}
/*
  dp 메모이제이션 + 재귀

  문제의 조건을 그대로 구현해도 모든 경우를 확인하는 DFS 방식으로 코드를 작성할 수 있다.
  처음에 그런 식으로 작성을 하였더니 시간초과가 발생하여 dp[i][j]에 왼쪽, 오른쪽에 i, j번째 수가 보이는
  경우에 획득할 수 있는 최대의 점수를 저장해놓고 계산을 줄이는 Top-down 방식의 DP를 구현했다.

  따라서 최종적으로는 dp[1][1], 최초 상태의 최댓값을 return하는 재귀함수를 구현할 수 있다. 
*/