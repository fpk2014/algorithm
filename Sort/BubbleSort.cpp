#include <iostream>

using std::cout;
using std::endl;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void BubbleSort(int *a, const int length){
	for(int i=0; i<length-1; i++){
		for(int j=0; j<length-1-i; j++){
			if(j+1<length && a[j]>a[j+1]){
				int tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}


int main(){
	const int length = 8;
	int my_array[length] = {12, 4, 34, 6, 8, 65, 3, 2};	
	
	BubbleSort(my_array, length);
	print(my_array, length);

	return 0;
}
