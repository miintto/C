#include <stdio.h>

struct Todo_list {
	int Start;
	int Run;
	char Todo[10];
	struct Todo_list*link;
};

int main() 
{
	char A[10];

	struct Todo_list *head = malloc(sizeof(struct Todo_list));			//// head ��� ���� (�ڷ� X)

	struct Todo_list *node = malloc(sizeof(struct Todo_list));			//// ��� ����

	head->link = node;				//// head�� node ����
	node->Start = 1;
	node->Run = 1;		//// ��忡 �� ����
	node->link = NULL;
	printf("�Է� : ");
	scan_s("%s", A, 10);;						//// ��ũ�� 0

	printf("%d %d %s\n", node -> Start, node -> Run, A);

	system("pause");
	return 0;
}
		
/*
int main() 
{
	int num;
	int Start;
	int Run;
	char Todo[20];
	int Dlt;
	int Srh;
	
	
	while(1){
	printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n\n");
	printf("                    1. �� �� �Է�\n");
	printf("                    2. �� �� �����\n");
	printf("                    3. �� �� �˻�\n\n\n");

	printf("���ϴ� �۾��� �Է��Ͻÿ�.\ : ");
	scanf_s("%d", &num);
	printf("\n\n");

	switch (num)
	{
	case 1:
	{
		printf("                    1. �� �� �Է�\n\n");
		printf("���۽ð� : ");
		scanf_s("%d", &Start);
		printf("�ҿ�ð� : ");
		scanf_s("%d", &Run);
		printf("���� : ");
		scanf_s("%s", &Todo, 10);
		

		
		printf("\n[%d�ú��� %d�ð����� �� �� %s�� �Է¹޾ҽ��ϴ�.]\n\n\n", Start, Run, Todo);

		break;
	}
	case 2:
	{
		printf("                    2. �� �� �����\n\n");
		printf("������ �ð� : ");
		scanf_s("%d", &Dlt);
		if (Dlt == -1) {
			printf("\n[��� �� ���� �����߽��ϴ�.]\n\n\n");
		}
		else {
			printf("\n[%d�� �� ���� �����߽��ϴ�.]\n\n\n", Dlt);
		}

		break;
	}
	case 3:
	{
		printf("                    3. �� �� �˻�\n\n");
		printf("�˻��� �ð� : ");
		scanf_s("%d", &Srh);
		if (Srh == -1) {
			printf("\n[��� �� �� ����]\n\n\n");
	}
		else {
			printf("\n[%d�� �� �� ����]\n\n\n", Srh);
		}break;
	}
	}
	}


}*/