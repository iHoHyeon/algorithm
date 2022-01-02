// https://www.acmicpc.net/problem/17204

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[150];
bool visit[150];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    for (int i = 0; i <= N - 1; i++) cin >> a[i];

    int next = 0;
    visit[0] = true;

    int res = 0;

    while (!visit[K]) {
        next = a[next];
        if (visit[next]) {
            res = -1;
            break;
        }

        visit[next] = true;
        res++;
    }

    cout << res;

    return 0;
}

/*
*/