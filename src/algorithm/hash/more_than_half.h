#pragma once;
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class MoreThanHalf {
public:
	/*     
    加入数组中存在众数，那么众数一定大于数组的长度的一半。
	思想就是：如果两个数不相等，就消去这两个数，最坏情况下，每次消去一个众数和一个非众数，那么如果存在众数，最后留下的数肯定是众数。

	具体做法：

	初始化：候选人cond = -1， 候选人的投票次数cnt = 0
	遍历数组，如果cnt=0， 表示没有候选人，则选取当前数为候选人，++cnt
	否则，如果cnt > 0, 表示有候选人，如果当前数=cond，则++cnt，否则--cnt
	直到数组遍历完毕，最后检查cond是否为众数 */
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int candi = -1;
		int count = 0;
		for (size_t i = 0; i < numbers.size(); i++) {
			if (count == 0) {
				candi = numbers[i];
				count++;
			} else {
				if (numbers[i] != candi) {
					count--;
				} else {
					count++;
				}
			}
		}
		return candi;
	}
};