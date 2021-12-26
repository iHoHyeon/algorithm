// https://www.acmicpc.net/problem/15688

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);  

    for (int i = 0; i < n; i++) cout << arr[i] << '\n';

    return 0;
}

/*
  간단한 정렬이지만 시간누적 문제,

  속도 향상을 위한 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/