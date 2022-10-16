#include <vector>
using namespace std;

// NC29 二维数组中的查找
// https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117
class MatrixSearch {
public:
	bool Find(int target, vector<vector<int> > array) {
		if (array.empty() || array[0].empty()) {
			return false;
		}

		int rows = array.size();
		int cols = array[0].size();
		int col = cols - 1;
		int row = 0;
		while (row < rows && col >= 0) {
			if (array[row][col] == target) {
				return true;
			} else if (array[row][col] > target) {
				col--;
			} else {
				row++;
			}
		}
		return false;
	}
};