#include <iostream>
#include <cstring>

using namespace std;
const int MAXSIZE = 20;

void print(int *a, const int length){
	for(int i=0; i<length; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

//参考自：http://www.cnblogs.com/maybe2030/p/4715035.html#_label1
void Fibonacci(int *Fibo){
	Fibo[0] = 0;
	Fibo[1] = 1;
	for(int i=2; i<MAXSIZE; i++){
		Fibo[i] = Fibo[i-1] + Fibo[i-2];
	}
}

int FibonacciSearch(const int *a, 
		    const int length, 
		    const int key){
	int low, mid, high;
	low = 0;
	high = length - 1;

	int Fibo[MAXSIZE];
	Fibonacci(Fibo);

	// 获取斐波那契分割数值下标 
	int k = 0;
	while(length>Fibo[k]-1) 
		k++;

	//将数组a扩展到F[k]-1的长度
	int *tmp;
	tmp = new int [Fibo[k]-1];
	memcpy(tmp,a,length*sizeof(int));

	for(int i=length; i<Fibo[k]-1; i++)
		tmp[i] = a[high];

	while(low<=high){
		mid = low + Fibo[k-1]-1;
		if(key<tmp[mid]){
			high = mid - 1;
			k -= 1;
		}else if(key>tmp[mid]){
			low = mid + 1;
			k -=2;
		}else{ 
			//若mid>=n则说明是扩展的数值,返回n-1
			//若相等则说明mid即为查找到的位置
			if(mid<length)
				return mid;
			else
				return length -1;
		}
	}
	delete[] tmp;
	return -1;
}

int main(){
	const int length = 10;
	int a[length] = {0,16,24,35,47,59,62,73,88,99};
	int key=73;
	int index = FibonacciSearch(a,length,key);
	cout<< key << " is located at:" <<index<<endl;
	return 0;
}
