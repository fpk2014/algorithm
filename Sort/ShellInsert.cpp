#include <iostream>

using std::cout;
using std::endl;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

//希尔插入其实是插入排序的扩展版
void InsertSort(int *a, const int length, const int division){
	int j, tmp;
	for(int i=division; i<length; i++){
		j = i - division;
		tmp = a[i];
		a[i] = a[i-division];
		while(j>=0 && a[j] > tmp){
			a[j+division] = a[j];
			j = j - division;
		}
		a[j+division] = tmp;
	}
	print(a, length);
}




void ShellSort(int *a, const int length){
	int division = length / 2;
	while(division>=1){
		InsertSort(a, length, division);
		division = division / 2;
	}
}




int main(){
	const int length = 5;
	int my_array[length] = {1,5,4,3,7};	
	print(my_array, length);
	ShellSort(my_array, length);

	
	print(my_array, length);


	return 0;
}
