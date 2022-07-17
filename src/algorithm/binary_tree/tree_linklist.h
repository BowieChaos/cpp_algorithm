#pragma once

#include "../../model/b_tree.h"
#include <stack>
#include <vector>
using namespace std;
// https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295

class TreeLinkList {
public:
    TreeNode* preNode;
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree==nullptr) {
            return nullptr;
        }
        TreeNode* p = pRootOfTree;
        while (p->left!=nullptr) {
            p = p->left;
        }
        inOrder(pRootOfTree);
        return p;

    }

    void inOrder (TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left);
        node->left = preNode;
        if (preNode !=nullptr) {
            preNode->right = node;
        }
        preNode = node;
        inOrder(node->right);
        return;
    }
};