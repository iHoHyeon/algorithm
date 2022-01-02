// https://www.acmicpc.net/problem/6603

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int res[6];
int S[13];
int k;

void dfs(int n, int dep) {
    if (dep == 6) {
        for (int i = 0; i < 6; i++) cout << res[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = n; i < k; i++) {
        res[dep] = S[i];
        dfs(i + 1, dep + 1);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> k;
        if (k == 0) break;

        for (int i = 0; i < k; i++) cin >> S[i];
        dfs(0, 0);
        cout << '\n';
    }

    return 0;
}

/*
    next_permutation을 이용한 combination으로 풀어보려고 헀는데 
    풀이는 했지만 틀렸고, 디버깅이 어려워서 우선 재귀 dfs로 풀이했다.. 
    */