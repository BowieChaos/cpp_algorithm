#pragma once
#include <string>
using namespace std;

// NC57 反转数字
// https://www.nowcoder.com/practice/1a3de8b83d12437aa05694b90e02f47a?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	/**
	 *
	 * @param x int整型
	 * @return int整型
	 */
	int reverse(int x) {
		// write code here
		//         long long num = x<0? -x : x;
		//         string rx = to_string(num);
		//         ::reverse(rx.begin(),rx.end());
		//         num = stoll(rx);
		//         if(x < 0) num = -num;
		//         if(num < INT_MIN || num > INT_MAX) return 0;
		//         return num;
		long long res = 0;
		while (x != 0) {
			int t = x % 10;
			res = res * 10 + t;
			x /= 10;
		}
		if (res < INT_MIN || res > INT_MAX)
			return 0;
		return res;
	}
};