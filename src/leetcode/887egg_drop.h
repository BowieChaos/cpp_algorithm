#pragma once
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// 887. 鸡蛋掉落
// https://leetcode.cn/problems/super-egg-drop/

class Solution {
public:
	int superEggDrop(int k, int n) {
		if (k < 1 || n < 1) {
			return 0;
		}
		return core(k, n);
	}

	int core(int k, int n) {
		if (n == 0) {
			return 0;
		}
		if (k == 1) {
			return n;
		}
		int ret = 100000;
		for (int i = 1; i <= n; i++) {
			ret = min(ret, max(core(k - 1, i - 1), core(k, n - i)));
		}
		return ret + 1;
	}
};