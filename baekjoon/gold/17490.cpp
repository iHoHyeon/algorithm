// https://www.acmicpc.net/problem/17490

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> v;
vector<long long> g;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M, i, j, T;
    long long K;

    cin >> N >> M >> K;

    v.push_back(0);
    long long temp;
    for (long long i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    bool flag = false;
    for (int a = 0; a < M; a++) {
        cin >> i >> j;

        if ((i == N and j == 1) or (j == N and i == 1)) {
            flag = true;
            g.push_back(N);
        } else
            g.push_back(min(i, j));
    }

    if (M <= 1) {
        cout << "YES";
        return 0;
    }

    sort(g.begin(), g.end());

    long long start = g[0] + 1;

    long long s = start, e;

    long long need = 0;

    for (long long i = 1; i < g.size(); i++) {
        e = g[i];

        if (s <= e) {
            temp = 9999999;
            for (long long j = s; j <= e; j++) {
                temp = min(temp, v[j]);
            }

            s = e + 1;
            need += temp;
        }
    }

    temp = 9999999;
    for (long long i = 1; i <= start - 1; i++) {
        temp = min(temp, v[i]);
    }
    if (flag) {
        need += temp;
        temp = 9999999;
    }

    for (long long i = N; i >= e + 1; i--) {
        temp = min(temp, v[i]);
    }
    if (temp != 9999999) need += temp;

    if (need > K)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}

/*
*/