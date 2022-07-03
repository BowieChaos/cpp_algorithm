#pragma once
#include <limits.h>
#include <stacK>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/e016ad9b7f0b45048c58a9f27ba618bf?tpId=295&tqId=23458&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranKing&sourceUrl=%2Fexam%2Foj

class FindK {
public:
	int findKth(vector<int> a, int n, int K) {
		if (K >= a.size()) {
			return -1;
		}

		if (K <= 0) {
			return -1;
		}
		int start = 0;
		int end = a.size() - 1;
		int index = Partition(a, start, end);
		while (index != n - K) {
			if (index < n - K) {
				index = Partition(a, index + 1, end);
			} else {
				index = Partition(a, start, end - 1);
			}
		}
		return a[index];
	}

	int Partition(vector<int>& nums, int start, int end) {
		// 这行是减少耗时的精髓
		swap(nums[start], nums[(start + end) / 2]);

		int left = start;
		int right = end;
		int pivot = nums[start];
		while (left < right) {
			while (left < right && nums[right] >= pivot) {
				right--;
			}

			while (left < right && nums[left] <= pivot) {
				left++;
			}
			swap(nums[left], nums[right]);
		}
		swap(nums[left], nums[start]);
		return left;
	}
};