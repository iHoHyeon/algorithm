// https://www.acmicpc.net/problem/11004

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    int* arr = new int[N];

    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    cout << arr[K - 1];

    return 0;
}

/*
  
*/