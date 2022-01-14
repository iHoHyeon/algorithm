// https://www.acmicpc.net/problem/23757

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        pq.push(temp);
    }

    bool flag = true;

    for (int i = 1; i <= M; i++) {
        cin >> temp;
        int top = pq.top();
        if (top == temp) {
            pq.pop();
        } else if (top > temp) {
            pq.pop();
            pq.push(top - temp);
        } else {
            flag = false;
            break;
        }
    }

    cout << (flag ? 1 : 0);

    return 0;
}

/*
*/