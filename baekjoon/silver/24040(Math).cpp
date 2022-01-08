// https://www.acmicpc.net/problem/24040

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        if (N % 9 == 0 or N % 3 == 2)
            cout << "TAK" << '\n';
        else
            cout << "NIE" << '\n';
    }

    return 0;
}

/*
    xy = n 
    x + y === 0 (mod 3) 

    을 만족하는 순서쌍 x, y가 존재하면 된다.ㄴ
*/