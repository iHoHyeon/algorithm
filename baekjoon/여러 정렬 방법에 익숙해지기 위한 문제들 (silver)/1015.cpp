// https://www.acmicpc.net/problem/1015

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A[50], rawA[50], res[50], idx = 0;
    cin >> N;

    for (int i = 0; i < N; i++) cin >> A[i];

    copy(A, A + N, rawA);

    sort(A, A + N);

    for (int i = 0; i < N; i++) {
        int now = A[i];
        int last = 0;
        while (now == A[i]) {
            for (int j = last; j < N; j++) {
                if (rawA[j] == now) {
                    res[j] = idx++;
                    i++;
                    last = j + 1;
                    break;
                }
            }
        }
        i--;
    }

    for (int i = 0; i < N; i++) cout << res[i] << ' ';

    return 0;
}

/*
  배열의 해당 원소 index 탐색을 구현하였다.
  vector의 find()와 distance()를 이용한 방법도 있으니 참고하자
*/