#pragma once
#include <deque>
#include <limits.h>
#include <set>
#include <stack>
#include <vector>
using namespace std;

// NC82 滑动窗口的最大值
// https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=295&tqId=23458&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class MaxWindows {
public:
	vector<int> maxInWindows(const vector<int>& nums, int size) {
		deque<int> dq;
		vector<int> ret_vec;
		for (size_t i = 0; i < size; i++) {
			if (dq.empty()) {
				dq.emplace_back(i);
				continue;
			}

			while (!dq.empty() && nums[i] > nums[dq.back()]) {
				dq.pop_back();
			}
			dq.emplace_back(i);
		}

		ret_vec.emplace_back(nums[dq.front()]);
		for (size_t i = size; i < nums.size(); i++) {
			while (!dq.empty() && nums[i] > nums[dq.back()]) {
				dq.pop_back();
			}
			dq.emplace_back(i);

			if (i-size >= dq.front() ){
				dq.pop_front();
			}
			ret_vec.emplace_back(nums[dq.front()]);
		}
		return ret_vec;
	}

	vector<int> maxInWindows_1(const vector<int>& nums, int size) {
		multiset<int, greater<int>> st;
		for (size_t i = 0; i < size; i++) {
			st.emplace(nums[i]);
		}

		vector<int> ret_vec;
		ret_vec.emplace_back(*st.begin());
		for (size_t i = size; i < nums.size(); i++) {
			st.erase(st.find(nums[i - size]));
			st.emplace(nums[i]);
			ret_vec.emplace_back(*st.begin());
		}
		return ret_vec;
	}
};