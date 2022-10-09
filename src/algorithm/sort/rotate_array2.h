#include <vector>

using namespace std;

// NC48 在旋转过的有序数组中寻找目标值
// https://www.nowcoder.com/practice/87c0e7abcbda41e7963660fa7d020995?tpId=117&tqId=37744&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param nums int整型vector
	 * @param target int整型
	 * @return int整型
	 */
	int search(vector<int>& nums, int target) {
		// write code here
		int minIndex = getMin(nums);
		if (minIndex == 0) {
			return binarySearch(nums, 0, nums.size() - 1, target);
		}
		if (nums[0] > target) {
			return binarySearch(nums, minIndex, nums.size() - 1, target);
		} else {
			return binarySearch(nums, 0, minIndex - 1, target);
		}
	}
	int binarySearch(vector<int>& nums, int left, int right, int target) {
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			else if (nums[mid] > target)
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}

	int getMin(vector<int>& nums) {
		// write code here
		int left = 0;
		int right = nums.size() - 1;
		int ret = left;
		while (nums[left] > nums[right]) {
			if (right - left == 1) {
				ret = right;
				break;
			}
			int mid = (left + right) / 2;
			if (nums[mid] > nums[left]) {
				left = mid;
			} else {
				right = mid;
			}
		}

		return ret;
	}
};