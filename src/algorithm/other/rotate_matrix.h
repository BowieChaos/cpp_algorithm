#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// NC18 顺时针旋转矩阵
// https://www.nowcoder.com/practice/2e95333fbdd4451395066957e24909cc?tpId=295&tqId=693&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class RotateMatrix {
public:
    vector<vector<int>> rotateMatrix(vector<vector<int>> mat, int n) {
        // write code here
        vector<vector<int>> ret;
        if (mat.empty() || mat[0].empty() || n <= 0) {
            return ret;
        }
        vector<vector<int>> tmp_vec(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int new_i = j;
                int new_j = n - i - 1;
                tmp_vec[new_i][new_j] = mat[i][j];
            }
        }
        return tmp_vec;
    }
};