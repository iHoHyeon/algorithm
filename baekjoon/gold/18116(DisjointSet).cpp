// https://www.acmicpc.net/problem/18116

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int pointer[1000001];
int level[1000001];
int cnt[1000001];

int myFind(int a) {
    if (a == pointer[a]) return a;

    return pointer[a] = myFind(pointer[a]);
}

void myUnion(int a, int b) {
    int rootA = myFind(a);
    int rootB = myFind(b);

    if (rootA == rootB) return;

    if (level[rootA] > level[rootB]) swap(rootA, rootB);

    pointer[rootA] = rootB;

    if (level[rootA] == level[rootB]) level[rootB]++;

    cnt[rootB] = cnt[rootA] + cnt[rootB];
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    char com;
    int a, b, c;
    for (int i = 0; i <= 1000000; i++) pointer[i] = i;
    fill_n(cnt, 1000001, 1);

    while (N--) {
        cin >> com;
        if (com == 'I') {
            cin >> a >> b;
            myUnion(a, b);
        } else {
            cin >> c;
            cout << cnt[myFind(c)] << '\n';
        }
    }

    return 0;
}

/*
  Disjoint Set 자료구조를 구현
  합집합 (union), 찾기 (find) 연산을 지원하며 linked-list 혹은 트리구조를 사용해서 구현

  트리로 구현했을 때 이득이 많아서 주로 트리로 구현되며 
  union 시 tree 높이(level)와 경로 압축을 통해서 최적화가 가능하다.
*/