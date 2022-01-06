// https://www.acmicpc.net/problem/18120

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<long long, long long> dw;                     // di^2, wi pair 저장
vector<pair<long long, long double>> acc;         //wi 누적합, wi*di 누적합 pair
vector<pair<long double, long double>> disRange;  //acc와 연관된 거리 범위
int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A;
    cin >> N >> A;

    long long x, y, w;
    while (N--) {
        cin >> x >> y >> w;
        long long d2 = x * x + y * y;
        dw[d2] += w;
    }

    long double res = 0.0;

    acc.push_back(make_pair(0, 0));
    disRange.push_back(make_pair(0, 0));

    for (auto i = dw.begin(); i != dw.end(); i++) {
        long long accW = (*i).second + acc.back().first;
        long double accWD = (*i).second * sqrt((*i).first) + acc.back().second;
        acc.push_back(make_pair(accW, accWD));

        if (i == --dw.end()) {
            disRange.push_back(make_pair(sqrt((*i).first), 1000000000));
        } else {
            disRange.push_back(make_pair(sqrt((*i).first), sqrt((*next(i, 1)).first)));
        }
    }

    int len = acc.size();
    for (int i = 1; i < len; i++) {
        long long xj = acc[i].first;
        long double yj = acc[i].second;

        long double axis = (long double)xj / (long double)(2 * A);
        long double tempRes = 0.0;
        if (disRange[i].second < axis) {
            tempRes = -1 * A * disRange[i].second * disRange[i].second + xj * disRange[i].second - yj;
        } else if (disRange[i].first > axis) {
            tempRes = -1 * A * disRange[i].first * disRange[i].first + xj * disRange[i].first - yj;
        } else {
            tempRes = (long double)(xj * xj) / (long double)(4 * A) - yj;
        }
        res = max(res, tempRes);
    }

    cout << fixed;
    cout.precision(10);

    cout << res << '\n';

    return 0;
}

/*
  상혁이가 얻을 수 있는 이득은 r에 관한 방정식을 따른다.

  최댓값 => B(r) = -A r^2 + Xj r - Yj
  (Xj = 이득의 j번째까지 누적합, Yj = 이득 * 원점으로부터 거리의 누적합)

  j에 따른 r의 범위에 이차식 B(r)이 어디에서 최댓값을 갖는지 계산해주면 된다.
*/