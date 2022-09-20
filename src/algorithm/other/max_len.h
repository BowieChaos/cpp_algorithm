#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// NC41 最长无重复子数组
// https://www.nowcoder.com/practice/b56799ebfd684fb394bd315e89324fb4?tpId=117&tqId=37816&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
class MaxLength {
public:
	/**
	 *
	 * @param arr int整型vector the array
	 * @return int整型
	 */
	int maxLength(vector<int>& arr) {
		// write code here
		if (arr.empty()) {
			return 0;
		}
		int ret = 1;
		int left = 0;
		int right = 0;
		unordered_set<int> st;
		while (right < arr.size()) {
			int i = arr[right];
			if (!st.count(i)) {
				st.emplace(i);
				right++;
				if (right - left > ret) {
					ret = right - left;
				}
			} else {
				while (st.count(i)) {
					int i_delete = arr[left];
					st.erase(i_delete);
					left++;
				}
			}
		}
		return ret;
	}
};