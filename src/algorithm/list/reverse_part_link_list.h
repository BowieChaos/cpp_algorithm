#pragma once

#include "../../model/list_node.h"

class ReverseBetween
{
public:
    /**
     *
     * @param head ListNode类
     * @param m int整型
     * @param n int整型
     * @return ListNode类
     */
    ListNode *reverse_between(ListNode *head, int m, int n)
    {
        if (head == nullptr)
        {
            return head;
        }

        ListNode *pre = new ListNode(-1);
        ListNode *ret = new ListNode(-1);
        ret->next = head;
        pre->next = head;
        ListNode *cur = head;

        int count = m;
        while (cur != nullptr && count > 1)
        {
            count--;
            pre = cur;
            cur = cur->next;
        }

        ListNode *p_next = head;
        count = n;
        while (count >= 1)
        {
            count--;
            p_next = p_next->next;
        }

        ListNode *tmp_pre = p_next;
        int i = 0;
        while (cur->next != nullptr && m + i < n)
        {
            auto tmp_next = cur->next;
            cur->next = tmp_pre;
            tmp_pre = cur;
            cur = tmp_next;
            i++;
        }
        cur->next = tmp_pre;
        pre->next = cur;

        if (m == 1)
        {
            return cur;
        }
        return ret->next;
    }
};