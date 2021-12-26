// https://www.acmicpc.net/problem/5525

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int N, M, now, res = 0;
string S;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> S;

    for (int i = 0; i < S.length(); i++) {
        if (S[i + 1] == 'O' && S[i + 2] == 'I') {
            now = 0;
            while (S[i] == 'I' && S[i + 1] == 'O') {
                i += 2;
                now++;
                if (S[i] == 'I' && now == N) {
                    now--;
                    res++;
                }
            }
        }
    }

    cout << res;

    return 0;
}

/*
  시간복잡도 O(N)을 위해서 한 번 탐색으로 포함된 개수를 파악할 방법을 구현해야함
*/