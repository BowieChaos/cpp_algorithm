#pragma once
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

// NC56 回文数字
// https://www.nowcoder.com/practice/35b8166c135448c5a5ba2cff8d430c32?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	/**
	 *
	 * @param x int整型
	 * @return bool布尔型
	 */
	bool isPalindrome(int x) {
		// write code here
		if (x < 0)
			return false;
		long long tmp = x;
		if (tmp > INT_MAX || tmp < INT_MIN)
			return false;
		long long reverse = 0;
		while (tmp) {
			reverse = reverse * 10 + tmp % 10;
			tmp = tmp / 10;
		}
		long long tmp2 = x;
		if (tmp2 == reverse)
			return true;
		else
			return false;
	}
};