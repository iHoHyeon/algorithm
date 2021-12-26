// https://www.acmicpc.net/problem/1449

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    int arr[1000];

    cin >> N >> L;

    for (int i = 0; i < N; i++) cin >> arr[i];

    sort(arr, arr + N);

    int tempEnd = 0, res = 0;

    for (int i = 0; i < N; i++) {
        if (tempEnd < arr[i]) {
            tempEnd = arr[i] + L - 1;
            res++;
        }
    }

    cout << res;

    return 0;
}

/*
  테이프를 적어도 좌우 0.5만큼 붙이는게 아닌 왼쪽 1만큼이라고 생각하면 쉽게 풀이가 가능!
*/