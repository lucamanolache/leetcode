using namespace std;

u_int8_t min3(u_int8_t t1, u_int8_t t2, u_int8_t t3) {
    return std::min(t1, std::min(t2, t3));
}

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    u_int8_t dp[matrix.size()][matrix[0].size()];
    dp[0][0] = matrix[0][0] - '0';
    for (int i = 1; i < matrix.size(); ++i) {
        dp[i][0] = matrix[i][0] - '0';
    }
    for (int j = 1; j < matrix[0].size(); ++j) {
        dp[0][j] = matrix[0][j] - '0';
    }
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 1; j < matrix[0].size(); ++j) {
            dp[i][j] = (matrix[i][j] - '0') *
                       (min3(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1);
        }
    }

    int ret = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[i][j] == '1') {
                int ct = dp[i][j] * dp[i][j];
                for (int k = i + 1; k < matrix.size() && dp[k][j] >= dp[i][j] && dp[k][j]; ++k) {
                    ct += dp[i][j];
                }
                ret = max(ct, ret);
                ct = dp[i][j] * dp[i][j];
                for (int k = j + 1; k < matrix[0].size() && dp[i][k] >= dp[i][j] && dp[i][k]; ++k) {
                    ct += dp[i][j];
                }
                ret = max(ct, ret);
            }
        }
    }

    return ret;
    }
};