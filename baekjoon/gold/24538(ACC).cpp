// https://www.acmicpc.net/problem/24538

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long s[1000111];
vector<long long> e[1000111];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long K, N;
    cin >> N >> K;

    long long start, end;
    while (N--) {
        cin >> start >> end;
        s[start]++;
        e[end + 1].push_back(end - start + 1);
    }

    long long now = 0;
    long long num = 0;

    for (int i = 1; i <= K; i++) {
        if (s[i]) {
            num += s[i];
        }
        if (e[i].size()) {
            num -= e[i].size();
        }

        now += num;

        for (auto ex : e[i]) now -= ex;

        cout << now << ' ';
    }

    return 0;
}

/*
 */