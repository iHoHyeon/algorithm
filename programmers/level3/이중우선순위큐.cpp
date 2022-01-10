// https://programmers.co.kr/learn/courses/30/lessons/42628

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
vector<string> v;

vector<int> solution(vector<string> o) {
    int del1 = 0, del2 = 0;
    vector<int> res;
    for (auto i : o) {
        if (i[0] == 'I') {
            int len = i.size();
            string num = i.substr(2, len);
            if (pq1.size() - del2 == 0) {
                while (!pq1.empty()) pq1.pop();
                del2 = 0;
            }
            if (pq2.size() - del1 == 0) {
                while (!pq2.empty()) pq2.pop();
                del1 = 0;
            }
            pq1.push(stoi(num));
            pq2.push(stoi(num));
        } else {
            if (i[2] == '1') {
                if (!pq1.empty() and pq1.size() - del2 > 0) {
                    pq1.pop();
                    del1++;
                }
            } else {
                if (!pq2.empty() and pq2.size() - del1 > 0) {
                    pq2.pop();
                    del2++;
                }
            }
        }
    }

    if (pq1.size() - del2 > 0 and pq2.size() - del1 > 0) {
        res.push_back(pq1.top());
        res.push_back(pq2.top());
    } else {
        res.push_back(0);
        res.push_back(0);
    }

    for (auto i : res) cout << i << ' ';

    return res;
}

/*
    priority queue를 최대 / 최소로 두 개 만들어서 풀이

    multiset을 이용하면 더 쉽다고한다..
*/