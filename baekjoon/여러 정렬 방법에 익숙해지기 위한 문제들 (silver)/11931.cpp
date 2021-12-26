// https://www.acmicpc.net/problem/11931

#include <algorithm>
#include <iostream>

using namespace std;

bool compare(int a, int b) { return a > b; }

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n, compare);  // 직접 구현하지 않고 greater<int>()를 사용해도 된다

    for (int i = 0; i < n; i++) cout << arr[i] << '\n';

    return 0;
}