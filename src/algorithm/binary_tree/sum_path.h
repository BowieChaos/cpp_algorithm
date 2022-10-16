#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;

// NC5 二叉树根节点到叶子节点的所有路径和
// https://www.nowcoder.com/practice/185a87cd29eb42049132aed873273e83?tpId=117&tags=&title=&difficulty=0&judgeStatus=0&rp=1&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 class Solution {
 public:
     /**
      *
      * @param root TreeNode类
      * @return int整型
      */
     int sumNumbers(TreeNode* root) {
         // write code here
		 vector<int> retVec;
		 if (root == NULL) {
			 return 0;
		 }
		 if (root->left != NULL)
			 pathTravel(root->left, root->val, retVec);
		 if (root->right != NULL)
			 pathTravel(root->right, root->val, retVec);
		 if (root->left == NULL && root->right == NULL) {
			 retVec.push_back(root->val);
		 }
		 int sum = 0;
		 for (auto i : retVec) {
			 sum += i;
		 }
		 return sum;
     }
	 void pathTravel(TreeNode* node, int count, vector<int>& retVec) {
		 // write code here
		 if (node->left == NULL && node->right == NULL) {
			int sum = count*10 + node->val;
			retVec.push_back(sum);
			return;
		 }
		 else {
			 if (node->left != NULL)
				 pathTravel(node->left, count*10 + node->val, retVec);
			 if (node->right != NULL)
				 pathTravel(node->right, count*10 + node->val, retVec);
		 }
	 }
 };