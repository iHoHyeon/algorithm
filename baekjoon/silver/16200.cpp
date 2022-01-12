// https://www.acmicpc.net/problem/16200

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
    cin >> N;

    int temp;

    for (int i = 1; i <= N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    int cnt = 0;

    for (int i = 0; i < N;) {
        cnt++;
        i += v[i];
    }

    cout << cnt;

    return 0;
}

/*
*/