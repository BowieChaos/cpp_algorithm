#pragma once

#include "../../model/list_node.h"

// NC2 重排链表
// https://www.nowcoder.com/practice/3d281dc0b3704347846a110bf561ef6b?tpId=117&tqId=37712&rp=1&ru=/exam/oj&qru=/exam/oj&sourceUrl=%2Fexam%2Foj%3Fpage%3D2%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D117&difficulty=undefined&judgeStatus=undefined&tags=&title=
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == nullptr)
			return;
		int length = 0;
		auto countH = head;
		while (countH != nullptr) {
			countH = countH->next;
			length++;
		}
		if (length == 1)
			return;
		int mid = length / 2 + 1;
		auto pHead = head;
		auto pCur = head;
		int count = 1;
		while (count < mid) {
			pCur = pCur->next;
			count++;
		}
		auto pPre = pCur;
		pCur = pCur->next;
		pPre->next = nullptr;
		while (pCur != nullptr) {
			auto next = pCur->next;
			pCur->next = pPre;
			pPre = pCur;
			pCur = next;
		}
		count = 1;
		auto pReset = head;
		while (count < mid - 1) {
			pReset = pReset->next;
			count++;
		}
		pReset->next = nullptr;

		ListNode* mergeHead = pHead;
		pHead = pHead->next;
		count = 1;
		while (pHead != nullptr && pPre != nullptr) {

			if (count % 2 == 1) {
				mergeHead->next = pPre;
				pPre = pPre->next;
				mergeHead = mergeHead->next;
			} else {
				mergeHead->next = pHead;
				pHead = pHead->next;
				mergeHead = mergeHead->next;
			}
			count++;
		}
		if (pHead != nullptr)
			mergeHead->next = pHead;
		if (pPre != nullptr)
			mergeHead->next = pPre;

		return;
	}
};