// https://www.acmicpc.net/problem/17198

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

string map[10];
int bx, by, lx, ly, rx, ry;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 10; i++) {
        cin >> map[i];
        for (int j = 0; j < 10; j++) {
            if (map[i][j] == 'B') {
                bx = i;
                by = j;
            } else if (map[i][j] == 'L') {
                lx = i;
                ly = j;
            } else if (map[i][j] == 'R') {
                rx = i;
                ry = j;
            }
        }
    }

    if ((bx == lx && bx == rx && ((by < ry && ry < ly) || (ly < ry && ry < by))) || (by == ly && by == ry && ((bx < rx && rx < lx) || (lx < rx && rx < bx))))
        cout << abs(bx - lx) + abs(by - ly) + 1;
    else
        cout << abs(bx - lx) + abs(by - ly) - 1;

    return 0;
}

/*
*/