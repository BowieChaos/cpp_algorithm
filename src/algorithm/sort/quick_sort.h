#pragma once

#include <vector>

using namespace std;

// https://www.nowcoder.com/practice/2baf799ea0594abd974d37139de27896?tpId=117&tqId=37851&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 * 将给定数组排序
	 * @param arr int整型vector 待排序的数组
	 * @return int整型vector
	 */
	vector<int> MySort(vector<int>& arr) {
		// write code here
		QuickSort(arr, 0, arr.size() - 1);
		return arr;
	}

	void QuickSort(vector<int>& arr, int left, int right) {
		if (left >= right) {
			return;
		}

		int pivot = arr[left];
		int s = left;
		while (left < right) {
			while (left < right && arr[right] < pivot) {
				right--;
			}

			while (left < right && arr[left] > pivot) {
				left++;
			}
			swap(arr[left], arr[right]);
		}
		swap(arr[s], arr[left]);
		QuickSort(arr, s, left - 1);
		QuickSort(arr, left + 1, right);
		return;
	}
};