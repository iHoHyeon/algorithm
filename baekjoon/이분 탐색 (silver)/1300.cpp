// https://www.acmicpc.net/problem/1300

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, k;
    cin >> N >> k;

    long long start = 1, end = min((long long)1000000000, N * N), res;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long cnt = 0;

        for (long long i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }

        if (cnt < k) {
            start = mid + 1;
        } else {
            res = mid;
            end = mid - 1;
        }
    }

    cout << res;

    return 0;
}

/*
    모든 값을 저장하고 k번째를 찾는 것은 시간, 메모리 상 불가능

    따라서 B[k]값의 후보들을 이분탐색으로 찾아준다.
    start = 1, end = min(1_000_000_000, N*N) 으로 시작하여 
    mid보다 작거나 같은 i*j의 개수가 몇개인지 k와 비교해준다.

    mid 보다 작거나 같은 i*j의 개수가 k보다 크거나 같다면 mid는 B[k]의 후보가 될 수 있고,
    따라서 res의 값을 갱신하고 탐색을 진행한다.
    
    mid 보다 작거나 같은 i*j의 개수가 k보다 작다면 mid는 절대로 B[k]가 될 수 없다. 따라서 
    res의 값을 갱신하지 않고 탐색을 진행한다.
    */