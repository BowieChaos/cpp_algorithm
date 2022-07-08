#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/b4525d1d84934cf280439aeecc36f4af?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class LongestPalindrome {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param A string字符串
	 * @return int整型
	 */
	int getLongestPalindrome(string A) {
		// write code here
		if (A.empty()) {
			return 0;
		}
		vector<vector<bool>> dp(A.size(), vector<bool>(A.size(), false));
		int ret = 0;
		for (int c = 0; c < A.size(); c++) {
			for (int i = 0; i < A.size() - c; i++) {
				int j = c + i;
				if (j >= A.size()) {
					break;
				}
				if (A[i] == A[j]) {
					if (c <= 1) {
						dp[i][j] = true;
					} else {
						dp[i][j] = dp[i + 1][j - 1];
					}
				}
				if (dp[i][j]) {
					ret = max(ret, c + 1);
				}
			}
		}
        return ret;
	}
};