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
		printf("�����Ѿ���\n");
		return;
	}
	sq->s[sq->tail] = s;	
	sq->tail = (sq->tail + 1) % maxsize;
	sq->size++;
}
void dequene(squene*sq, stu* s){
	if (sq->size==0){
		printf("�����Ѿ���\n");	
		return;
	}
	*s = sq->s[sq->head];
	sq->head = (sq->head + 1) % maxsize;
	sq->size--;
}
void display(squene* sq){	
	if (sq->size == 0){
		printf("�����Ѿ���\n");
		return;
	}
	printf("Ԫ��չʾ��ʼ\n");
	int j = sq->head;
	for (int i = 0; i < sq->size; i++){
		printf("��%d�����ݣ�id:%d\t name:%s\t age:%d \n", i + 1, sq->s[j].id, sq->s[j].name, sq->s[j].age);
		j = (j + 1) % maxsize;
	}	
	printf("Ԫ��չʾ����\n");
}
void main(){
	squene* quene = NULL;
	quene = init();	
	stu s1 = { 111, "��", 29 };
	stu s2 = { 112, "��", 24 };
	stu s3 = { 113, "��", 26 };
	stu s4 = { 114, "��", 21 };
	enquene(quene, s1);
	printf("���е�ǰ���ȣ�%d\n", quene->tail - quene->head);
	display(quene);
	enquene(quene, s2);
	printf("���е�ǰ���ȣ�%d\n", quene->tail - quene->head);
	display(quene);
	enquene(quene, s3);
	printf("���е�ǰ���ȣ�%d\n", quene->size);
	display(quene);
	enquene(quene, s4);
	display(quene);
	printf("���е�ǰ���ȣ�%d\n", quene->size);
	//stu* s=NULL;
	stu* s = (stu*)malloc(sizeof(stu));
	//stu* s;	
	dequene(quene, s);	
	printf("����Ԫ�أ�%s\n", s->name);	
	display(quene);
	printf("���е�ǰ���ȣ�%d\n", quene->size);
	dequene(quene, s);
	printf("����Ԫ�أ�%s\n", s->name);	
	display(quene);
	printf("���е�ǰ���ȣ�%d\n", quene->size);
	dequene(quene, s);
	printf("����Ԫ�أ�%s\n", s->name);	
	display(quene);
	printf("���е�ǰ���ȣ�%d\n", quene->size);
	/*if (dequene(quene, s)){
	printf("����Ԫ�أ�%s\n", s->name);
	}
	display(quene);
	printf("���е�ǰ���ȣ�%d\n", quene->tail - quene->head);*/
	enquene(quene, s2);
	display(quene);
	system("PAUSE");
}