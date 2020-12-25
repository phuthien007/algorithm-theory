#include <iostream>
using namespace std;
//tao cay BTS
// khoi tao cau truc cay
typedef struct node{
	int data;
	struct node* pa, * pleft, * pright;
}Node;
typedef Node* Tree;
//khoi tao cay
void init(Tree &Root) {
	Root = NULL;
}
// tao node trong cay
Node* Create(int x) {
	Node* p = new Node;
	p->data = x;
	p->pa = p->pleft = p->pright = NULL;
	return p;
}
//them node vao cay
Node* addTree(Tree Root, int x) {
	if (Root == NULL) {
		return Create(x);
	}
	else if(Root->data < x){
		Root->pright=addTree(Root->pright, x);
		Root->pright->pa = Root;
	}
	else {
		Root->pleft=addTree(Root->pleft, x);
		Root->pleft->pa = Root;
	}
}
// in gia tri theo thu tu inorder
// sau khi in se duoc day tang dan
void inOrder(Tree Root) {
	if (Root != NULL) {
		inOrder(Root->pleft);
		cout << Root->data<<" ";
		inOrder(Root->pright);
	}
}
// tim kiem tren BST
Node* SearchBST(Tree Root, int x) {
	if (Root == NULL)
		return NULL;
	else if (Root->data == x)
	{
		return Root;
	}
	else if (Root->data > x)
		return SearchBST(Root->pleft, x);
	else if (Root->data < x)
		return SearchBST(Root->pright, x);
}
// FIND MAX
Node* findMax(Tree Root) {
	if (Root == NULL)
		return NULL;
	else {
		if (Root->pright == NULL)
			return Root;
		else
			return findMax(Root->pright);
	}
}
// FIND MIN
Node* findMin(Tree Root) {
	if (Root == NULL)
		return NULL;
	else {
		if (Root->pleft == NULL)
			return Root;
		else
			return findMin(Root->pleft);
	}
}
// PREDECESSOR: lon nhat nho hon x
Node* preDecessor(Node *x) {
	// co node trai
	if (x == NULL) return NULL;
	if (x->pleft != NULL)
	{
		return findMax(x->pleft);
	}
	//khong co node trai
	else {
		Node* p = x->pa;
		while (p != NULL && p->pright != x)
		{
			x = p;
			p = x->pa;
		}
		return p;
	}
}
// SUCCESOR : nho nhat lon hon x
Node* successor(Node* x) {
	// co node trai
	if (x == NULL) return NULL;
	if (x->pright != NULL)
	{
		return findMin(x->pright);
	}
	//khong co node trai
	else {
		Node* p = x->pa;
		while (p != NULL && p->pleft != x)
		{
			x = p;
			p = x->pa;
		}
		return p;
	}
}
Node* Delete(int x, Tree Root) {
	Node* p = SearchBST(Root, x);
	// co 4 truong hop xay ra
	// TH1: nut can xoa la nut la (khong co con trai va con pair)
	if (p->pleft == NULL && p->pright == NULL)
	{
		Node* q = p->pa;
		if (q->pleft->data == x)
			q->pleft = NULL;
		else q->pright = NULL;
	}
	// TH2: nut can xoa chi co con trai
	else if (p->pleft != NULL && p->pright == NULL) {
		p->data = p->pleft->data;
		p->pleft = NULL;
	}
	// TH3: nut can xoa chi co con phai
	else if (p->pright != NULL && p->pleft == NULL) {
		p->data = p->pright->data;
		p->pright = NULL;
	}
	// TH4: nut can xoa co ca con trai va con phai
	// co the hai truong hop la dung nut truoc va nut sau de thay the
	// trong bai nay toi se dung node ke can truoc predeccesor
	else {
		Node* q = preDecessor(p);
		p->data = q->data;
		q->data = q->pleft->data;
		q->pleft = NULL;
	}
	return Root;
}
int main() {
	Tree Root;
	init(Root);
	Root=addTree(Root,55);
	Root = addTree(Root,48);
	Root = addTree(Root,37);
	Root = addTree(Root,53);
	Root = addTree(Root,39);
	Root = addTree(Root, 49);
	Root = addTree(Root, 70);
	Root = addTree(Root, 59);
	Root = addTree(Root, 75);
	Root = addTree(Root, 57);
	Root = addTree(Root, 64);
	inOrder(Root);
	Root = Delete(55, Root);
	cout << endl;
	inOrder(Root);
	return 0;
}