// problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
// https://www.geeksforgeeks.org/reverse-a-linked-list-in-groups-of-given-size/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

Node* reverse(Node* head, int k)
{
	// base case
	if (!head)
		return NULL;
	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 0;

	/*reverse first k nodes of the linked list */
	while (current != NULL && count < k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	/* next is now a pointer to (k+1)th node
	Recursively call for the list starting from current.
	And make rest of the list as next of first node */
	if (next != NULL)
		head->next = reverse(next, k);

	/* prev is new head of the input list */
	return prev;
}


void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}


int main()
{

	Node* head = NULL;

	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	cout << "Given linked list \n";
	printList(head);
	head = reverse(head, 3);

	cout << "\nReversed Linked list \n";
	printList(head);

	return (0);
}

// Approach
// 1.Function definition: reverseKGroup(head, k)
// 2.Base case:
//      If the head is NULL (empty list), return NULL to indicate an empty list.
// 3.Check if the current group has enough nodes to reverse:
//      Traverse k nodes from the head and count the number of nodes in the current group.
//      If the count is less than k, it means the current group does not have enough nodes to reverse, so return the head of the group as it is.
// 4.Initialize three pointers:
//      prev: Points to the previous node (initially set to NULL).
//      next: Points to the next node (initially set to NULL).
//      curr: Points to the current node (initially set to head).
// 5.Reverse the current group of k nodes using a while loop:
//      Inside the loop, do the following k times:
//          Update next to curr->next.
//          Set curr->next to prev.
//          Move prev and curr to their respective next nodes.
//      After the loop, the current group of k nodes is reversed.
// 6.Check if there are more nodes left in the list (next != NULL):
//      If there are more nodes, make a recursive call to reverseKGroup with next as the new head and k as the group size.
//      This handles the remaining linked list and continues reversing groups until the end.
// 7. Return the prev pointer:
//      The prev pointer now points to the new head of the reversed list.

/*
Complexity
Time complexity:
O(n)
Space complexity:
O(n)*/