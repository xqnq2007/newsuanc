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
	int size;
}squene;
squene* init(){
	squene* tmp = (squene*)malloc(sizeof(squene));
	tmp->head = 0;
	tmp->tail = 0;
	tmp->size = 0;
	return tmp;
}
void enquene(squene* sq, stu s){
	if (sq->size == maxsize){
		printf("队列已经满\n");
		return;
	}
	sq->s[sq->tail] = s;	
	sq->tail = (sq->tail + 1) % maxsize;
	sq->size++;
}
void dequene(squene*sq, stu* s){
	if (sq->size==0){
		printf("队列已经空\n");	
		return;
	}
	*s = sq->s[sq->head];
	sq->head = (sq->head + 1) % maxsize;
	sq->size--;
}
void display(squene* sq){	
	if (sq->size == 0){
		printf("队列已经空\n");
		return;
	}
	printf("元素展示开始\n");
	int j = sq->head;
	for (int i = 0; i < sq->size; i++){
		printf("第%d条数据：id:%d\t name:%s\t age:%d \n", i + 1, sq->s[j].id, sq->s[j].name, sq->s[j].age);
		j = (j + 1) % maxsize;
	}	
	printf("元素展示结束\n");
}
void main(){
	squene* quene = NULL;
	quene = init();	
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
	printf("队列当前长度：%d\n", quene->size);
	display(quene);
	enquene(quene, s4);
	display(quene);
	printf("队列当前长度：%d\n", quene->size);
	//stu* s=NULL;
	stu* s = (stu*)malloc(sizeof(stu));
	//stu* s;	
	dequene(quene, s);	
	printf("出队元素：%s\n", s->name);	
	display(quene);
	printf("队列当前长度：%d\n", quene->size);
	dequene(quene, s);
	printf("出队元素：%s\n", s->name);	
	display(quene);
	printf("队列当前长度：%d\n", quene->size);
	dequene(quene, s);
	printf("出队元素：%s\n", s->name);	
	display(quene);
	printf("队列当前长度：%d\n", quene->size);
	/*if (dequene(quene, s)){
	printf("出队元素：%s\n", s->name);
	}
	display(quene);
	printf("队列当前长度：%d\n", quene->tail - quene->head);*/
	enquene(quene, s2);
	display(quene);
	system("PAUSE");
}