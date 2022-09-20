#pragma once

#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <vector>
using namespace std;

// NC19 连续子数组的最大和
// https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class SumSubArray {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) {
            return 0;
        }
        vector<int> dp(array.size());
        dp[0] = array[0];
        int ret = dp[0];
        for (size_t i = 1;i<dp.size();i++) {
            if (dp[i-1]>=0) {
                dp[i] = array[i] + dp[i-1];
            } else {
                dp[i] = array[i];
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};