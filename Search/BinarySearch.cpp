#include <iostream>

using namespace std;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int BinarySearch(const int *a,
				  const int length,
				  const int key){
	int low, mid, high;
	low = 0;
	high = length-1;
	//相等
	while(low <= high){
		mid = (low + high)/2;		//mid = low + (high - low) / 2;
		if(a[mid]==key)
			return mid;
		if(a[mid]>key)
			high = mid - 1;
		if(a[mid]<key)
			low = mid + 1;
	}	
	return -1;
}


int main(){
	const int length = 4;
	int my_array[length] = {1, 2, 4, 5};
	for(int i=0; i<length; i++){
		if(BinarySearch(my_array, length, my_array[i])==-1)
			cout << i << " error" << endl;
	}
}
