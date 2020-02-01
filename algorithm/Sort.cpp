#include<iostream>
#include"Student.h"
#include"SortTestHelper.h"
using namespace std;
template<typename T>
void selectionSort(T arr[],int n){
	for(int i=0;i<n;i++){
		int minIndex=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[minIndex]){
			minIndex=j;
			}
		}
		swap(arr[i],arr[minIndex]);
	}
}
template<typename T>
void insertionSort(T arr[],int n){
	for(int i=1;i<n;i++){
		for(int j=i;j>0&&arr[j]<arr[j-1];j--){
			swap(arr[j],arr[j-1]);
		}
	}
}

int main(){
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	selectionSort(a,10);
	for(int i=0;i<10;i++){
		cout<<a[i]<<"  ";
	}
	cout<<endl;
	float b[4]={4.4,3.3,2.2,1.1};
	selectionSort(b,4);
	for(int i=0;i<4;i++){
		cout<<b[i]<<"  ";
	}
	cout<<endl;
	string c[4]={"d","c","b","a"};
	selectionSort(c,4);
	for(int i=0;i<4;i++){
		cout<<c[i]<<"  ";
	}
	cout<<endl;
	Student d[4]={{"d",90},{"c",100},{"b",95},{"a",96}};
	selectionSort(d,4);
	for(int i=0;i<4;i++){
		cout<<d[i];
	}
	cout<<endl;
	int n=10000;
	int *arr=SortTestHelper::generateRandomArray(n,0,n);
	int *arr2=SortTestHelper::copyIntArray(arr,n);
	//selectionSort(arr,n);
	//SortTestHelper::printArray(arr,n);
	SortTestHelper::testSort("Insertion Sort",insertionSort,arr,n);
	SortTestHelper::testSort("Selection Sort",selectionSort,arr2,n);
	cout<<endl;			        
      	delete[] arr;
	delete[] arr2;
	return 0;
}