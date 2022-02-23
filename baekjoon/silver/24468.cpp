// https://www.acmicpc.net/problem/24468

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, char>> ball;
int check[1001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L, N, T;
    cin >> L >> N >> T;

    int S;
    char C;

    for (int i = 1; i <= N; i++) {
        cin >> S >> C;
        ball.push_back({S, C});
    }

    int res = 0;

    for (int i = 1; i <= T; i++) {
        for (int b = 0; b < N; b++) {
            if (ball[b].second == 'L') {
                ball[b].first = ball[b].first - 1;
            } else {
                ball[b].first = ball[b].first + 1;
            }
        }

        vector<int> v;
        int temp = 0;
        fill_n(check, 1001, -1);

        for (int b = 0; b < N; b++) {
            if (ball[b].first == 0 or ball[b].first == L) {
                v.push_back(b);
            } else if (check[ball[b].first] != -1) {
                v.push_back(b);
                v.push_back(check[ball[b].first]);
                temp++;
            } else {
                check[ball[b].first] = b;
            }
        }

        for (int b = 0; b < v.size(); b++) {
            ball[v[b]].second = ball[v[b]].second == 'R' ? 'L' : 'R';
        }
        res += temp;
    }

    cout << res;

    return 0;
}

/*
 */