// https://codeforces.com/contest/1248/problem/C

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long dp[100001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    long long res = 0;

    dp[1] = 2;
    dp[2] = 4;
    for (int i = 3; i <= 100000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    cout << (dp[n] + dp[m] - 2) % 1000000007;

    return 0;
}

/*
  한 줄만 있을 때는 피보나치 수열과 같은 점화식이 세워진다.
  ex. n = 1 이라고 할 때 경우의 수를 dp[m] 이라고 한다면
      dp[1] = 2, dp[2] = 4, dp[3] = 6 ...
      dp[m] = dp[m-2] + dp[m-1] : 왜냐하면 m의 경우의 수는 m-2에서 같은 색 cell이 연속 두개 오는 경우의 수 + m-1에서 마지막 cell과 다른 색 cell이 오는 경우의 수이기 때문

    가로축에서 한 줄을 고르거나, 세로축에서 한 줄을 고르면 정답.
    -> 왜냐하면 한 줄을 선택하면 바로 색이 반전되는 random picture를 단 하나씩 대응할 수 있고, 
    가로축과 세로축 중복은 체스판 모양뿐이므로 제외해주면 된다.

    중복 횟수가 2 이므로 정답은 dp[m] + dp[n] - 2
*/