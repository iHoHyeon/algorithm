// https://www.acmicpc.net/problem/2011

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long dp[5001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string st;
    cin >> st;

    dp[0] = 1;
    dp[1] = 1;

    if (st[0] == '0') {
        cout << 0;
        return 0;
    }

    for (int i = 2; i <= st.size(); i++) {
        if (st[i - 1] == '0') {
            if (!(st[i - 2] == '1' || st[i - 2] == '2')) {
                cout << 0;
                return 0;
            }
            dp[i] = dp[i - 2];
        } else {
            dp[i] = dp[i - 1];

            if (st[i - 2] == '0') continue;
            if (st[i - 2] == '1' or (st[i - 2] == '2' and st[i - 1] < '7')) dp[i] = (dp[i] + dp[i - 2]) % 1000000;
        }
    }

    cout << dp[st.size()] % 1000000;

    return 0;
}

/*
    dp 점화식 bottom-up
    입력받은 string을 idx = 0 부터 idx = st.size()까지 순회하면서
    i) i번째 문자가 '0'인 경우 
        -> 0은 혼자서 해석될 수 없으므로 무조건 i-1번째 문자와 쌍을 이루어야한다.
        따라서 i-1번째 문자열이 '1' or '2'가 아니라면 해석할 수 없는 예외처리를 해주어야 하고
        '1' or '2' 라면 dp[i] = dp[i-2]의 점화식을 따른다. (i-1, i 번째가 쌍을 이루어 해석되는 한 가지 경우 뿐)

    ii) i번째 문자가 '0'이 아닌 경우
        -> 무조건 혼자서 해석될 수 있으므로 
        dp[i] = (i번째 문자가 혼자서 해석되는 경우의 수) + (i번째 문자가 i-1번째 문자와 쌍을 이루어 해석되는 경우의 수)
        
        코드로 나타내면 dp[i] = dp[i-1] + ((i번쨰와 i-1번째가 쌍을 이룰 수 있는 조건) ? dp[i-2] : 0 )
*/