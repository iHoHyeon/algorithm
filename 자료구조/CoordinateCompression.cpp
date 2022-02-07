#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> temp;

int getCompression(int a) {
    return 1 + (lower_bound(temp.begin(), temp.end(), a) - temp.begin());
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int a;
        cin >> a;

        v.push_back(a);
        temp.push_back(a);
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < v.size(); i++) {
        int compressed = getCompression(v[i]);
    }

    return 0;
}

/*
    좌표압축
    v 원소의 압축된 좌표를 얻기 위해서는 getCompression을 통해서
    temp의 idx를 꺼내서 사용하면 된다.
*/