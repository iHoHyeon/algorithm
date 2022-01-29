
#include <algorithm>
#include <iostream>

using namespace std;

long long tree[n], arr[n];

long long init(long long N, long long s, long long e) {
    if (s == e) return tree[N] = arr[s];

    long long mid = (s + e) / 2;
    return tree[N] = init(N * 2, s, mid) + init(N * 2 + 1, mid + 1, e);
}

long long query(long long N, long long s, long long e, long long l, long long r) {
    if (l > e or r < s) return 0;
    if (l <= s and e <= r) return tree[N];

    long long mid = (s + e) / 2;
    return query(N * 2, s, mid, l, r) + query(N * 2 + 1, mid + 1, e, l, r);
}
// s, e는 현재 노드 N이 나타내는 구간 /  l, r은 범위 합을 구해야하는 구간

void update(long long N, long long s, long long e, long long idx, long long val) {
    if (idx > e or idx < s) return;
    if (s == e) {
        if (idx == s) tree[N] = val;
        return;
    }

    long long mid = (s + e) / 2;
    update(N * 2, s, mid, idx, val);
    update(N * 2 + 1, mid + 1, e, idx, val);
    tree[N] = tree[N * 2] + tree[N * 2 + 1];
}

/*
    1. Init 함수로, 초기 segment tree를 구성하는 함수
    2. Update 함수로 특정 원소를 update 하는 함수
    3. Query 함수로 특정 구간 [l, r] 의 합을 구해주는 함수

    Update와 Query는 문제마다 달라질 수 있다.

    tree라는 배열의 x번째 index, 즉 tree[x]에 세그먼트 트리 구간합이 저장
    arr라는 배열에는 원래 주어진 배열을 저장

    재귀함수 (Top - Down) 방식으로 구현하자

    어느 구간의 합인지는 재귀함수의 파라미터로 구분된다
*/