#include <iostream>

using std::cout;
using std::endl;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

void max_heapify(int arr[], int start, int end) {
	//建立父節點指標和子節點指標
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) { //若子節點指標在範圍內才做比較
		if (son + 1 <= end && arr[son] < arr[son + 1]) //先比較兩個子節點大小，選擇最大的
			son++;
		if (arr[dad] > arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
			return;
		else { //否則交換父子內容再繼續子節點和孫節點比較
			swap(&arr[dad], &arr[son]);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void heap_sort(int arr[], int len) {
	int i;
	//初始化，i從最後一個父節點開始調整
	for (i = len / 2 - 1; i >= 0; i--){
		max_heapify(arr, i, len - 1);
		print(arr, len);
	}
	//先將第一個元素和已排好元素前一位做交換，再從新調整，直到排序完畢
	for (i = len - 1; i > 0; i--) {
		swap(&arr[0], &arr[i]);
		max_heapify(arr, 0, i - 1);
		print(arr, len);
	}
}

int main(){
	const int length = 7;
	int my_array[length] = {61,65,21,48,27,36,24};
	heap_sort(my_array, length);
	print(my_array, length);

	return 0;
}
