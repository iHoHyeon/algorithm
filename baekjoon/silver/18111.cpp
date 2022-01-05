// https://www.acmicpc.net/problem/18111

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int map[501][501];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, B;
    cin >> N >> M >> B;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
    int resTime = 987654321, resHeight = -1;

    for (int h = 0; h <= 256; h++) {
        int time = 0, block = B;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                int temp = map[i][j] - h;
                if (temp > 0) {
                    time += 2 * temp;
                    block += temp;
                } else if (temp < 0) {
                    time -= temp;
                    block += temp;
                }
            }
        }

        if (block < 0) continue;

        if (time == resTime && resHeight < h) {
            resHeight = h;
        } else if (time < resTime) {
            resTime = time;
            resHeight = h;
        }
    }

    cout << resTime << ' ' << resHeight;

    return 0;
}

/*
  h의 값이 항상 주어진 map 높이의 최대와 최소 사이라고 착각하여 이분탐색으로 구현했으나
  그게 아니라 최대 / 최소를 벗어나는 정답이 생길 수 있고
  경우의 수가 256가지 이므로 for 루프를 돌도록 수정했다. 
*/