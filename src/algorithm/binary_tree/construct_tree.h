#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

// NC12 重建二叉树
// https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=295&tqId=23282&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

class Construct {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty() || pre.size() != vin.size()) {
			return nullptr;
		}
		return constructCore(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
	}

	TreeNode* constructCore(vector<int>& pre, vector<int>& vin, int pre_start,
	                        int pre_end, int vin_start, int vin_end) {

		int root_val = pre[pre_start];
		TreeNode* root = new TreeNode(root_val);

		if (pre_start == pre_end && vin_start == vin_end) {
			return root;
		}

		int index = vin_start;
		while (index < vin_end && vin[index] != root_val) {
			index++;
		}
		int left_len = index - vin_start;

		if (left_len > 0) {
			root->left =
			    constructCore(pre, vin, pre_start + 1, pre_start + left_len,
			                  vin_start, vin_start + left_len - 1);
		}
		if (index < vin_end) {
			root->right = constructCore(pre, vin, pre_start + left_len + 1,
			                            pre_end, index + 1, vin_end);
		}

		return root;
	}

};