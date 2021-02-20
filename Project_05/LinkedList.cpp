#include "stdafx.h"
#include "ListNode.h"
#include "LinkedList.h"


LinkedList::LinkedList(std::string name)
{
	head = NULL;
	m_listName = name;
}

LinkedList::~LinkedList()
{
	while (head != NULL)
	{
		ListNode *p = head;
		head = head->next;
		delete p;
	}
}

//adds a given value to the front of the linked list
void LinkedList::addFront(std::string s)
{
	head = new ListNode(s, head);
	m_numItems++;
}

//adds a given value to the end of the linked list
void LinkedList::addBack(std::string s)
{
	//new node that will be added
	ListNode *newNode = new ListNode(s, NULL);

	ListNode *p = head;

	//if head is empty, make newNode the head
	if (p == NULL)
	{
		head = newNode;
		m_numItems++;
		return;
	}
	//else traverse the list to the last node
	while (p->next != NULL)
	{
		p = p->next;
	}

	//add newNode to the last node
	p->next = newNode;
	m_numItems++;
	return;
}

//prints the list
void LinkedList::printList()
{
	ListNode *p = head;
	std::cout << m_listName << " List: " << std::endl;
	for (int i(0); i < m_numItems; i++)
	{
		std::cout << i + 1 << ": " << p->m_listItem << std::endl;
		p = p->next;
	}	
}

//remove the first value from the linked list
void LinkedList::removeFirst()
{
	ListNode *garbage;		//used to delete nodes

	if (head == NULL)
		return;

	garbage = head;
	head = head->next;
	delete garbage;
	m_numItems--;
	return;
}

//remove the last value from the linked list
void LinkedList::removeLast()
{
	ListNode *garbage;		//used to delte nodes

	if (head == NULL)
		return;

	//if the head is the only value in list, delete the head
	if (head->next == NULL)
	{
		garbage = head;
		delete garbage;
		m_numItems--;
		return;
	}


	ListNode *p = head;

	//else traverse the list to the second to last node
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	//delete the last node
	garbage = p->next;
	delete garbage;
	p->next = NULL;
	m_numItems--;
	return;
}

//remove a given item from the linked list
void LinkedList::removeValue(std::string s)
{
	ListNode *garbage;		//used to delete nodes

	if (head == NULL)
		return;

	//is x in the head?
	if (head->m_listItem == s)
	{
		garbage = head;
		head = head->next;
		delete garbage;
		m_numItems--;
		return;
	}

	//x not in the head, find it
	ListNode *p = head;
	while (p->next != NULL && p->next->m_listItem != s)
		p = p->next;

	//p->next == NULL or p->next->value is x
	if (p->next == NULL)
		return;			//did not find the value
	else
	{
		//delete the x
		garbage = p->next;
		p->next = garbage->next;
		delete garbage;
		m_numItems--;
	}
}