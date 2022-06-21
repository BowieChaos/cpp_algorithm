#pragma once

#include "../../model/list_node.h"

class ReverseLinkList
{
public:
    ListNode *reverse_link_list(ListNode *pHead)
    {
        if (pHead == nullptr)
        {
            return nullptr;
        }

        ListNode *pre = nullptr;
        ListNode *cur = pHead;
        while (cur->next != nullptr)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        cur->next = pre;
        return cur;
    }
};
