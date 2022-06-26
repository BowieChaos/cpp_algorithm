#include <vector>
using namespace std;

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
            } else if (array[row][col]> target) {
                col--;
            } else {
                row ++;
            }
        }
        return false;
	}
};