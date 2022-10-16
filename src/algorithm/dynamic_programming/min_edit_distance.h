#pragma once

#include <algorithm>
#include <limits.h>
#include <vector>
#include <string>
using namespace std;

// NC35 编辑距离(二)
// https://www.nowcoder.com/practice/05fed41805ae4394ab6607d0d745c8e4?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        // write code here
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,0));
        for (int i = 0; i <= str1.size(); i++) {
            dp[i][0] = i * dc;
        }
        for (int i = 0; i <= str2.size(); i++) {
            dp[0][i] = i * ic;
        }
        for (int row = 1; row <= str1.size(); row++) {
            for (int col = 1; col <= str2.size(); col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    dp[row][col] = dp[row - 1][col - 1];
                }
                else {
                    dp[row][col] = min(dp[row - 1][col - 1] + rc, min(dp[row - 1][col] + dc, dp[row][col - 1] + ic));
                
                }
            
            }
        }
        return dp[str1.size()][str2.size()];
    }
};