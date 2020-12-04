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
	Node* ptail;
}Queue;
void init(Queue &q)
{
	q.phead = q.ptail = NULL;
}
bool isEmpty(Queue q) {
	if (q.phead == NULL)
		return true;
	return false;
}
void enQueue(Queue q, int x) {
	Node* p = new Node;
	p->data = x;
	p->pnext = NULL;
	if (isEmpty(q) == true)
		q.phead = q.ptail=p;
	else {
		q.ptail->pnext = p;
		q.ptail = p;
	}
}
//gop pop voi top, khoong huy du lieu
int deQueue(Queue q) {
	return q.phead->data;
}
int size(Queue q) {
	int res = 0;
	while (isEmpty(q) != true)
		res += 1;
	return res;
}
int main()
{
	return 0;
}