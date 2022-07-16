#include <vector>

using namespace std;

// https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=295&tqId=23260&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class Inverse {
public:
	int ret = 0;
	int InversePairs(vector<int> data) {
		if (data.size() <= 1) {
			return 0;
		}
		MergeSort(data, 0, data.size() - 1);
		return ret;
	}

	void MergeSort(vector<int>& data, int left, int right) {
		int mid = (left + right) / 2;
		if (left < right) {
			MergeSort(data, left, mid);
			MergeSort(data, mid + 1, right);
			Merge(data, left, mid, right);
		}
	}

	void Merge(vector<int>& data, int left, int mid, int right) {
		vector<int> tmp_vec(right - left + 1);

		int l = left;
		int r = mid + 1;
		int tmp_i = 0;
		while (l <= mid && r <= right) {
			if (data[l] <= data[r]) {
				tmp_vec[tmp_i++] = data[l++];
			} else {
				ret += mid - l + 1;
				ret %= 1000000007;
				tmp_vec[tmp_i++] = data[r++];
			}
		}
		while (l <= mid) {
			tmp_vec[tmp_i++] = data[l++];
		}
		while (r <= right) {
			tmp_vec[tmp_i++] = data[r++];
		}
		int j = left;
		for (int i : tmp_vec) {
			data[j++] = i;
		}
	}
};