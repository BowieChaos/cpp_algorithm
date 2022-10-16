#pragma once

#include "../../model/b_tree.h"
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// NC60 判断一棵二叉树是否为搜索二叉树和完全二叉树
// https://www.nowcoder.com/practice/f31fc6d3caf24e7f8b4deb5cd9b5fa97?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

class Solution {
public:
	/**
	 *
	 * @param root TreeNode类 the root
	 * @return bool布尔型vector
	 */
	vector<bool> judgeIt(TreeNode* root) {
		// write code here
		vector<bool> ret;
		ret.push_back(judgeSearch(root));
		ret.push_back(judgeFull(root));
		return ret;
	}
	bool judgeSearch(TreeNode* root) {
		if (root == NULL)
			return true;
		stack<TreeNode*> s;
		TreeNode* curNode = root;
		vector<int> ret;
		while (!s.empty() || curNode != NULL) {
			if (curNode != NULL) {
				s.push(curNode);
				curNode = curNode->left;
			} else {
				auto tmp = s.top();
				ret.push_back(tmp->val);
				s.pop();
				curNode = tmp->right;
			}
		}
		if (is_sorted(ret.begin(), ret.end()))
			return true;
		else
			return false;
	}
	bool judgeFull(TreeNode* root) {
		if (root == NULL)
			return true;
		queue<TreeNode*> Q;
		stack<TreeNode*> S;
		Q.push(root);
		while (!Q.empty()) {
			auto tmp = Q.front();
			Q.pop();
			S.push(tmp);
			if (tmp != NULL) {
				Q.push(tmp->left);
				Q.push(tmp->right);
			}
		}
		while (!S.empty()) {
			auto tmp = S.top();
			if (tmp != NULL) {
				break;
			} else {
				S.pop();
			}
		}
		while (!S.empty()) {
			auto tmp = S.top();
			if (tmp == NULL)
				return false;
			else {
				S.pop();
			}
		}
		return true;
	}
};