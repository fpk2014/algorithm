#include <iostream>

using std::cout;
using std::endl;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void QuickSort(int a[], const int low, const int high)  {  
	if (low< high){        
		int i = low, j = high, x = a[low];  
        	while (i < j){  
			while(i < j && a[j]>= x) // 从右向左找第一个小于x的数  
		       		j--;   
            		if(i < j)  
             	  		a[i++] = a[j];  
			while(i < j && a[i]< x)  // 从左向右找第一个大于等于x的数  
                		i++;   
            		if(i < j)  
              	 	 	a[j--] = a[i];  
        	}  
        	a[i] = x;  
		QuickSort(a, low, i - 1); 
		QuickSort(a, i + 1, high);  
	}  
}  

int main(){
	const int length = 6;
	int my_array[length] = {12,4,13,3,6,8};	

	QuickSort(my_array, 0, length-1);
	print(my_array, 6);
	return 0;
}
