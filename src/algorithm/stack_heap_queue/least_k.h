#pragma once
#include <limits.h>
#include <stack>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=295&tqId=23458&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class LeaseK {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k >= input.size()) {
			return input;
		}
		vector<int> empty;

		if (k <= 0) {
			return empty;
		}
		int start = 0;
		int end = input.size() - 1;
		int index = Partition(input, start, end);
		while (index != k) {
			if (index < k) {
				index = Partition(input, index + 1, end);
			} else {
				index = Partition(input, start, end - 1);
			}
		}
		vector<int> ret_vec(input.begin(), input.begin() + k);
		return ret_vec;
	}

	int Partition(vector<int>& nums, int start, int end) {

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