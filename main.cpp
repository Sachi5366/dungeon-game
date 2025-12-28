#include <bits/stdc++.h>
using namespace std;

/*
 Dungeon Game (LeetCode 174)
 Find the minimum initial health needed to reach the bottom-right cell
 from the top-left, moving only right or down, never letting health drop to 0.

 DP from bottom-right to top-left:
 dp[i][j] = min health required to ENTER cell (i,j)
 Transition:
   need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j]
   dp[i][j] = max(1, need)

 Time:  O(m*n)
 Space: O(m*n)  (can be optimized to O(n))
*/

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m = dungeon.size();
    int n = dungeon[0].size();

    const int INF = 1e9;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));

    dp[m][n - 1] = 1;
    dp[m - 1][n] = 1;

    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            int need = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            dp[i][j] = max(1, need);
        }
    }
    return dp[0][0];
}

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> dungeon(r, vector<int>(c));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> dungeon[i][j];

    cout << calculateMinimumHP(dungeon) << "\n";
    return 0;
}
