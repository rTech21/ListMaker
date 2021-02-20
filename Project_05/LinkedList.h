#pragma once
class LinkedList
{
private:
	ListNode * head;
	int m_numItems = 0;		//number of item within the list
	std::string m_listName;	//name of the list

public:
	LinkedList(std::string na);
	~LinkedList();
	ListNode* getHead() { return head; }
	void addFront(std::string s);
	void addBack(std::string s);
	void removeFirst();
	void removeLast();
	void removeValue(std::string s);
	void printList();
};

