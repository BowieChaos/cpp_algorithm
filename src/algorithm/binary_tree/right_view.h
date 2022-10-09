#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;


// NC136 输出二叉树的右视图
// https://www.nowcoder.com/practice/c9480213597e45f4807880c763ddd5f0?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

class Right {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // write code here
        vector<int> ret_vec;
        if (xianxu.empty() || zhongxu.empty() || xianxu.size() !=  zhongxu.size()) {
            return ret_vec;
        }
        TreeNode* root = reConstructBinaryTree(xianxu, zhongxu);
        auto vecs = levelOrder(root);
        for (size_t i = 0;i<vecs.size();i++) {
            ret_vec.emplace_back(vecs[i][vecs[i].size()-1]);
        }
        return ret_vec;
    }


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

    vector<vector<int>> levelOrder(TreeNode* root) {
		// write code here
		vector<vector<int>> ret_vec;
		if (root == nullptr) {
			return ret_vec;
		}

		queue<TreeNode*> que_left;
		queue<TreeNode*> que_right;
		que_left.emplace(root);

		while (!que_left.empty()) {
			vector<int> tmp_vec;
			while (!que_left.empty()) {
				TreeNode* tmp_node = que_left.front();
				tmp_vec.emplace_back(tmp_node->val);
				que_left.pop();
				if (tmp_node->left != nullptr) {
					que_right.push(tmp_node->left);
				}
				if (tmp_node->right != nullptr) {
					que_right.push(tmp_node->right);
				}
			}
			ret_vec.emplace_back(tmp_vec);
			swap(que_left,que_right);
		}
		return ret_vec;
	}
};