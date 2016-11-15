#include "stdio.h"
#include "stdlib.h"
void reversestr(char* str){
	int len = strlen(str);
	//printf("%d", len);
	char c;
	for (int i = 0; i < len/2; i++){
		c = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = c;
	}
	
}
char* joinstr(char* str1, char* str2){
	//printf("str1:%d str2: %d", strlen(str1),strlen(str2));
	char* result = (char*)malloc(strlen(str1) + strlen(str1) + 1);
	int i = 0;
	int j = 0;
	int k = 0;
	/*while (str1[i]!='\0'){
		result[k++] = str1[i++];		
	}
	while (str2[j] != '\0'){
		result[k++] = str2[j++];		
	}*/
	strcpy(result, str1);
	strcat(result, str2);
	//result[k] = '\0';
	//printf("result:%d ", strlen(result));
	return result;
}
void main(){
	char* s1 = "hello";
	int num = 100;
	char str[10];
	char* result;
	//char*  str=(char*)malloc(sizeof(10));
	//_itoa(num, str, 10);
	sprintf(str,"%d",100);
	reversestr(str);
	//printf("The number 'num' is %d and the string 'str' is %s. \n",	100, str);
	result = joinstr(s1, str);
	printf("%s",result);
	system("PAUSE");
}
