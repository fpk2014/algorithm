#include <iostream>

using std::cout;
using std::endl;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void Merge(int *r, int *rf, 
		int i, int m,
		int n){
	int j,k;  
	//r[i,m]...r[m+1,n] --> rf[i, n]
	for(j=m+1,k=i; i<=m && j <=n; k++){  
		if(r[j] < r[i]) 
			rf[k] = r[j++];  
        	else 
			rf[k] = r[i++];  
    	}  
	//判断未处理完的子表
	//将尚未处理完的子表中元素存入rf
	while(i <= m)  rf[k++] = r[i++];  
	while(j <= n)  rf[k++] = r[j++];  
}

void MergeSort(int *r, int *rf, const int length){
	int len = 1;    
	while(len < length) {  
		int division = len;  
        	len = 2 * division;  
       		int i = 0;  
     	 	while(i+len < length){  
        		Merge(r, rf, i, i+division-1, i+len-1 ); //合并等长的两个子表
            		i = i + len;  
        	}
        	if(i-len+division < length){  
            		Merge(r, rf, i, i+division-1, length-1); //合并不等长的两个子表
        	}  
        	int *tmp = r; r = rf; rf = tmp; //交换q,rf，以保证下一趟归并时，仍从r归并到rf
    	}  
}




int main(){
	const int length = 7;
	int my_array[length] = {12, 4, 34, 6, 8, 65, 3};	
	int arr[length];
	MergeSort(my_array, arr, length);
	print(arr, length);
	return 0;
}
