#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// NC144 懂二进制
// https://www.nowcoder.com/practice/120e406db3fd46f09d55d59093f13dd8?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param m int整型
	 * @param n int整型
	 * @return int整型
	 */
	int countBitDiff(int m, int n) {
		// write code here
		unsigned int tmp = m ^ n;
		unsigned int k = 1;
		int ret = 0;
		while (k) {
			if (k & tmp) {
				ret++;
			}
			k = k << 1;
		}
        return ret;
	}
};