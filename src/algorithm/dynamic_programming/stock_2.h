#pragma once

#include <algorithm>
#include <limits.h>
#include <string>
#include <vector>
using namespace std;

// BM81 买卖股票的最好时机(二)
// https://www.nowcoder.com/practice/9e5e3c2603064829b0a0bbfca10594e9?tpId=295&tqId=1073471&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class Stock2 {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 计算最大收益
	 * @param prices int整型vector 股票每一天的价格
	 * @return int整型
	 */
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1) {
			return 0;
		}
		vector<int> diff(prices.size() - 1);
		for (int i = 1; i < prices.size(); i++) {
			diff[i - 1] = prices[i] - prices[i - 1];
		}

		int ret = 0;
		for (int i = 0; i < diff.size(); i++) {
			if (diff[i] > 0) {

				ret += diff[i];
			}
		}
		return ret >= 0 ? ret : 0;
	}
};