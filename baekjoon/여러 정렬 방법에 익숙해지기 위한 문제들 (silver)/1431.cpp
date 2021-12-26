// https://www.acmicpc.net/problem/1431

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(string a, string b) {
    int lenA = a.size();
    int lenB = b.size();

    if (lenA != lenB) return lenA < lenB;

    int sumA = 0;
    int sumB = 0;

    for (int i = 0; i < lenA; i++) {
        if ('0' <= a[i] && a[i] <= '9') sumA += a[i] - '0';
        if ('0' <= b[i] && b[i] <= '9') sumB += b[i] - '0';
    }

    if (sumA != sumB) return sumA < sumB;

    return a < b;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;

    cin >> N;

    vector<string> v;
    string temp;

    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) cout << v[i][j];
        cout << '\n';
    }

    return 0;
}

/*
  문제 조건에 맞게 비교 함수를 작성해주기만 하면 됨.

  * string 비교는 사전순으로 이루어진다.
*/