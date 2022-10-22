#pragma once
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

// NC77 调整数组顺序使奇数位于偶数前面(一)
// https://www.nowcoder.com/practice/ef1f53ef31ca408cada5093c8780f44b?tpId=117&tqId=37776&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D3%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param array int整型vector
	 * @return int整型vector
	 */
	vector<int> reOrderArray(vector<int>& array) {
		// write code here
		if (array.empty()) {
			return array;
		}

		for (int i = 1; i < array.size(); i++) {
			for (int j = i; j - 1 >= 0; j--) {
				if (array[j] % 2 == 0) {
					continue;
				}

				if (array[j - 1] % 2 == 1) {
					continue;
				}

				swap(array[j], array[j - 1]);
			}
		}
		return array;
	}
};