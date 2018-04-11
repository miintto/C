#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996)


typedef struct Todo_list {
	char Todo[50];
	int Start;
	int Run;
	struct Todo_list *link;
}Todo_list;

void insert_node (Todo_list**phead, Todo_list*p, Todo_list*new_node) {
	if (*phead == NULL) // �����͸� ó�� �޴� ���
	{
		new_node->link = NULL;
		*phead = new_node;
	}
	else if(p == NULL) //p�� NULL�̸� ù��° ���� ����
	{
		new_node->link = *phead;
		*phead = new_node;
	}
	else //p ������ ����
	{
		new_node->link = p->link;
		p->link = new_node;
	}
}

Todo_list*search(Todo_list*head, int *x, int*y) {
	Todo_list*p=NULL;

	p = head;
	if (head == NULL) {		// �����Ͱ� ���� ���
		return NULL;
	}
	else if (p->Start >= *x && p->Run >= *y) {	// ���� ���� ������ �� ������
		return NULL;
	}
	else{
		while (p->link != NULL) {
			if ((p->Start)*10000+(p->Run) <= (*x)*10000+*y & (*x)*10000+*y <= (p->link->Start)*10000+(p->link->Run)) {
				return p;
				break;
			}
			p = p->link;
		}
		return p;
	}
}

void search2 (Todo_list *head, Todo_list **prev, Todo_list **removed, int x) {
	Todo_list *p1, *p2;
	p1 = head;
	p2 = NULL;
	
	while (p1 != NULL) {
		if (p1->Start == x) {// Ž������
			*prev = p2;
			*removed = p1;
			return;
		}
		p2 = p1;
		p1 = p1->link;
	}
	return; // Ž�������ϰ��NULL ��ȯ
}

void remove_node(Todo_list**phead, Todo_list*p, Todo_list*removed)
{
	if (p == NULL)					// ���� ��尡 ���� ó�� ����� ���
		*phead = (*phead)->link;
	else {							// ���� ��尡 �߰��� �������� ���
	}
		p->link = removed->link;
	free(removed);
}

void display(Todo_list*head) {
	Todo_list*p = head;
	while (p != NULL) {
		printf("	%d	%d	%s\n", p->Start, p->Run, p->Todo);
		p = p->link;
	}
	printf("\n");
}

void display_2(Todo_list*head, int *a) {
	Todo_list*p = head;
	while (p != NULL) {
		if (p->Start == a){
			printf("	%d	%d	%s\n", p->Start, p->Run, p->Todo);
		}
		p = p->link;
	}
	printf("\n");
}
int main()
{
	int num;
	Todo_list *new = NULL;			// ��� ������
	Todo_list *phead = NULL;		// head ������
	Todo_list *p = NULL;			// ������ ������
	Todo_list *q = NULL;			// ������ ������2
	while (1)
	{
		printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n");
		printf("                      1. ���� �Է�\n");
		printf("                      2. ���� ����\n");
		printf("                      3. ���� �˼�\n\n");
		printf("���ϴ� �۾��� �Է��Ͻÿ� : ");
		scanf("%d", &num);
		printf("\n\n");

		switch (num)
		{
			case 1: {
				new = (Todo_list*)malloc(sizeof(Todo_list));		// �� ��� ������ ����
				printf("                      1. ���� �Է�\n\n");
				printf("���۽ð� : ");
				scanf("%d", &new->Start);
				printf("�ҿ�ð� : ");
				scanf("%d", &new->Run);
				printf("��    �� : ");
				scanf("%s", &new->Todo);
				new->link = NULL;			// ��忡 �� �Է��ϱ�

				p = search(phead, &new->Start, &new->Run);		// ���Ե� ��ġ ���
				insert_node(&phead, p, new);		// �� �ֱ�

				printf("\n%d�ú��� %d�ð����� ���� '%s�� �ԷµǾ����ϴ�.\n\n\n\n\n", new->Start, new->Run, &new->Todo);
				break;
			}
			case 2: {
				printf("                      2. ���� ����\n\n");
				printf("������ �ð� : ");
				scanf("%d", &num);
				if (num == -1) {
					phead = NULL;
				}
				else {
					p = NULL;
					q = phead;
					remove_node(&phead, p, new);
				}
				printf("\n\n\n\n");
				break;
			}
			case 3: {
				printf("                      3. ���� �˼�\n\n");
				
				printf("�˼��� �ð� : ");
				scanf("%d", &num);
				if (num == -1) {
					printf("\n������ ��� �����Դϴ�.\n");
					printf("\n	����	�ð�	����\n");
					display(phead);
				}
				else {
					printf("\n%d�ÿ� ������ �����Դϴ�.\n", num);
					printf("\n	����	�ð�	����\n");
					display_2(phead, num);
				}
				printf("\n\n\n\n");
				break;
			}
		}
	}

system("PAUSE");
return 0;
}