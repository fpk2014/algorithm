#include <iostream>

using std::cout;
using std::endl;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void InsertSort(int *a, const int length){
	for(int i=1; i<length; i++){
		int tmp = a[i];
		int j = i-1;
		while(j>0 && a[j] > tmp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
		print(a, length);
	}
}


int main(){
	const int length = 5;
	int my_array[length] = {1,5,4,3,7};	
	print(my_array, length);

	InsertSort(my_array, length);


	return 0;
}
