#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 1e9;  // 设定一个很大的值

int main() {
    int X, Y, n;
    cin >> X >> Y >> n;

    vector<vector<int>> dp(X + 1, vector<int>(Y + 1, INF));
    dp[0][0] = 0;  // 初始状态：不购买任何车辆，花费为 0

    for (int i = 0; i < n; i++) {
        int mi, xi, yi, ki;
        cin >> mi >> xi >> yi >> ki;

        vector<vector<int>> new_dp = dp; // 复制当前 dp 数组

        // 存储所有选项（包括默认方案）
        vector<vector<int>> options;
        options.push_back({mi, xi, yi});  // 默认方案

        for (int j = 0; j < ki; j++) {
            int mij, xij, yij;
            cin >> mij >> xij >> yij;
            options.push_back({mij, xi + xij, yi + yij});
        }

        // 处理该种汽车的所有方案
        for (auto &opt : options) {
            int cost = opt[0], pax = opt[1], cargo = opt[2];

            for (int a = X; a >= 0; a--) {
                for (int b = Y; b >= 0; b--) {
                    int newA = min(X, a + pax);
                    int newB = min(Y, b + cargo);
                    new_dp[newA][newB] = min(new_dp[newA][newB], dp[a][b] + cost);
                }
            }
        }

        dp = new_dp;
    }

    cout << dp[X][Y] << endl;  // 输出最优解

    return 0;
}