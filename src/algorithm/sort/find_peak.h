#include <vector>

using namespace std;

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