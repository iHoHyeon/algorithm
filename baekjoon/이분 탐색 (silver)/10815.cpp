// https://www.acmicpc.net/problem/10815

#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> s;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        s.insert(temp);
    }
    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> temp;
        cout << ((s.find(temp) == s.end()) ? 0 : 1) << ' ';
    }

    return 0;
}

/*
  set의 find를 이용하여 탐색시간을 줄였다.
  
  set은 균형 이진 트리를 사용하여 find, insert에서 log 시간 복잡도를 가질 수 있다.

  
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int b_search(int value) {
    int start = 0, end = v.size() - 1;

    while (start < end) {
        int mid = (start + end) / 2;
        if (value == v[mid]) return mid;

        if (value > v[mid])
            start = mid + 1;
        else
            end = mid;
    }

    return start;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> temp;
        int idx = b_search(temp);
        cout << ((v[idx] == temp) ? 1 : 0) << ' ';
    }

    return 0;
}

/*
    set 컨테이너 대신 직접 이분탐색을 구현
*/