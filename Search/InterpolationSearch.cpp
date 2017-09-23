#include <iostream>

using namespace std;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

//二分查找提升版, 复杂度O(log2(log2n))
int PolationSearch(const int *a,
				  const int length,
				  const int key){
	int low, mid, high, division;
	low = 0;
	high = length-1;
	//相等
	while(low <= high){
		division = (key-a[low])/(a[high]-a[low]);  //步长
		mid = low + (high - low) * division;
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
		if(PolationSearch(my_array, length, my_array[i])==-1)
			cout << i << " error" << endl;
	}
}
