// https://www.acmicpc.net/problem/1041

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, res = 0, arr[6];

    cin >> N;

    for (int i = 0; i < 6; i++) cin >> arr[i];

    if (N == 1) {
        sort(arr, arr + 6, greater<int>());
        for (long long i = 1; i < 6; i++) res += arr[i];
        cout << res;
        return 0;
    }

    int mins[3];

    mins[0] = min(arr[0], arr[5]);
    mins[1] = min(arr[1], arr[4]);
    mins[2] = min(arr[2], arr[3]);

    sort(mins, mins + 3);

    res += mins[0] * ((N - 2) * (N - 2) * 5 + (N - 2) * 4);
    res += (mins[0] + mins[1]) * ((N - 2) * 8 + 4);
    res += (mins[0] + mins[1] + mins[2]) * 4;

    cout << res;
    return 0;
}

/*
  주사위의 마주보면 두 변은 동시에 보여지지 않음을 이용하였다
*/