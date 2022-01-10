// https://www.acmicpc.net/problem/23048

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int p[500001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    memset(p, 0, sizeof(p));

    int now = 1;
    p[1] = now;

    for (int i = 2; i <= N; i++) {
        if (p[i] != 0) continue;
        now++;
        for (int j = i; j <= N; j += i) p[j] = now;
    }

    cout << now << '\n';

    for (int i = 1; i <= N; i++) cout << p[i] << ' ';

    return 0;
}

/*
*/