// https://www.acmicpc.net/problem/18115

#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
deque<int> d;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, temp;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 1; i <= N; i++) {
        if (v[N - i] == 1)
            d.push_front(i);
        else if (v[N - i] == 2)
            d.insert(d.begin() + 1, i);
        else
            d.push_back(i);
    }

    for (int i = 0; i < d.size(); i++) cout << d[i] << ' ';

    return 0;
}

/*
  거꾸로 생각해보면 
  1 -> 제일 위 카드를 카드 더미 맨 위에 놓는다.
  2 -> 제일 위 카드를 위에서 두번째에 놓는다.
  3 -> 제일 위 카드를 맨 아래에 넣는다.
*/