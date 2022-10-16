#pragma once

#include "../../model/list_node.h"

// NC133 链表的奇偶重排
// https://www.nowcoder.com/practice/02bf49ea45cd486daa031614f9bd6fc3?tpId=295&tqId=1008769&ru=%2Fexam%2Foj&qru=%2Fta%2Fformat-top101%2Fquestion-ranking&sourceUrl=%2Fexam%2Foj

class OddEvenList {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }

        ListNode* odd_head = head;
        ListNode* even_head = head->next;
        ListNode* even_head_1 = head->next;

        while (even_head != nullptr && even_head->next!=nullptr) {
            odd_head->next = even_head->next;
            odd_head = odd_head->next;
            even_head->next = odd_head->next;
            even_head = even_head->next;
        }
        odd_head->next = even_head_1;
        return head;
    }
};