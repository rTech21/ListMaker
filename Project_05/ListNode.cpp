#include "stdafx.h"
#include "ListNode.h"

ListNode::ListNode(std::string s, ListNode *p)
{
	m_listItem = s;
	next = p;
}


ListNode::~ListNode()
{
}
