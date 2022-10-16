#include <vector>

using namespace std;

// NC107 寻找峰值
// https://www.nowcoder.com/practice/fcf87540c4f347bcb4cf720b5b350c76?tpId=117&tqId=37831&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=


class FindPeak {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param nums int整型vector
	 * @return int整型
	 */
	int findPeakElement(vector<int>& nums) {
		// write code here
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
            if (nums[mid] > nums[mid+1]) {
                right = mid;
            } else {
                left = mid+1;
            }
		}
        return right;
	}
};