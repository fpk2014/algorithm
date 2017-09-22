#include <iostream>

using std::cout;
using std::endl;

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
	const int length = 5;
	int my_array[length] = {1,7,3,4,5};

	for(int i=0; i<length; i++){
        if(LinearSearch(my_array, length, my_array[i])==-1)
			cout << i << endl;
	}
	 
}
