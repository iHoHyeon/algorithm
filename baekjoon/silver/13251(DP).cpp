// https://www.acmicpc.net/problem/13251

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int color[88];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    int N = 0;

    for (int i = 1; i <= M; i++) {
        cin >> color[i];
        N += color[i];
    }

    int K;
    cin >> K;

    double res = 0.00;

    for (int i = 1; i <= M; i++) {
        double temp = 1.00;

        if (color[i] >= K) {
            for (int j = 0; j < K; j++) {
                temp *= (double)(color[i] - j) / (N - j);
            }
            res += temp;
        }
    }

    cout << fixed;
    cout.precision(15);

    cout << res;

    return 0;
}

/*
*/