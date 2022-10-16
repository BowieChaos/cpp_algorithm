#include <vector>

using namespace std;
// NC105 二分查找-II
// https://www.nowcoder.com/practice/4f470d1d3b734f8aaf2afb014185b395?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 如果目标值存在返回下标，否则返回 -1
	 * @param nums int整型vector
	 * @param target int整型
	 * @return int整型
	 */
	int search(vector<int>& nums, int target) {
		// write code here
		int left = 0;
		int right = nums.size() - 1;
		int retIndex = 0;
		bool find = false;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target) {
				find = true;
				retIndex = mid;
				break;
			} else if (nums[mid] < target) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		if (!find)
			return -1;
		while (retIndex > 0 && nums[retIndex - 1] == nums[retIndex]) {
			retIndex--;
		}
		return retIndex;
	}
};