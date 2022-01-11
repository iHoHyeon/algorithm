// https://www.acmicpc.net/problem/15889

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int pos[30001];
int power[30001];
pair<int, int> arr[30001];
bool possible[1000001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    if (N == 1) {
        cout << "권병장님, 중대장님이 찾으십니다";
        return 0;
    }

    for (int i = 1; i <= N; i++) cin >> pos[i];
    for (int i = 1; i <= N - 1; i++) cin >> power[i];
    power[N] = 0;

    for (int i = 1; i <= N; i++) arr[i] = make_pair(pos[i], power[i]);
    sort(arr, arr + N);

    bool flag = false;
    memset(possible, false, sizeof(possible));
    possible[0] = true;

    int maxPosition = arr[N].first;
    for (int i = 1; i <= N - 1; i++) {
        int nowPosition = arr[i].first;
        int nowPower = arr[i].second;
        if (!possible[nowPosition]) continue;

        for (int j = nowPosition; j <= min(maxPosition, nowPosition + nowPower); j++) {
            possible[j] = true;
        }
        if (possible[maxPosition]) {
            flag = true;
            break;
        }
    }

    cout << (flag ? "권병장님, 중대장님이 찾으십니다" : "엄마 나 전역 늦어질 것 같아");

    return 0;
}

/*
*/