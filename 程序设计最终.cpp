#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILE_NAME "成绩管理.txt"
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
	struct node* next;	//指针域，指向下一个节点
} studentNode;			//学生节点
typedef struct
{
	studentNode* head;	//头指针
	studentNode* tail;	//尾指针
	int count;			//学生节点总数
} studentList;			//学生链表
void enter(studentList* L);		//输入成绩
void display(studentList* L);	//显示某科目学生
void display1(studentList* L);
void find(studentList* L);       //姓名查找某人
void find1(studentList* L);		//学号查找某人
void modify(studentList* L);	//靠名字修改
void modify1(studentList* L);	//靠学号修改
void sort(studentList* L);		//降序重新建表并输出
void sort1(studentList* L);        //对某科排序
void write(studentList* L);		//写入文件，边写边释放空间
void read(studentList* L);		//读取文件，边读边建表
int main() {

	printf("		**************学生成绩管理系统**************\n");
	printf("		*  1.录入新的学生成绩                      *\n");//ok,但无课程编号
	printf("		*  2.按姓名修改学生成绩                    *\n");//ok
	printf("		*  3.按学号修改学生成绩                    *\n");//ok
	printf("		*  4.按姓名查询学生成绩                    *\n");//ok
	printf("		*  5.按学号查询学生成绩                    *\n");//ok
	printf("		*  6.查询某科目的选课学生信息              *\n");//ok
	printf("		*  7.输出某科目的学生成绩排名              *\n");
	printf("		*  8.按平均分输出学生成绩                  *\n");//ok
	printf("		*  9.退出学生成绩管理系统                  *\n");//ok
	printf("		********************************************\n");
	printf("  	                                                \n");
	//创建学生链表
	studentList* L = (studentList*)malloc(sizeof(studentList));
	//初始化学生链表
	studentNode* s = (studentNode*)malloc(sizeof(studentNode));//*s为开辟空间的头，无学生数据
	s->next = NULL;
	//初始化链表：
	//头尾指针均指向头节点，初始长度为零
	L->head = s;
	L->tail = s;
	L->count= 0;
	//从文件里读取数据到链表
	read(L);
	while (1) {
		int code;
		printf("请输入你想进行的操作对应的数字: ");
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
				free(L->head);	//头节点被销毁
				free(L);		//链表被销毁
				return 0;
			}
			else
				printf("%d是无效的数字，请重新输入！\n\n", code);
	}
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void enter(studentList* L)////录入学生成绩
{
	//创建新空间
	studentNode* s = (studentNode*)malloc(sizeof(studentNode));
	//对这个空间的量进行赋值
	printf("请输入学生姓名：");
	scanf("%s",s->stu.name);
	printf("请输入学生学号：");
	scanf("%d", &s->stu.number);
	printf("请输入python成绩：");
	scanf("%d", &s->stu.python);
	printf("请输入C成绩：");
	scanf("%d", &s->stu.C);
	printf("请输入java成绩：");
	scanf("%d", &s->stu.java);
	(*s).stu.sum = s->stu.python + s->stu.C + s->stu.java;
	s->stu.average = s->stu.sum / 3;
	//若链表为空，将尾指针指向这个储存空间
	if (L->head == L->tail) {
		L->tail = s;
	}
	//将这个储存空间插进链表（放在head后面)
	s->next = L->head->next;
	L->head->next = s;
	L->count++;
	//功能完成
	printf("信息录入成功！\n\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void display(studentList* L)//输出选择某科目的学生，未排名
{
	printf("请输入选择的科目名称：");
	char course1[20];
	scanf("%s", course1);
	if (strcmp(course1, "python") == 0)//选python时候
	{
		printf("姓名\t\t学号\t\t成绩\n");
		//创建指针从头开始查找
		studentNode* p = L->head;
		while (p->next)//当next=NULL时候不再循环
		{
			p = p->next;//每次循环都指向下一个储存空间
			if (p->stu.python != 0) //若这一科为零分 ，零分不输出，默认没选这一课
			{                              //输出学生的信息
				printf("%s", p->stu.name);
				printf("\t\t%d", p->stu.number);
				printf("\t\t%d", p->stu.python);
				printf("\n");
			}
		}
		printf("\n");
	}
	if (strcmp(course1, "C") == 0)//选C的时候
	{
		printf("姓名\t\t学号\t\t成绩\n");
		//创建一节点指针指向头节点
		studentNode* p = L->head;
		//遍历链表输出
		while (p->next)
		{
			p = p->next;
			if (p->stu.C != 0) //若没选这一科则记为零分 ，零分不输出
			{
				printf("%s", p->stu.name);
				printf("\t\t%d", p->stu.number);
				printf("\t\t%d", p->stu.C);
				printf("\n");
			}
		}
		printf("\n");
	}
	if (strcmp(course1, "java") == 0)//选java时候
	{
		printf("姓名\t\t学号\t\t成绩\n");
		//创建一指针指向头节点
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

/////////////////////////////////////////////////////////////////////////////////////////////查找某个学生
void find(studentList* L)//通过姓名查找学生信息
{
	printf("请输入学生姓名：");
	char name[15];
	scanf("%s", name);
	studentNode* p = (*L->head).next;
	while (p) {
		//符合了就输出并结束函数
		if (strcmp(p->stu.name, name) == 0)
		{
			printf("姓名\t\t学号\t\tpython\t\tC\t\tjava\t\t总分\t\t平均分\n");
			printf("%s", p->stu.name);
			printf("\t\t%d", p->stu.number);
			printf("\t\t%d", p->stu.python);
			printf("\t\t%d", p->stu.C);
			printf("\t\t%d", p->stu.java);
			printf("\t\t%d", p->stu.sum);
			printf("\t\t%d", p->stu.average);
			printf("\n\n");
			return;//这句会结束函数返回主函数
		}
		//名字不符合就下一个
		p = p->next;
	}
	//最终没找到这个名字
	printf("没找到此人信息！\n\n");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void find1(studentList* L)//通过学号查找学生信息
{
	printf("请输入学生学号：");
	int number;
	scanf("%d", &number);
	//创建个指针，从第二个开始查找
	studentNode* p = (*L->head).next;
	while (p) {
		//符合了就输出并结束函数
		if (p->stu.number == number)
		{
			printf("姓名\t\t学号\t\tpython\t\tC\t\tjava\t\t总分\t\t平均分\n");
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
		//学号不符合就下一个
		p = p->next;
	}
	//遍历完里都没找到这个学号
	printf("没找到此人！\n\n");
}
/////////////////////////////////////////////////////////////////////////////////// ////////////
void display1(studentList* L)//输出全部学生成绩
 {
	printf("姓名\t\t学号\t\tpython\t\tC\t\tjava\t\t总分\t\t平均分\n");
	//创建指针指向头节点
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
void sort(studentList* L)//输出平均成绩排名的成绩单
{
	//少于两个节点不用排序
	if (L->count < 2)
	{
		display1(L);
		return;
	}
	//利用插入排序法进行排名
	studentNode* p, * pre, * tmp;
	//p指向第二个学生节点
	p = (*L->head).next;
	//链表从头节点和第一个学生节点处断开
	(*L->head).next = NULL;
	//从第一个学生节点开始一直往后循环
	while (p)
	{
		//存好下一个节点的指针
		tmp = p->next;
		//找到插入位置
		pre = L->head;
		while ((*pre).next != NULL && (*(*pre).next).stu.average > p->stu.average)
			pre = (*pre).next;
		//更新尾指针
		if ((*pre).next == NULL) {
			L->tail = p;
		}
		//插入
		p->next = (*pre).next;
		(*pre).next = p;
		//跳到下一个
		p = tmp;
	}
	display1(L);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sort1(studentList* L)//输出某科目学生成绩排名
{
	printf("请输入选择的科目名称：");
	char course1[20];
	scanf("%s", course1);
	if (strcmp(course1, "python") == 0)
	{
		//插入排序法 ，排名开始
		studentNode* p, * pre, * tmp;
		//p指向第二个学生节点
		p = (*L->head).next;
		//链表从头节点和第一个学生节点处断开
		(*L->head).next = NULL;
		//从第一个学生节点开始一直往后循环
		while (p)
		{
			//存好下一个节点的指针
			tmp = p->next;
			//找到插入位置
			pre = L->head;
			while ((*pre).next != NULL && (*(*pre).next).stu.python > p->stu.python)
				pre = (*pre).next;
			//更新尾指针
			if ((*pre).next == NULL) {
				L->tail = p;
			}
			//插入
			p->next = (*pre).next;
			(*pre).next = p;
			//跳到下一个
			p = tmp;
		}//////到这排名结束
		printf("姓名\t\t学号\t\t成绩\n");
		//创建一节点指针指向头节点
		p = L->head;
		//遍历链表输出
		while (p->next)
		{
			p = p->next;
			if (p->stu.python != 0) //若没选这一科则记为零分 ，零分不输出
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
		//插入排序
		studentNode* p, * pre, * tmp;
		//p指向第二个学生节点
		p = (*L->head).next;
		//链表从头节点和第一个学生节点处断开
		(*L->head).next = NULL;
		//从第一个学生节点开始一直往后循环
		while (p)
		{
			//存好下一个节点的指针
			tmp = p->next;
			//找到插入位置
			pre = L->head;
			while ((*pre).next != NULL && (*(*pre).next).stu.C > p->stu.C)
				pre = (*pre).next;
			//更新尾指针
			if ((*pre).next == NULL) {
				L->tail = p;
			}
			//插入
			p->next = (*pre).next;
			(*pre).next = p;
			//跳到下一个
			p = tmp;
		}
		printf("姓名\t\t学号\t\t成绩\n");
		//创建一节点指针指向头节点
		p = L->head;
		//遍历链表输出
		while (p->next)
		{
			p = p->next;
			if (p->stu.C != 0) //若没选这一科则记为零分 ，零分不输出
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
		//插入排序
		studentNode* p, * pre, * tmp;
		//p指向第二个学生节点
		p = (*L->head).next;
		//链表从头节点和第一个学生节点处断开
		(*L->head).next = NULL;
		//从第一个学生节点开始一直往后循环
		while (p)
		{
			//存好下一个节点的指针
			tmp = p->next;
			//找到插入位置
			pre = L->head;
			while ((*pre).next != NULL && (*(*pre).next).stu.java > p->stu.java)
				pre = (*pre).next;
			//更新尾指针
			if ((*pre).next == NULL) {
				L->tail = p;
			}
			//插入
			p->next = (*pre).next;
			(*pre).next = p;
			//跳到下一个
			p = tmp;
		}
		printf("姓名\t\t学号\t\t成绩\n");
		//创建一节点指针指向头节点
		p = L->head;
		//遍历链表输出
		while (p->next)
		{
			p = p->next;
			if (p->stu.java != 0) //若没选这一科则记为零分 ，零分不输出
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
void modify(studentList* L)        //按照姓名修改学生成绩
{
	printf("请输入学生姓名：");
	char name[15];
	scanf("%s", name);
	studentNode* p = (*L->head).next;
	while (p) {
		if (strcmp(p->stu.name, name) == 0)//符合了就重新进行赋值
		{
			printf("请重新输入信息：\n");
			printf("请输入学生学号：");
			scanf("%d", &p->stu.number);
			printf("请输入python成绩：");
			scanf("%d", &p->stu.python);
			printf("请输入C成绩：");
			scanf("%d", &p->stu.C);
			printf("请输入java成绩：");
			scanf("%d", &p->stu.java);
			p->stu.sum = p->stu.python + p->stu.C + p->stu.java;
			p->stu.average = p->stu.sum / 3;
			printf("信息修改成功！\n\n");
			return;
		}
		//名字不符合就下一个
		p = p->next;
	}
	//遍历完里都没找到这个名字
	printf("没找到此人信息！\n\n", name);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void modify1(studentList* L)        //按照学号修改学生成绩
{
	printf("请输入学生学号：");
	int number;
	scanf("%d", &number);
	//遍历链表对比学号
	studentNode* p = (*L->head).next;
	while (p) {
		//符合了就让用户重新赋值
		if (p->stu.number == number)
		{
			printf("请重新输入信息：\n");
			printf("请输入学生姓名：");
			scanf("%s", p->stu.name);
			printf("请输入python成绩：");
			scanf("%d", &p->stu.python);
			printf("请输入C成绩：");
			scanf("%d", &p->stu.C);
			printf("请输入java成绩：");
			scanf("%d", &p->stu.java);
			p->stu.sum = p->stu.python + p->stu.C + p->stu.java;
			p->stu.average = p->stu.sum / 3;
			printf("信息修改成功！\n\n");
			return;
		}
		//学号不符合就下一个
		p = p->next;
	}
	//遍历完里都没找到这个学号
	printf("没找到此人的信息！\n\n");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void write(studentList* L)//把链表数据输入文件
{
	//打开文件
	FILE* fp = fopen(FILE_NAME, "w");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		exit(0);//结束所有程序
	}
	//将学生节点总数输出在第一行
	fprintf(fp, "%d\n", L->count);
	//创建一节点指针指向头节点
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
		//输出完成之后释放节点空间
		studentNode* next = p->next;
		free(p);
		p = next;//p指向下一个储存空间
	}
	//关闭文件
	fclose(fp);
	printf("数据已保存！谢谢使用，再见！\n");
}
///////////////////////////////////////////////////////////////////////////
void read(studentList* L)//从文件中读取数据到链表
{
	FILE* fp = fopen(FILE_NAME, "r");
	if (fp == NULL) {
		printf("文件打开失败\n");
		exit(0);//结束程序
	}
	//读取第一行的学生节点总数
	fscanf(fp, "%d", &L->count);
	//循环读取数据，循环次数为count
	for (int i = 1; i <= L->  count; i++)
	{
		//创建新节点
		studentNode* s = (studentNode*)malloc(sizeof(studentNode));
		//读取数据
		fscanf(fp, "%s ", s->stu.name);
		fscanf(fp, "%d ", &s->stu.number);
		fscanf(fp, "%d ", &s->stu.python);
		fscanf(fp, "%d ", &s->stu.C);
		fscanf(fp, "%d ", &s->stu.java);
		fscanf(fp, "%d ", &s->stu.sum);
		fscanf(fp, "%d ", &s->stu.average);
		//将新节点插进链表尾部
		s->next = NULL;
		L->tail->next = s;//L->tail指的是插入前链表的最后一个结点，是这个结点的next指向了插入的结点
		L->tail = s;
	}
	//关闭文件
	fclose(fp);
}
