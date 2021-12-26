// https://www.acmicpc.net/problem/6986

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<double> v;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    double temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    double sum = 0.0, side = K * (v[K] + v[N - K - 1]);

    for (int i = K; i < v.size() - K; i++) sum += v[i];

    cout << fixed;
    cout.precision(2);  // cout << fixed & precision(n) => 소수점 아래 n자리까지 고정

    cout << sum / (N - 2 * K) + 1e-13 << '\n';
    cout << (sum + side) / N + 1e-13 << '\n';

    return 0;
}

/*
    소수를 연산(반올림)하는 경우 오차에 항상 주의

    예를 들어서 4.45로 저장되어야 할 수가 4.44999999999로 저장된 경우 반올림하면 
    4.5가 아니라 44.4가 되어 버린다.

    따라서 적당한 수를 더한 후 반올림 함으로 해결한다.

    1e-13 정도의 수를 더해준다. * 1e-15부터는 0이 되어버려 의미가 없으니 주의
*/