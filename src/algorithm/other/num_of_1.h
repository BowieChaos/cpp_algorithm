#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// NC120 二进制中1的个数
// https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	int NumberOf1(int n) {
		unsigned int base = 0x80000000;
		int ret = 0;
		while (base != 0) {
			if ((n & base) != 0) {
				ret++;
			}
			base = base >> 1;
		}
		return ret;
	}
};