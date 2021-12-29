// https://www.acmicpc.net/problem/2352

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {  // lower_bound
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp, res = 0;
    vector<int> v;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;

        int idx = lower_bound(v.begin(), v.end(), temp) - v.begin();

        if (idx == v.size())
            v.push_back(temp);
        else {
            v[idx] = temp;
        }
    }
    res = v.size();
    cout << res;
    return 0;
}

int main() {  // lower_bound를 이분탐색으로 구현
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp, res = 0;
    vector<int> v;
    cin >> n;
    cin >> temp;
    v.push_back(temp);
    for (int i = 2; i <= n; i++) {
        cin >> temp;
        if (v[v.size() - 1] < temp) {
            v.push_back(temp);
        } else {
            int start = 0, end = v.size() - 1, mid;
            while (start <= end) {
                mid = (start + end) / 2;
                if (v[mid] < temp)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            v[start] = temp;
        }
    }
    res = v.size();
    cout << res;
    return 0;
}

int main() {  // index tree 를 이용
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp, res = 0;
    cin >> n;

    pair<int, int> arr[40001];

    for (int i = 1; i <= n; i++) {
        cin >> temp;
        arr[i] = make_pair(temp, i);
    }

    sort(arr + 1, arr + n + 1);

    int dp[40001];
    fill_n(dp, 40001, 0);

    for (int i = 1; i <= n; i++) {
        int idx = arr[i].second;
        int maxTemp = 0;
        for (int j = 1; j < idx; j++) {  // idx트리를 이용해서 검색량을 줄인다 -> O(NlogN)
            if (dp[j] > maxTemp) {
                maxTemp = dp[j];
            }
        }
        dp[idx] = maxTemp + 1;
        res = max(res, dp[idx]);
    }

    cout << res;

    return 0;
}

/*
  단순 O(N^2) dp 방식으로는 시간초과
  O(NlogN) 방식으로 구현해야함 -> Lower Bound, Index Tree 방법이 존재한다. (https://dyngina.tistory.com/16)
  dp[N]의 값을 정할 때 dp[1~N]의 탐색을 이분탐색으로 진행하면 된다 (Lower Bound를 이분탐색으로).
  or lower_bound 사용
*/