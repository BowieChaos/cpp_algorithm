#pragma once
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/345e2ed5f81d4017bbb8cc6055b0b711?tpId=295&tqId=2188893&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class ThreeSum {
public:
	vector<vector<int>> threeSum(vector<int>& num) {
		vector<vector<int>> ret_vec;
		if (num.size() < 3)
			return ret_vec;
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size() - 2; i++) {
			if (num[i] == num[i - 1] && i > 0)
				continue;
			int left = i + 1, right = num.size() - 1;
			while (left < right) {
				if (num[left] + num[right] ==
				    -num[i]) { //若指针i 加指针j 等于当前数x 则答案为x 和指针i
					           //与j 的三元组。

					ret_vec.push_back({num[i], num[left], num[right]});
					while (num[left] == num[left + 1] && left + 1 < right)
						left++;
					while (num[right] == num[right - 1] && right - 1 > left)
						right--;
					left++, right--;
				} else if (num[left] + num[right] >
				           -num[i]) { //若指针left加指针r
					                  //大于当前数-num[i]则指针r
					                  //--，
					right--;
				} else
					left++; //若指针left加指针r 小于当前数-num[i]则指针l++，
			}
		}
		return ret_vec;
	}
};
