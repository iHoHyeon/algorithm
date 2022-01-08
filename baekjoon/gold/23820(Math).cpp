// https://www.acmicpc.net/problem/23820

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

bool check[2000111];
bool res[2000111];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int temp;
        cin >> temp;
        check[temp] = true;
    }

    if (!check[0]) {
        cout << 0;
        return 0;
    }
    if (!check[1]) {
        cout << 1;
        return 0;
    }

    for (long long i = 1; i <= 2000111; i++) {
        if (!check[i]) continue;

        for (long long j = 1; i * j <= 2000111; j++) {
            if (!check[j]) continue;
            res[i * j] = true;
        }
    }

    for (long long i = 2; i <= 2000111; i++) {
        if (res[i]) continue;
        cout << i;
        return 0;
    }

    return 0;
}

/*
  i * j 에서 i, j 의 범위가 2,000,000 이하

  이때, mex(S)가 소수라면 i = 1, j = 소수 꼴이 필수적이다.
  따라서 mex(S)는 2,000,000보다 큰 소수는 될 수 없고 따라서 
  mex(S)는 2,000,000보다 큰 수 중에서 가장 작은 소수보다는 작은 값이다.

  따라서 2,000,000보다 큰 가장 작은 소수를 포함할 적당한 수 (위 코드에서는 2,000,111)까지
  전부 탐색해주면 O(n logn)으로 문제를 해결할 수 있다.
*/