#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int LinearSearch(const int *a, const int length,
				 const int key){
	for(int i=0; i<length; i++){
		if(a[i] == key){
			return i;
		}
	}
	return -1;
}

int main(){
	srand((unsigned)time(NULL));
	const int length = rand()%10;
	int my_array[length+1];
	for(int i=0; i<length; i++)
		my_array[i] = rand()%10;

	print(my_array, length);
	for(int i=0; i<length; i++){
        if(LinearSearch(my_array, length, my_array[i])==-1)
			cout << i << " error" << endl;
	}
	 
}
