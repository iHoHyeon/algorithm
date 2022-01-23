// https://www.acmicpc.net/problem/1865

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int value[501][501];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        for (int i = 0; i <= 500; i++) {
            for (int j = 0; j <= 500; j++) {
                value[i][j] = 987654321;
            }
        }
        int N, M, W;
        cin >> N >> M >> W;

        while (M--) {
            int S, E, T;
            cin >> S >> E >> T;

            value[S][E] = min(value[S][E], T);
            value[E][S] = min(value[E][S], T);
        }

        while (W--) {
            int S, E, T;
            cin >> S >> E >> T;

            value[S][E] = -T;
        }

        for (int m = 1; m <= N; m++) {
            for (int s = 1; s <= N; s++) {
                if (value[s][m] == 987654321) continue;
                for (int e = 1; e <= N; e++) {
                    if (value[m][e] == 987654321) continue;
                    value[s][e] = min(value[s][e], value[s][m] + value[m][e]);
                }
            }
        }

        bool flag = false;
        for (int i = 1; i <= N; i++) {
            if (value[i][i] < 0) {
                flag = true;
                break;
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}

/*
*/