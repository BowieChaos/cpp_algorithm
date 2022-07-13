#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/69f4e5b7ad284a478777cb2a17fb5e6a?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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