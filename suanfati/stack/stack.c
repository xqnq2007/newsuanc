#include "stdio.h"
#define maxsize 3
typedef struct student{
	int id;
	char name[10];
	int age;
}stu;
typedef struct seqQuene{
	stu s[maxsize];
	int top;
}stack;
stack* init(){
	stack* st = (stack*)malloc(sizeof(stack));
	st->top = -1;
	return st;
}
void enstack(stack* st,stu s){
	if ((st->top + 1) == maxsize){
		printf("栈已满\n");
		return;
	}
	st->top++;
	st->s[st->top] = s;
}
int destack(stack* st, stu* s){
	if (st->top == -1){
		printf("栈已空\n");
		return 0;
	}
	*s = st->s[st->top];	
	st->top--;
	return 1;
}
void display(stack* st){
	if (st->top == -1){
		printf("栈已空,无数据展示\n");
		return;
	}
	int i=st->top;
	int j = 0;
	while (i > -1){
		printf("第%d条数据：id:%d\t name:%s\t age:%d \n", ++j, st->s[i].id, st->s[i].name, st->s[i].age);
		i--;
	}
}
void main(){
	stack* stack = NULL;
	stack = init();
	display(stack);
	stu s1 = { 111, "王", 29 };
	stu s2 = { 112, "李", 24 };
	stu s3 = { 113, "杨", 26 };
	stu s4 = { 114, "赵", 21 };
	enstack(stack, s1);
	printf("栈元素：%d\n", stack->top);
	display(stack);
	enstack(stack, s2);
	printf("栈元素：%d\n", stack->top);
	display(stack);
	enstack(stack, s3);
	printf("栈元素：%d\n", stack->top);
	display(stack);
	enstack(stack, s4);
	printf("栈元素：%d\n", stack->top);
	stu* s = (stu*)malloc(sizeof(stu));
	if (destack(stack, s)){
		printf("出栈元素：%s\n", s->name);
	}	
	if (destack(stack, s))
	printf("出栈元素：%s\n", s->name);
	if (destack(stack, s))
	printf("出栈元素：%s\n", s->name);
	if (destack(stack, s))
	printf("出栈元素：%s\n", s->name);
	system("PAUSE");
}