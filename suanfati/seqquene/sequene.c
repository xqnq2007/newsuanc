#include "stdio.h"
#define maxsize 3
typedef struct student{
	int id;
	char name[10];
	int age;
}stu;
typedef struct seqQuene{
	stu s[maxsize];
	int head;
	int tail;
}squene;
squene* init(){
	squene* tmp = (squene*)malloc(sizeof(squene));
	tmp->head = 0;
	tmp->tail = 0;
	return tmp;
}
int enquene(squene* sq,stu s){
	if (sq->tail == maxsize){
		printf("队列已经满\n");
		return 0;
	}
	sq->s[sq->tail++] = s;
	return 1;
}
int dequene(squene*sq,stu* s){
	if (sq->head == sq->tail){
		printf("队列已经空\n");
		return 0;
	}	
	*s = sq->s[sq->head++];
	return 1;
}
void display(squene* sq){
	if (sq->head == sq->tail){
		printf("队列已经空,无元素可展示\n");
		return ;
	}
	printf("元素展示开始\n");
	for (int i = sq->head; i < sq->tail;i++)
		printf("第%d条数据：id:%d\t name:%s\t age:%d \n", i + 1, sq->s[i].id, sq->s[i].name, sq->s[i].age);
	printf("元素展示结束\n");
}
void main(){
	squene* quene = NULL;
	quene = init();
	display(quene);
	stu s1 = { 111, "王", 29 };
	stu s2 = { 112, "李", 24 };
	stu s3 = { 113, "杨", 26 };
	stu s4 = { 114, "赵", 21 };
	enquene(quene, s1);
	printf("队列当前长度：%d\n", quene->tail - quene->head);
	display(quene);
	enquene(quene, s2);
	printf("队列当前长度：%d\n", quene->tail - quene->head);
	display(quene);
	enquene(quene, s3);
	printf("队列当前长度：%d\n", quene->tail - quene->head);
	display(quene);
	enquene(quene, s4);
	display(quene);
	printf("队列当前长度：%d\n",quene->tail-quene->head);
	//stu* s=NULL;
	stu* s = (stu*)malloc(sizeof(stu));
	//stu* s;	
	if (dequene(quene,s)){
		printf("出队元素：%s\n", s->name);
	}
	display(quene);
	printf("队列当前长度：%d\n", quene->tail - quene->head);	
	if (dequene(quene, s)){
		printf("出队元素：%s\n", s->name);
	}
	display(quene);
	printf("队列当前长度：%d\n", quene->tail - quene->head);	
	if (dequene(quene, s)){
		printf("出队元素：%s\n", s->name);
	}
	display(quene);
	printf("队列当前长度：%d\n", quene->tail - quene->head);	
	/*if (dequene(quene, s)){
		printf("出队元素：%s\n", s->name);
	}
	display(quene);
	printf("队列当前长度：%d\n", quene->tail - quene->head);*/
	enquene(quene, s2);
	system("PAUSE");
}