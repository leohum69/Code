// C++ program to get intersection point of two linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node {
public:
	int data;
	Node* next;
};

/* function to get the intersection point of two linked
lists head1 and head2 */
Node* getIntesectionNode(Node* head1, Node* head2)
{
	Node * curr1 = head1;
    Node * curr2 = head2;
    while(curr1){
        while(curr2){
            if(curr1 == curr2){
                return curr1;
            }
            curr2 = curr2->next;
        }
        curr2 = head2;
        curr1 = curr1->next;
    }
	
	return NULL;
}

// Driver Code
int main()
{
	/*
		Create two linked lists

		1st 10->15->30
		2nd 3->6->9->15->30
		

		15 is the intersection point
	*/

	Node* newNode;

	// Addition of nodes in the First Linked List
	Node* head1 = new Node();
	head1->data = 10;
	
	// Addition of nodes in the Second Linked List
	Node* head2 = new Node();
	head2->data = 3;

	newNode = new Node();
	newNode->data = 6;
	head2->next = newNode;

	newNode = new Node();
	newNode->data = 9;
	head2->next->next = newNode;

	newNode = new Node();
	newNode->data = 15;
	head1->next = newNode;
	head2->next->next->next = newNode;

	newNode = new Node();
	newNode->data = 30;
	head1->next->next = newNode;

	head1->next->next->next = NULL;

	Node* intersectionPoint
		= getIntesectionNode(head1, head2);

	if (!intersectionPoint)
		cout << " No Intersection Point \n";
	else
		cout << "Intersection Point: "
			<< intersectionPoint->data << endl;
}