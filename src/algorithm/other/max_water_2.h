#pragma once
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// NC128 接雨水问题
// https://www.nowcoder.com/practice/31c1aed01b394f0b8b7734de0324e00f?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class MaxWater2 {
public:
	/**
	 * max water
	 * @param arr int整型vector the array
	 * @return long长整型
	 */
	long long maxWater(vector<int>& arr) {
		// write code here
		if (arr.size() <= 2) {
			return 0;
		}
		int left = 0;
		int right = arr.size() - 1;
		int left_board = 0;
		int right_board = arr.size() - 1;
		long long ret = 0;
		while (left < right) {
			while (left < right && arr[left_board] < arr[right_board]) {
				left++;
				if (arr[left] < arr[left_board]) {
					ret += arr[left_board] - arr[left];
				} else {
					left_board = left;
				}
			}

			while (left < right && arr[right_board] <= arr[left_board]) {
				right--;
				if (arr[right] < arr[right_board]) {
					ret += arr[right_board] - arr[right];
				} else {
					right_board = right;
				}
			}
		}
		return ret;
	}
};