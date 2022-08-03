#pragma once
#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>
using namespace std;

// NC95 数组中的最长连续子序列
// https://www.nowcoder.com/practice/eac1c953170243338f941959146ac4bf?tpId=117&tqId=37783&rp=1&ru=%2Fexam%2Foj&qru=%2Fexam%2Foj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class Solution {
public:
	/**
	 * max increasing subsequence
	 * @param arr int整型vector the array
	 * @return int整型
	 */
	int ret = 1;
	int MLS(vector<int>& arr) {
		// write code here
		if (arr.empty()) {
			return 0;
		}
		int ret = 1;
		sort(arr.begin(), arr.end());
		auto it = unique(arr.begin(), arr.end());
		arr.erase(it, arr.end());
		int len = 1;
		for (int i = 0; i < arr.size() - 1; i++) {
			if (arr[i] == arr[i + 1] - 1) {
				len++;
			} else {
				ret = max(ret, len);
                len == 1;
			}
		}
        return ret;
	}
};

class Solution_SS {
public:
	/**
	 * max increasing subsequence
	 * @param arr int整型vector the array
	 * @return int整型
	 */
	int ret = 1;
	unordered_map<int, int> mp;
	int MLS(vector<int>& arr) {
		// write code here
		if (arr.empty()) {
			return 0;
		}
		for (int i = 0; i < arr.size(); i++) {
			if (mp.count(arr[i]) == 0) {
				mp[arr[i]] = 1;
				if (mp.count(arr[i] - 1))
					merge(arr[i] - 1, arr[i]);
				if (mp.count(arr[i] + 1))
					merge(arr[i], arr[i] + 1);
			}
		}
		return ret;
	}

	void merge(int less, int more) {
		int left = less - mp[less] + 1;
		int right = more + mp[more] - 1;
		int length = right - left + 1;
		if (length > ret) {
			ret = length;
		}
		mp[left] = mp[right] = length;
	}
};