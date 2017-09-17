#include <iostream>

using std::cout;
using std::endl;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void SelectSort(int *a, const int length){
	for(int i=0; i<length; i++){
		for(int j=i; j<length; j++){
			if(a[i] > a[j]){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
		print(a, length);
	}
}

int main(){
	const int length = 5;
	int my_array[length] = {1,3,5,4,2};
	SelectSort(my_array, length);

	return 0;
}
