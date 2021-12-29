#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
bool graph[101][101];

int solution(int n, vector<vector<int>> results) {
    for (int i = 0; i < results.size(); i++) {
        int winnerIdx = results[i][0];
        int loserIdx = results[i][1];

        graph[winnerIdx][loserIdx] = true;
        graph[loserIdx][loserIdx] = true;
        graph[winnerIdx][winnerIdx] = true;
    }

    for (int mid = 1; mid <= n; mid++) {
        for (int start = 1; start <= n; start++) {
            if (start == mid) continue;
            for (int end = 1; end <= n; end++) {
                if (mid == end) continue;
                if (graph[start][mid] && graph[mid][end])
                    graph[start][end] = true;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 1; j <= n; j++) {
            if (!graph[i][j] && !graph[j][i]) {
                flag = false;
                break;
            }
        }
        if (flag) res++;
    }

    return res;
}
