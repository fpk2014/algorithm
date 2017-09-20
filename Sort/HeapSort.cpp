#include <iostream>

using std::cout;
using std::endl;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void HeapSortBase(int *a, const int length){
	for(int i=0; i<length; i++){
/*
		int j, t;
		if(a[i]>a[2*i+1] && 2*i+1<length){
			swap(&a[i], &a[2*i+1]);
			//int tmp = a[2i+1]; a[2i+1] = a[i]; a[i] = tmp;
			j = i; t = (j-1)/2;
			while(a[t]>a[j] && t>=0){
				swap(&a[t], &a[j]);
				j = t;
				t = (t-1)/2;
			}
				
		}
		if(a[i]>a[2*i+2] && 2*i+2<length){
			swap(&a[i], &a[2*i+2]);
			//int tmp = a[2i+2]; a[2i+2] = a[i]; a[i] = tmp;
			j = i; t = (j-1)/2;
			while(a[t]>a[j] && t>=0){
				swap(&a[t], &a[j]);
				j = t;
				t = (t-1)/2;
			}
		}
*/
		int dad = i; 
		int dad_father;
		//两个子节点与父节点分别进行比较
		for(int plus=1; plus<3; plus++){
			int son = 2*dad+plus;
			// 父节点大于子节点
			if(a[dad]>a[son] && son<length){
				swap(&a[dad], &a[son]);   
				//判断父节点是否小于它的父节点
				do{
					dad_father = (dad-1)/2;
					swap(&a[dad_father], &a[dad]);
				}while(a[dad_father]>a[dad] && dad_father>=0);				
			}
		}

	}
}

void HeapSort(int *a, const int length){
	for(int i=0; i<length; i++){
		//父节点是最小的
		HeapSortBase(a+i, length-i);
	}
}

int main(){
	const int length = 7;
	int my_array[length] = {61,65,21,48,27,36,24};	

	HeapSort(my_array, length);
	print(my_array, length);

	//print(my_array, length);

	return 0;
}
