#include <iostream>
#include <stack>
#include <string>
#include  <vector>
using namespace std;
typedef struct node {
	int data;
	struct node* pnext;
}Node;
typedef struct {
	Node* phead;
}Stack;
void init(Stack& s)
{
	s.phead == NULL;
}
bool isEmpty(Stack s) {
	if (s.phead == NULL)
		return true;
	return false;
}
void push(Stack s, int x) {
	Node* p = new Node;
	p->data = x;
	p->pnext = NULL;
	if (isEmpty(s) == true)
		s.phead = p;
	else {
		p->pnext = s.phead;
		s.phead = p;
	}
}
//gop pop voi top, khoong huy du lieu
int pop(Stack s) {
	return s.phead->data;
}
int size(Stack s) {
	int res = 0;
	while (isEmpty(s) != true)
		res += 1;
	return res;
}
int main()
{
	return 0;
}