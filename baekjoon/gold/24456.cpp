// https://www.acmicpc.net/problem/24456

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int num = N * M;

    int Dold = abs(N - M);

    while (num > 1) {
        num--;

        int Dnew = -1;
        for (int i = 1; i * i <= num; i++) {
            if (num % i != 0) continue;

            int j = num / i;

            if (abs(abs(i - j) - Dold) <= K) {
                Dnew = 1;
                break;
            }
        }

        if (Dnew == -1) {
            num++;
            break;
        }
    }

    cout << N * M - num;

    return 0;
}

/*
 */