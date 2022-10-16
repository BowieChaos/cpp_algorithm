#pragma once
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

// NC26 括号生成
// https://www.nowcoder.com/practice/c9addb265cdf4cdd92c092c655d164ca?tpId=295&tqId=1008753&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class Parethesis {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param n int整型
	 * @return string字符串vector
	 */
    
	vector<string> generateParenthesis(int n) {
		// write code here
		vector<string> ret_vec;
		if (n == 0) {
			return ret_vec;
		}

		string s;
		traverse(s, 0, 0, n, ret_vec);
		return ret_vec;
	}

	void traverse(string& s, int left, int right, int n,
	              vector<string>& ret_vec) {
		if (left == right && left == n) {
			ret_vec.emplace_back(s);
			return;
		}

		if (left < n) {
			s.push_back('(');
			traverse(s, left + 1, right, n, ret_vec);
            s.pop_back();
		}

		if (right < left) {
			s.push_back(')');
			traverse(s, left, right + 1, n, ret_vec);
            s.pop_back();
		}
	}
};