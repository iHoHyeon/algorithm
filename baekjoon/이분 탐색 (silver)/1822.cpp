// https://www.acmicpc.net/problem/1822

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> a, b, res;

bool binarySearch(int value) {
    int start = 0, end = b.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (b[mid] == value) return true;

        if (b[mid] < value) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return (b[start] == value);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nA, nB;
    cin >> nA >> nB;

    int temp;
    for (int i = 0; i < nA; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    for (int i = 0; i < nB; i++) {
        cin >> temp;
        b.push_back(temp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < nA; i++) {
        if (!binarySearch(a[i])) res.push_back(a[i]);
    }

    cout << res.size() << '\n';
    for (int i = 0; i < res.size(); i++) cout << res[i] << ' ';

    return 0;
}

/*
*/