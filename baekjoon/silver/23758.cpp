// https://www.acmicpc.net/problem/23758

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    scanf("%d", &N);

    int temp;
    for (int i = 0; i < N; i++) {
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    long long cnt = 0;
    for (int i = 0; i <= (N + 1) / 2 - 1; i++) {
        int now = v[i];
        while (now > 1) {
            cnt++;
            now /= 2;
        }
    }

    cout << cnt + 1;

    return 0;
}

/*
  1. 입력을 모두 받고 매번 정렬 -> 시간 초과
  2. N+1 번째까지만 우선순위 큐에 넣고 pop / push 반복 -> 시간초과
  3. 일반해 발견 -> N+1번째까지 모든 수를 2로 나눌 수 있는 횟수의 합이 정답이다.
*/