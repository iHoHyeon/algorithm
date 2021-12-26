// https://www.acmicpc.net/problem/16212

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int temp;
    cin >> N;
    
    vector<int> v;
    while (N--) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end(), greater<int>());

    while (v.size()){
        cout << v.back() << ' ';
        v.pop_back();
    }

    return 0;
}

/*
  vector 등 자료형 사용도 잘 해보자
*/