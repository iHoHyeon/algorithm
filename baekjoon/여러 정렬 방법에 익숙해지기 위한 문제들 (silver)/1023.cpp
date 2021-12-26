// https://www.acmicpc.net/problem/1026

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, res = 0;
    cin >> N;

    int* A = new int[N];
    int* B = new int[N];

    for (int i = 0; i< N;i++) cin >> A[i];
    for (int i = 0; i< N;i++) cin >> B[i];

    sort(A,A+N);
    sort(B,B+N,greater<int>());

    while(N--){
        res += A[N]*B[N];
    }
    
    cout << res;

    return 0;
}
