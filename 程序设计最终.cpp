#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "�ɼ�����.txt"
typedef struct
{
	char name[15];
	int number;
	int python;
	int C;
	int java;
	int average;
	int sum;
} student;
typedef struct node
{
	student stu;
	struct node* next;	//ָ����ָ����һ���ڵ�
} studentNode;			//ѧ���ڵ�
typedef struct
{
	studentNode* head;	//ͷָ��
	studentNode* tail;	//βָ��
	int count;			//ѧ���ڵ�����
} studentList;			//ѧ������
void enter(studentList* L);		//����ɼ�
void display(studentList* L);	//��ʾĳ��Ŀѧ��
void display1(studentList* L);
void find(studentList* L);       //��������ĳ��
void find1(studentList* L);		//ѧ�Ų���ĳ��
void modify(studentList* L);	//�������޸�
void modify1(studentList* L);	//��ѧ���޸�
void sort(studentList* L);		//�������½������
void sort1(studentList* L);        //��ĳ������
void write(studentList* L);		//д���ļ�����д���ͷſռ�
void read(studentList* L);		//��ȡ�ļ����߶��߽���
int main() {

	printf("		**************ѧ���ɼ�����ϵͳ**************\n");
	printf("		*  1.¼���µ�ѧ���ɼ�                      *\n");//ok,���޿γ̱��
	printf("		*  2.�������޸�ѧ���ɼ�                    *\n");//ok
	printf("		*  3.��ѧ���޸�ѧ���ɼ�                    *\n");//ok
	printf("		*  4.��������ѯѧ���ɼ�                    *\n");//ok
	printf("		*  5.��ѧ�Ų�ѯѧ���ɼ�                    *\n");//ok
	printf("		*  6.��ѯĳ��Ŀ��ѡ��ѧ����Ϣ              *\n");//ok
	printf("		*  7.���ĳ��Ŀ��ѧ���ɼ�����              *\n");
	printf("		*  8.��ƽ�������ѧ���ɼ�                  *\n");//ok
	printf("		*  9.�˳�ѧ���ɼ�����ϵͳ                  *\n");//ok
	printf("		********************************************\n");
	printf("  	                                                \n");
	//����ѧ������
	studentList* L = (studentList*)malloc(sizeof(studentList));
	//��ʼ��ѧ������
	studentNode* s = (studentNode*)malloc(sizeof(studentNode));//*sΪ���ٿռ��ͷ����ѧ������
	s->next = NULL;
	//��ʼ������
	//ͷβָ���ָ��ͷ�ڵ㣬��ʼ����Ϊ��
	L->head = s;
	L->tail = s;
	L->count= 0;
	//���ļ����ȡ���ݵ�����
	read(L);
	while (1) {
		int code;
		printf("������������еĲ�����Ӧ������: ");
		scanf("%d", &code);
			if (code == 1)
				enter(L);
			else if (code == 2)
				modify(L);
			else if (code == 3)
				modify1(L);
			else if (code == 4)
				find(L);
			else if (code == 5)
				find1(L);
			else if (code == 6)
				display(L);
			else if (code == 7)
				sort1(L);
			else if (code == 8)
				sort(L);
			else if (code == 9)
			{
				write(L);
				free(L->head);	//ͷ�ڵ㱻����
				free(L);		//��������
				return 0;
			}
			else
				printf("%d����Ч�����֣����������룡\n\n", code);
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void enter(studentList* L)////¼��ѧ���ɼ�
{
	//�����¿ռ�
	studentNode* s = (studentNode*)malloc(sizeof(studentNode));
	//������ռ�������и�ֵ
	printf("������ѧ��������");
	scanf("%s",s->stu.name);
	printf("������ѧ��ѧ�ţ�");
	scanf("%d", &s->stu.number);
	printf("������python�ɼ���");
	scanf("%d", &s->stu.python);
	printf("������C�ɼ���");
	scanf("%d", &s->stu.C);
	printf("������java�ɼ���");
	scanf("%d", &s->stu.java);
	(*s).stu.sum = s->stu.python + s->stu.C + s->stu.java;
	s->stu.average = s->stu.sum / 3;
	//������Ϊ�գ���βָ��ָ���������ռ�
	if (L->head == L->tail) {
		L->tail = s;
	}
	//���������ռ�����������head����)
	s->next = L->head->next;
	L->head->next = s;
	L->count++;
	//�������
	printf("��Ϣ¼��ɹ���\n\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void display(studentList* L)//���ѡ��ĳ��Ŀ��ѧ����δ����
{
	printf("������ѡ��Ŀ�Ŀ���ƣ�");
	char course1[20];
	scanf("%s", course1);
	if (strcmp(course1, "python") == 0)//ѡpythonʱ��
	{
		printf("����\t\tѧ��\t\t�ɼ�\n");
		//����ָ���ͷ��ʼ����
		studentNode* p = L->head;
		while (p->next)//��next=NULLʱ����ѭ��
		{
			p = p->next;//ÿ��ѭ����ָ����һ������ռ�
			if (p->stu.python != 0) //����һ��Ϊ��� ����ֲ������Ĭ��ûѡ��һ��
			{                              //���ѧ������Ϣ
				printf("%s", p->stu.name);
				printf("\t\t%d", p->stu.number);
				printf("\t\t%d", p->stu.python);
				printf("\n");
			}
		}
		printf("\n");
	}
	if (strcmp(course1, "C") == 0)//ѡC��ʱ��
	{
		printf("����\t\tѧ��\t\t�ɼ�\n");
		//����һ�ڵ�ָ��ָ��ͷ�ڵ�
		studentNode* p = L->head;
		//�����������
		while (p->next)
		{
			p = p->next;
			if (p->stu.C != 0) //��ûѡ��һ�����Ϊ��� ����ֲ����
			{
				printf("%s", p->stu.name);
				printf("\t\t%d", p->stu.number);
				printf("\t\t%d", p->stu.C);
				printf("\n");
			}
		}
		printf("\n");
	}
	if (strcmp(course1, "java") == 0)//ѡjavaʱ��
	{
		printf("����\t\tѧ��\t\t�ɼ�\n");
		//����һָ��ָ��ͷ�ڵ�
		studentNode* p = L->head;
		while (p->next)
		{
			p = p->next;
			if (p->stu.java != 0)
			{
				printf("%s", p->stu.name);
				printf("\t\t%d", p->stu.number);
				printf("\t\t%d", p->stu.java);
				printf("\n");
			}
		}
		printf("\n");
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////����ĳ��ѧ��
void find(studentList* L)//ͨ����������ѧ����Ϣ
{
	printf("������ѧ��������");
	char name[15];
	scanf("%s", name);
	studentNode* p = (*L->head).next;
	while (p) {
		//�����˾��������������
		if (strcmp(p->stu.name, name) == 0)
		{
			printf("����\t\tѧ��\t\tpython\t\tC\t\tjava\t\t�ܷ�\t\tƽ����\n");
			printf("%s", p->stu.name);
			printf("\t\t%d", p->stu.number);
			printf("\t\t%d", p->stu.python);
			printf("\t\t%d", p->stu.C);
			printf("\t\t%d", p->stu.java);
			printf("\t\t%d", p->stu.sum);
			printf("\t\t%d", p->stu.average);
			printf("\n\n");
			return;//���������������������
		}
		//���ֲ����Ͼ���һ��
		p = p->next;
	}
	//����û�ҵ��������
	printf("û�ҵ�������Ϣ��\n\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void find1(studentList* L)//ͨ��ѧ�Ų���ѧ����Ϣ
{
	printf("������ѧ��ѧ�ţ�");
	int number;
	scanf("%d", &number);
	//������ָ�룬�ӵڶ�����ʼ����
	studentNode* p = (*L->head).next;
	while (p) {
		//�����˾��������������
		if (p->stu.number == number)
		{
			printf("����\t\tѧ��\t\tpython\t\tC\t\tjava\t\t�ܷ�\t\tƽ����\n");
			printf("%s", p->stu.name);
			printf("\t\t%d", p->stu.number);
			printf("\t\t%d", p->stu.python);
			printf("\t\t%d", p->stu.C);
			printf("\t\t%d", p->stu.java);
			printf("\t\t%d", p->stu.sum);
			printf("\t\t%d", p->stu.average);
			printf("\n\n");
			return;
		}
		//ѧ�Ų����Ͼ���һ��
		p = p->next;
	}
	//�������ﶼû�ҵ����ѧ��
	printf("û�ҵ����ˣ�\n\n");
}
/////////////////////////////////////////////////////////////////////////////////// ////////////
void display1(studentList* L)//���ȫ��ѧ���ɼ�
 {
	printf("����\t\tѧ��\t\tpython\t\tC\t\tjava\t\t�ܷ�\t\tƽ����\n");
	//����ָ��ָ��ͷ�ڵ�
	studentNode* p= L->head;
	while (p->next) {
		p = p->next;
		printf("%s", p->stu.name);
		printf("\t\t%d", p->stu.number);
		printf("\t\t%d", p->stu.python);
		printf("\t\t%d", p->stu.C);
		printf("\t\t%d", p->stu.java);
		printf("\t\t%d", p->stu.sum);
		printf("\t\t%d", p->stu.average);
		printf("\n");
	}
	printf("\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////
void sort(studentList* L)//���ƽ���ɼ������ĳɼ���
{
	//���������ڵ㲻������
	if (L->count < 2)
	{
		display1(L);
		return;
	}
	//���ò������򷨽�������
	studentNode* p, * pre, * tmp;
	//pָ��ڶ���ѧ���ڵ�
	p = (*L->head).next;
	//�����ͷ�ڵ�͵�һ��ѧ���ڵ㴦�Ͽ�
	(*L->head).next = NULL;
	//�ӵ�һ��ѧ���ڵ㿪ʼһֱ����ѭ��
	while (p)
	{
		//�����һ���ڵ��ָ��
		tmp = p->next;
		//�ҵ�����λ��
		pre = L->head;
		while ((*pre).next != NULL && (*(*pre).next).stu.average > p->stu.average)
			pre = (*pre).next;
		//����βָ��
		if ((*pre).next == NULL) {
			L->tail = p;
		}
		//����
		p->next = (*pre).next;
		(*pre).next = p;
		//������һ��
		p = tmp;
	}
	display1(L);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sort1(studentList* L)//���ĳ��Ŀѧ���ɼ�����
{
	printf("������ѡ��Ŀ�Ŀ���ƣ�");
	char course1[20];
	scanf("%s", course1);
	if (strcmp(course1, "python") == 0)
	{
		//�������� ��������ʼ
		studentNode* p, * pre, * tmp;
		//pָ��ڶ���ѧ���ڵ�
		p = (*L->head).next;
		//�����ͷ�ڵ�͵�һ��ѧ���ڵ㴦�Ͽ�
		(*L->head).next = NULL;
		//�ӵ�һ��ѧ���ڵ㿪ʼһֱ����ѭ��
		while (p)
		{
			//�����һ���ڵ��ָ��
			tmp = p->next;
			//�ҵ�����λ��
			pre = L->head;
			while ((*pre).next != NULL && (*(*pre).next).stu.python > p->stu.python)
				pre = (*pre).next;
			//����βָ��
			if ((*pre).next == NULL) {
				L->tail = p;
			}
			//����
			p->next = (*pre).next;
			(*pre).next = p;
			//������һ��
			p = tmp;
		}//////������������
		printf("����\t\tѧ��\t\t�ɼ�\n");
		//����һ�ڵ�ָ��ָ��ͷ�ڵ�
		p = L->head;
		//�����������
		while (p->next)
		{
			p = p->next;
			if (p->stu.python != 0) //��ûѡ��һ�����Ϊ��� ����ֲ����
			{
				printf("%s", p->stu.name);
				printf("\t\t%d", p->stu.number);
				printf("\t\t%d", p->stu.python);
				printf("\n");
			}
		}
		printf("\n");
	}
	if (strcmp(course1, "C") == 0)
	{
		//��������
		studentNode* p, * pre, * tmp;
		//pָ��ڶ���ѧ���ڵ�
		p = (*L->head).next;
		//�����ͷ�ڵ�͵�һ��ѧ���ڵ㴦�Ͽ�
		(*L->head).next = NULL;
		//�ӵ�һ��ѧ���ڵ㿪ʼһֱ����ѭ��
		while (p)
		{
			//�����һ���ڵ��ָ��
			tmp = p->next;
			//�ҵ�����λ��
			pre = L->head;
			while ((*pre).next != NULL && (*(*pre).next).stu.C > p->stu.C)
				pre = (*pre).next;
			//����βָ��
			if ((*pre).next == NULL) {
				L->tail = p;
			}
			//����
			p->next = (*pre).next;
			(*pre).next = p;
			//������һ��
			p = tmp;
		}
		printf("����\t\tѧ��\t\t�ɼ�\n");
		//����һ�ڵ�ָ��ָ��ͷ�ڵ�
		p = L->head;
		//�����������
		while (p->next)
		{
			p = p->next;
			if (p->stu.C != 0) //��ûѡ��һ�����Ϊ��� ����ֲ����
			{
				printf("%s", p->stu.name);
				printf("\t\t%d", p->stu.number);
				printf("\t\t%d", p->stu.C);
				printf("\n");
			}
		}
		printf("\n");
	}
	if (strcmp(course1, "java") == 0)
	{
		//��������
		studentNode* p, * pre, * tmp;
		//pָ��ڶ���ѧ���ڵ�
		p = (*L->head).next;
		//�����ͷ�ڵ�͵�һ��ѧ���ڵ㴦�Ͽ�
		(*L->head).next = NULL;
		//�ӵ�һ��ѧ���ڵ㿪ʼһֱ����ѭ��
		while (p)
		{
			//�����һ���ڵ��ָ��
			tmp = p->next;
			//�ҵ�����λ��
			pre = L->head;
			while ((*pre).next != NULL && (*(*pre).next).stu.java > p->stu.java)
				pre = (*pre).next;
			//����βָ��
			if ((*pre).next == NULL) {
				L->tail = p;
			}
			//����
			p->next = (*pre).next;
			(*pre).next = p;
			//������һ��
			p = tmp;
		}
		printf("����\t\tѧ��\t\t�ɼ�\n");
		//����һ�ڵ�ָ��ָ��ͷ�ڵ�
		p = L->head;
		//�����������
		while (p->next)
		{
			p = p->next;
			if (p->stu.java != 0) //��ûѡ��һ�����Ϊ��� ����ֲ����
			{
				printf("%s", p->stu.name);
				printf("\t\t%d", p->stu.number);
				printf("\t\t%d", p->stu.java);
				printf("\n");
			}
		}
		printf("\n");
	}

}
//////////////////////////////////////////////////////////////////////////////////////////////
void modify(studentList* L)        //���������޸�ѧ���ɼ�
{
	printf("������ѧ��������");
	char name[15];
	scanf("%s", name);
	studentNode* p = (*L->head).next;
	while (p) {
		if (strcmp(p->stu.name, name) == 0)//�����˾����½��и�ֵ
		{
			printf("������������Ϣ��\n");
			printf("������ѧ��ѧ�ţ�");
			scanf("%d", &p->stu.number);
			printf("������python�ɼ���");
			scanf("%d", &p->stu.python);
			printf("������C�ɼ���");
			scanf("%d", &p->stu.C);
			printf("������java�ɼ���");
			scanf("%d", &p->stu.java);
			p->stu.sum = p->stu.python + p->stu.C + p->stu.java;
			p->stu.average = p->stu.sum / 3;
			printf("��Ϣ�޸ĳɹ���\n\n");
			return;
		}
		//���ֲ����Ͼ���һ��
		p = p->next;
	}
	//�������ﶼû�ҵ��������
	printf("û�ҵ�������Ϣ��\n\n", name);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modify1(studentList* L)        //����ѧ���޸�ѧ���ɼ�
{
	printf("������ѧ��ѧ�ţ�");
	int number;
	scanf("%d", &number);
	//��������Ա�ѧ��
	studentNode* p = (*L->head).next;
	while (p) {
		//�����˾����û����¸�ֵ
		if (p->stu.number == number)
		{
			printf("������������Ϣ��\n");
			printf("������ѧ��������");
			scanf("%s", p->stu.name);
			printf("������python�ɼ���");
			scanf("%d", &p->stu.python);
			printf("������C�ɼ���");
			scanf("%d", &p->stu.C);
			printf("������java�ɼ���");
			scanf("%d", &p->stu.java);
			p->stu.sum = p->stu.python + p->stu.C + p->stu.java;
			p->stu.average = p->stu.sum / 3;
			printf("��Ϣ�޸ĳɹ���\n\n");
			return;
		}
		//ѧ�Ų����Ͼ���һ��
		p = p->next;
	}
	//�������ﶼû�ҵ����ѧ��
	printf("û�ҵ����˵���Ϣ��\n\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void write(studentList* L)//���������������ļ�
{
	//���ļ�
	FILE* fp = fopen(FILE_NAME, "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);//�������г���
	}
	//��ѧ���ڵ���������ڵ�һ��
	fprintf(fp, "%d\n", L->count);
	//����һ�ڵ�ָ��ָ��ͷ�ڵ�
	studentNode* p;
	p = (*L->head).next;
	while (p) {
		fprintf(fp, "%s ", p->stu.name);
		fprintf(fp, "%d ", p->stu.number);
		fprintf(fp, "%d ", p->stu.python);
		fprintf(fp, "%d ", p->stu.C);
		fprintf(fp, "%d ", p->stu.java);
		fprintf(fp, "%d ", p->stu.sum);
		fprintf(fp, "%d ", p->stu.average);
		fprintf(fp, "\n");
		//������֮���ͷŽڵ�ռ�
		studentNode* next = p->next;
		free(p);
		p = next;//pָ����һ������ռ�
	}
	//�ر��ļ�
	fclose(fp);
	printf("�����ѱ��棡ллʹ�ã��ټ���\n");
}
///////////////////////////////////////////////////////////////////////////
void read(studentList* L)//���ļ��ж�ȡ���ݵ�����
{
	FILE* fp = fopen(FILE_NAME, "r");
	if (fp == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);//��������
	}
	//��ȡ��һ�е�ѧ���ڵ�����
	fscanf(fp, "%d", &L->count);
	//ѭ����ȡ���ݣ�ѭ������Ϊcount
	for (int i = 1; i <= L->  count; i++)
	{
		//�����½ڵ�
		studentNode* s = (studentNode*)malloc(sizeof(studentNode));
		//��ȡ����
		fscanf(fp, "%s ", s->stu.name);
		fscanf(fp, "%d ", &s->stu.number);
		fscanf(fp, "%d ", &s->stu.python);
		fscanf(fp, "%d ", &s->stu.C);
		fscanf(fp, "%d ", &s->stu.java);
		fscanf(fp, "%d ", &s->stu.sum);
		fscanf(fp, "%d ", &s->stu.average);
		//���½ڵ�������β��
		s->next = NULL;
		L->tail->next = s;//L->tailָ���ǲ���ǰ��������һ����㣬���������nextָ���˲���Ľ��
		L->tail = s;
	}
	//�ر��ļ�
	fclose(fp);
}
