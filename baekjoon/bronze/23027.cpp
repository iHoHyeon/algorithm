// https://www.acmicpc.net/problem/23027

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string st;
    cin >> st;

    int len = st.length();

    for (int i = 0; i < len; i++) {
        if (st[i] == 'A') {
            for (int j = 0; j < len; j++) {
                if (st[j] == 'B' or st[j] == 'C' or st[j] == 'D' or st[j] == 'F') st[j] = 'A';
            }
            cout << st;
            return 0;
        }
    }

    for (int i = 0; i < len; i++) {
        if (st[i] == 'B') {
            for (int j = 0; j < len; j++) {
                if (st[j] == 'C' or st[j] == 'D' or st[j] == 'F') st[j] = 'B';
            }
            cout << st;
            return 0;
        }
    }

    for (int i = 0; i < len; i++) {
        if (st[i] == 'C') {
            for (int j = 0; j < len; j++) {
                if (st[j] == 'D' or st[j] == 'F') st[j] = 'C';
            }
            cout << st;
            return 0;
        }
    }

    for (int j = 0; j < len; j++) {
        cout << 'A';
    }

    return 0;
}