#pragma once

#include "../../model/b_tree.h"
#include <queue>
#include <stack>
#include <vector>
using namespace std;

// NC81 二叉搜索树的第k个节点
// https://www.nowcoder.com/practice/57aa0bab91884a10b5136ca2c087f8ff?tpId=117&tqId=37783&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3FjudgeStatus%3D3%26page%3D1%26pageSize%3D50%26search%3D%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=3&tags=&title=

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 *
	 * @param proot TreeNode类
	 * @param k int整型
	 * @return int整型
	 */
	int KthNode(TreeNode* proot, int k) {
		// write code here
		if (proot == nullptr || k == 0) {
			return -1;
		}

		TreeNode* theNode = proot;
		stack<TreeNode*> stk;
		vector<int> vec;
		while (theNode != nullptr || !stk.empty()) {
			if (theNode != nullptr) {
				stk.push(theNode);
				theNode = theNode->left;
			} else {
				theNode = stk.top();
				vec.push_back(theNode->val);
				stk.pop();
				theNode = theNode->right;
			}
		}
		if (k <= vec.size()) {
			return vec[k - 1];
		}
		return -1;
	}
};