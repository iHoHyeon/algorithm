// https://www.acmicpc.net/problem/11652

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, m = 1, now = 1, res = 0;
    long long arr[100001];

    cin >> N;

    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);
    res = arr[0];

    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i - 1])
            now++;
        else
            now = 1;

        if (now > m) {
            m = now;
            res = arr[i];
        }
    }

    cout << res;

    return 0;
}

/*
  정렬 후 배열을 순회하며 현재 순회중인 원소 값의 개수를 기억한다.
*/