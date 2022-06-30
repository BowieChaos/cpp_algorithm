#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

// https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=295&tqId=2299105&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class Balance {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
        if (pRoot  == nullptr) {
            return true;
        }

        int left_depth = depth(pRoot->left);
        int right_depth = depth(pRoot->right);
        if (std::abs(left_depth-right_depth) > 1) {
            return false;
        }

        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);

    }

	int depth(TreeNode* node) {
		if (node == nullptr) {
			return 0;
		}
		return std::max(depth(node->left), depth(node->right)) + 1;
	}
};