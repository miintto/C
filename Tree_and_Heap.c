#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)


typedef struct Node {		////////// Ʈ�� ��� ���� ���� //////////
	int key;
	struct Node *right;
	struct Node *left;
}Node;

void insert_node(Node**proot, Node*new) {		////////// ��� ���� �Լ� //////////
	Node*p = NULL;
	Node*q = NULL;
	p = *proot;		// Ž���� ������

	if (*proot == NULL) // �����͸� ó�� �޴� ���
	{
		new->right = NULL;
		new->left = NULL;
		*proot = new;
	}
	else {				// �����Ͱ� �̹� �Էµ� ���
		while (p != NULL) {		// ��ġ �Ǻ�
			if (new->key > p->key) {
				q = p;
				p = p->right;
			}
			else {
				q = p;
				p = p->left;
			}
		}

		// ��ġ �Ǻ� �� ũ�⸦ ���Ͽ� �� ��ġ�� ����.
		if (new->key > q->key) {
			new->right = NULL;
			new->left = NULL;
			q->right = new;
		}
		else {
			new->right = NULL;
			new->left = NULL;
			q->left = new;
		}
	}
}

void delete_node(Node**proot, int num) {		////////// ��� ���� �Լ� //////////
	Node*p = NULL;
	Node*q = NULL;
	Node*r = NULL;
	p = *proot;		// Ž���� ������


	while (p->key != num) {		// ��ġ Ž��
		if (num > p->key) {
			q = p;
			p = p->right;
		}
		else {
			q = p;
			p = p->left;
		}
	}		// Ž�� �Ŀ� p�� ������ ���, q�� �����ϱ� �� ���


	if (p->right==NULL && p->left == NULL) {	// �ڽ� ��尡 ���� ���
		if (q->right->key == num)
		{
			q->right = NULL;
		}
		else {
			q->left = NULL;
		}
	}
	else if (p->right == NULL && p->left != NULL) {	// Left�� ������ ���
		r = p;
		q = p;
		p = p->left;
		while (p->right != NULL) {
			r = p;
			p = p->right;
		}
		q->key = p->key;
		if (p->left == NULL) {
			r->right = NULL;
		}
		else
		{
			r->right = p->left;
		}
	}
	else {		// Right�� �ִ°�� Right��常 ���
		r = p;
		q = p;
		p = p->right;
		while (p->left != NULL) {
			r = p;
			p = p->left;
		}
		q->key = p->key;
		if (p->right == NULL) {
			r->left = NULL;
		}
		else
		{
			r->left = p->right;
		}
	}
}

void display_endnode(Node *root)
{
	if (root != NULL)
	{
		display_endnode(root->left);
		if (root->left == NULL && root->right == NULL) {
			printf("%d ", root->key);
		}
		display_endnode(root->right);
	}
}

int num(Node *root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return num(root->left) + num(root->right);
}



typedef struct{
	int heap[200];
	int heap_size;
}HeapType;

init(HeapType*h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType*HPT, int num) {
	int i;
	i = ++(HPT->heap_size);

	while ((i != 1) && (num < HPT->heap[(i+1)/3])) {
		HPT->heap[i] = HPT->heap[(i+1)/3];
		i = (i+1)/3;
	}
	HPT->heap[i] = num; //����
}

int delete_max_heap(HeapType*HPT) {
	int parent, child, out, temp;

	out = HPT->heap[1];
	temp = HPT->heap[(HPT->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= HPT->heap_size) {
		if ((child < HPT->heap_size)) {
			if (HPT->heap[child] > HPT->heap[child + 1] && HPT->heap[child + 1] < HPT->heap[child + 2])  // �� �ڽ� �� ���� ���������� child �̵�
				child++;
			else if (HPT->heap[child] > HPT->heap[child + 2] && HPT->heap[child] > HPT->heap[child + 2])
				child = child + 2;
		}
		if (temp <= HPT->heap[child])  break;	// ������ �Ϸ�Ǹ� ������ ����

		HPT->heap[parent] = HPT->heap[child];	// �Ʒ� �ٷ� �̵�
		parent = child;
		child  = 3*child - 1;
	}

	HPT->heap[parent] = temp;
	return out; // �� ÷�� �ִ� ���� ���
}



int main()		////////////////////////////// ���� �Լ� //////////////////////////////
{
	int i;
	int A[15] = {10, 15, 8, 18, 7, 1, 5, 9, 17, 11, 12, 30, 25, 6, 32};
	HeapType HPT;
	Node *new = NULL;		// ��� ������
	Node *proot = NULL;		// root ������

	
	printf("                      1. Tree ����� \n\n");
	
	for (i = 0; i < 15; i++) {
		new = (Node*)malloc(sizeof(Node));		// �� ��� ������ ����
		new->key = A[i];						// �� ��� ������ ����
		insert_node(&proot, new);				// ������ ��ġ�� ����
	}

	delete_node(&proot, 9);		// ����
	delete_node(&proot, 7);
	delete_node(&proot, 10);


	// �ܸ���� ���
	printf("�ܸ� ��� : ");
	display_endnode(proot);
	printf("\n");

	// ��� ���� ���
	printf("�ܸ������ ���� : %d��", num(proot));
	printf("\n\n\n");
	


	printf("                      2. �� ���� �ϱ�\n\n");
	printf("�������� ���� : ");

	init(&HPT);		// �ʱ�ȭ

	for (i = 0; i < 15; i++) {
		insert_max_heap(&HPT, A[i]);	// ��� ����
	}

	for (i = 0; i < 15; i++) {		// �� ���� �����ϸ� ���
		printf("%d ", delete_max_heap(&HPT));
	}
	

	system("PAUSE");
	return 0;
}

