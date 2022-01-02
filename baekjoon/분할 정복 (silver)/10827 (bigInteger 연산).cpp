// https://www.acmicpc.net/problem/10827

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

string add(string s1, string s2) {
    string result(max(s1.size(), s2.size()), '0');
    bool carry = false;
    for (int i = 0; i < result.size(); i++) {
        int temp = carry;
        carry = false;

        if (i < s1.size()) temp += s1[s1.size() - i - 1] - '0';
        if (i < s2.size()) temp += s2[s2.size() - i - 1] - '0';
        if (temp >= 10) {
            carry = true;
            temp -= 10;
        }
        result[result.size() - i - 1] = temp + '0';
    }

    if (carry) result.insert(result.begin(), '1');
    return result;
}

string multiply(string s1, string s2) {
    string result = "0";
    for (int i = 0; i < s2.size(); i++) {
        string line(s1);
        int carry = 0;

        for (int j = s1.size() - 1; j >= 0; j--) {
            int temp = carry;
            carry = 0;
            temp += (s1[j] - '0') * (s2[s2.size() - i - 1] - '0');
            if (temp >= 10) {
                carry = temp / 10;
                temp %= 10;
            }
            line[j] = temp + '0';
        }
        if (carry > 0) line.insert(line.begin(), carry + '0');
        line += string(i, '0');
        result = add(result, line);
    }

    return result;
}

string power(string s1, int p) {
    if (p == 1) return s1;

    string result = power(s1, p - 1);
    result = multiply(result, s1);

    return result;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a;
    int b;

    cin >> a >> b;

    string::iterator finder = find(a.begin(), a.end(), '.');  // a에서 소숫점 자리 찾기
    int dotIdx = 0;

    if (finder != a.end()) {  // 소숫점이 존재한다면
        dotIdx = (a.end() - 1) - finder;
        a.erase(finder);
    }

    dotIdx *= b;
    string res = power(a, b);

    if (dotIdx) {
        res.insert(res.end() - dotIdx, '.');
    }

    cout << res;

    return 0;
}

/*
  kks227's github을 참고해서 bigInteger 덧셈, 곱셈, 제곱을 구현

  구현이 어려워서 https://jaimemin.tistory.com/1076 블로그 풀이를 참고했다.
  추후에 반드시 참고 없이 다시 풀어볼 것!
*/