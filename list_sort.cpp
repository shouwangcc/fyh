// list_sort.cpp : 定义控制台应用程序的入口点。
//createlist是生成测试用例的函数
//solution类成员函数实现了列表的排序
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode * createlist(int num)
{
	int i;
	ListNode *head;
	ListNode *p;
	if (num <= 0)
		return NULL;
	head = new ListNode(rand());
	p = head;
	for (i = 1; i < num; i++)
	{
		p->next = new ListNode(rand());
		p = p->next;
	}
	p->next = NULL;
	return head;
}
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL)
			return NULL;
		ListNode head_pre(0);
		ListNode * node_insert = head;
		ListNode *node_insert_tmp;
		ListNode *node_loop;
		while (node_insert)
		{
			node_loop = &head_pre;
			node_insert_tmp = node_insert->next;
			while (node_loop->next && node_insert->val > node_loop->next->val)
			{
				node_loop = node_loop->next;
			}
			if (node_loop->next == NULL)
			{
				node_loop->next = node_insert;
				node_insert->next = NULL;
			}
			else
			{
				ListNode *tmp;
				tmp = node_loop->next;
				node_loop->next = node_insert;
				node_insert->next = tmp;
			}
			node_insert = node_insert_tmp;	
		}
		return head_pre.next;
	}
};
void Print(ListNode *head)
{
	ListNode *p = head;
	while (p)
	{
		cout << p->val<<"    ";
		p = p->next;
	}
	cout << endl;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int num;
	cin >> num;
	ListNode *head = createlist(num);
	Print(head);
	Solution a;
	ListNode *p = a.insertionSortList(head);
	Print(p);
	return 0;
}

