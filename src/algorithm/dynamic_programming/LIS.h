#pragma once

#include <algorithm>
#include <limits.h>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/5164f38b67f846fb8699e9352695cd2f?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class LISSolution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 给定数组的最长严格上升子序列的长度。
	 * @param arr int整型vector 给定的数组
	 * @return int整型
	 */
	int LIS(vector<int>& arr) {
		// write code here
		int ret = 0;
		if (arr.empty()) {
			return ret;
		}
		vector<int> dp(arr.size(), 1);
		ret = 1;
		for (size_t i = 1; i < arr.size(); i++) {
			for (size_t j = 0; j < i; j++) {
				if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					ret = max(ret, dp[i]);
				}
			}
		}
		return ret;
	}
};


// https://www.nowcoder.com/practice/9cf027bf54714ad889d4f30ff0ae5481?tpId=117&tqId=37796&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
class Solution {
public:
    /**
     * return the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    vector<int> LIS(vector<int>& arr) {
        // write code here
        // 第一步：利用贪心+二分求最长递增子序列长度
        vector<int> res;
        vector<int> maxLen;
        if (arr.size() < 1) return res;
        res.emplace_back(arr[0]);  // 注：emplace_back(val)作用同push_back，效率更高
        maxLen.emplace_back(1);
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > res.back()) {
                res.emplace_back(arr[i]);
                maxLen.emplace_back(res.size());
            } else {
                // lower_bound(begin, end, val)包含在<algorithm>中
                // 它的作用是返回有序数组begin..end中第一个大于等于val的元素的迭代器
                int pos = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
                res[pos] = arr[i];
                maxLen.emplace_back(pos+1);
            }
        }
        // 第二步：填充最长递增子序列
        for (int i = arr.size()-1, j = res.size(); j > 0; --i) {
            if (maxLen[i] == j) {
                res[--j] = arr[i];
            }
        }
        return res;
    }
};