#include <iostream>

using std::cout;
using std::endl;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

//二元选择排序
void SelectSort(int r[],int length){  
 	int i ,j , min ,max, tmp;  
	for (i=0 ;i < length/2;i++){    
		min = i; 
		max = i;
		//find minimum
		for (j= i+1; j< length-i; j++){  
			if (r[j] > r[max]){
				max = j ; 
				continue;  
			}    
            		if (r[j]< r[min]){   
				min = j ;   
         		}
        	}    
        tmp = r[i]; r[i] = r[min]; r[min] = tmp;  
        tmp = r[length-i-1]; r[length-i-1] = r[max]; r[max] = tmp;   
    	}  
} 

int main(){
	const int length = 5;
	int my_array[length] = {1,3,5,4,2};
	SelectSort(my_array, length);
	print(my_array, length);
	return 0;
}
