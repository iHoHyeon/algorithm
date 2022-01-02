// https://www.acmicpc.net/problem/2749

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int dp[1500001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= 1500000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
    }

    long long n;
    cin >> n;

    cout << dp[n % 1500000];

    return 0;
}

/*
  피사노 주기 : https://www.acmicpc.net/problem/9471

  1,000,000으로 나눈 피보나치 수열의 반복 주기는 1,500,000 임을 피사노 주기를 통해 알 수 있다.
*/