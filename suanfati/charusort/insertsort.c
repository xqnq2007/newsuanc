#include "stdio.h"
#include "time.h"

void insertsort(int* a, int len){
	for (int i = 1; i < len; i++){
		int j;		
		int tmp = a[i];
		for (j = i - 1; j >= 0 && tmp<a[j]; j--){
			a[j + 1] = a[j];
		}
		a[j + 1] = tmp;
	}
}
void hillsort(int* a, int len){
	int bu = len / 2;
	while (bu >= 1){
		for (int i = bu; i <len; i++){
			int j;
			int tmp = a[i];
			for (j = i - bu; j >= 0 && tmp < a[j]; j -= bu){
				a[j + bu] = a[j];
			}
			a[j + bu] = tmp;
		}
		bu /= 2;
	}
}
void merge(int*a, int*tmp,int left ,int right){	
	int mid = (left + right) / 2; 
	int leftstart = left;	
	int rightstart = mid + 1;
	int tmplen = right - left + 1;
	int k = left;
	while (leftstart <= mid&&rightstart <= right){
		if (a[leftstart] < a[rightstart]){
			tmp[k++] = a[leftstart++];			
		}
		else{
			tmp[k++] = a[rightstart++];			
		}
	}
	while (leftstart <= mid){		
		tmp[k++] = a[leftstart++];
	}
	while (rightstart <= right){		
		tmp[k++] = a[rightstart++];		
	}
	for (int ii = 0; ii <tmplen; ii++){
		a[right] = tmp[right];
		right--;
	}
}
void mergesort(int* a,int* b, int left,int right){
	if(left < right){
		int mid = (left + right) / 2;
		mergesort(a, b,left, mid);
		mergesort(a, b,mid + 1, right);
		merge(a, b,left, right);
	}
	
}
int compInc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

void main(){	
	int a[20000], b[20000],c[20000];
	//for (int ii = 0; ii<5000; ii++){
	//printf("第%d次：\n", ii);
	for (int i = 0; i < 20000; i++){
		b[i] = a[i] = rand();
	}
	clock_t t1, t2;
	double duration;
	for (int i = 0; i<50; i++){
		printf("%d\n", a[i]);
	}
	t1 = clock();
	printf("排序后：\n");
	int* tmp;
	//tmp = (int*)malloc(sizeof(int)*20000);
	tmp = c;
	//insertsort(a, 20000);
	//hillsort(a, 20000);
	mergesort(a, tmp, 0, 19999);
	t2 = clock();
	for (int i = 0; i<50; i++){
		printf("%d\n", a[i]);
	}
	duration = (double)(t2 - t1) / CLOCKS_PER_SEC;
	printf("自己写的归并排序用时：%f\n", duration);
	t1 = clock();
	qsort(b, 20000, sizeof(b[0]), compInc);
	t2 = clock();
	duration = (double)(t2 - t1) / CLOCKS_PER_SEC;
	printf("系统快速排序用时：%f\n", duration);
	//}

	getchar();
}
