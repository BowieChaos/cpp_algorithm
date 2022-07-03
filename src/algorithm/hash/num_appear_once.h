#pragma once
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class AppearOnce {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param array int整型vector
	 * @return int整型vector
	 */
	// 位运算，找到mask，然后将数组分为两组
	vector<int> FindNumsAppearOnce(vector<int>& array) {
		// write code here
		int tmp = 0;
		for (int i : array) {
			tmp ^= i;
		}
		int mask = 1;
		while ((mask & tmp) == 0) {
			mask <<= 1;
		}
		int a = 0;
		int b = 0;
		for (int i : array) {
			if (i & mask) {
				a ^= i;
			} else {
				b ^= i;
			}
		}
		if (a > b) {
			int tmp = b;
			b = a;
			a = tmp;
		}

		return {a, b};
	}
};