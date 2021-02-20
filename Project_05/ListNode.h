#pragma once
class ListNode
{
private:
	std::string m_listItem;
	ListNode *next;
	friend class LinkedList;		//InventoryList has friend status

public:
	ListNode(std::string s, ListNode *p);
	~ListNode();
	std::string getItem() { return m_listItem; }
	ListNode* getNext() { return next; }
};
