#include <vector>

using namespace std;
// https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=295&tqId=23269&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class RotateArray {
public:
	/* 	int minNumberInRotateArray(vector<int> rotateArray) {
	        int len = rotateArray.size();
	        int left = 0;
	        int right = len - 1;
	        while ((right - left) > 1) {
	            int mid = (right + left) / 2;

	            if (rotateArray[left] == rotateArray[mid] &&
	                rotateArray[mid] == rotateArray[right]) {
	                return findMin(rotateArray, left, right);
	            }

	            if (rotateArray[mid] >= rotateArray[left]) {
	                left = mid;
	            } else {
	                right = mid;
	            }
	        }
	        return rotateArray[right];
	    }

	    int findMin(vector<int> rotateArray, int left, int right) {
	        int ret = rotateArray[left];
	        for (int j = left + 1; j <= right; j++) {
	            if (rotateArray[j] < ret) {
	                ret = rotateArray[j];
	            }
	        }
	        return ret;
	    } */
	int minNumberInRotateArray(vector<int> rotateArray) {
		int left = 0;
		int right = rotateArray.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (rotateArray[mid] > rotateArray[right]) {
				left = mid + 1;
			} else if (rotateArray[mid] < rotateArray[right]) {
                right = mid;
            } else {
                right--;
            }
		}
        return rotateArray[left];
	}
};