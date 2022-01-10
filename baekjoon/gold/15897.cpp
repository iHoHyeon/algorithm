// https://www.acmicpc.net/problem/15897

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;

    long long res = 1;
    for (int i = 1, j; i < n; i += j) {
        j = ((n - 1) % i) / ((n - 1) / i) + 1;
        res += ((n - 1) / i + 1) * j;
    }

    cout << res;

    return 0;
}

/*
  1 ~ n 까지 i마다 (n-1)/i + 1 을 더해주면 된다.
  이때, 선형적으로 더해간다면 O(N)으로 TLE가 발생하지만

  (n-1)/i + 1이 될 수 있는 경우의 수를 j번이라고 하여 점화식을 세운다면
  시간복잡도를 줄일 수 있다.

  (n-1)/i + 1 = a 라고 할 때, 다음 경우의 수는 (n-1)/(i+j) + 1 = a - 1을 만족하는 j가 되어야한다.

  따라서 (n-1)을 i로 나누었을 때 몫을 q, 나머지를 r이라고 한다면
  (n-i)/i + 1 = a를 만족하는 i의 개수는 q / r + 1 개가 되므로 식을 세울 수 있다.
*/