#include <bits/stdc++.h>
using namespace std;
void merge_utility(int ar[],int left,int right,int mid){
	int left_size=mid-left+1;//left part of array size
	int right_size=right-mid;//right part array size
	
	//MAKING SUBARARYS LEFT AND RIGHT
	int left_array[left_size+1]; //+1 is becoz indexing is from 0
	int right_array[right_size+1];//+1 is becoz indexing is from 0

	//NOW PUTTING ELEMNTS IN SUBARARYS
	for(int i=0;i<left_size;i++){
		left_array[i]=ar[i+left];
	}
	for(int i=0;i<right_size;i++){
		right_array[i]=ar[i+mid+1];
	}

	//NOTE:INT_MAX is for our convienece read notes
	left_array[left_size]=right_array[right_size]=INT_MAX;
	

	int left_index=0,right_index=0;
	for (int i =left; i <=right; i++)
	{
		if(left_array[left_index]<=right_array[right_index]){
			ar[i]=left_array[left_index];
			left_index++;
		}
		else{
			ar[i]=right_array[right_index];
			right_index++;

		}
	}

}
void merge_sort(int ar[],int left,int right){
	//base case if two elemnts are equal then nothing to sort
	if(left==right) {
		return;
	}
	//to sort two sub arrays
	int mid=(left+right)/2;
	merge_sort(ar,left,mid);//from left to mid
	merge_sort(ar,mid+1,right);//from mid+1 to right

	merge_utility(ar,left,right,mid);//this is to merge the both subarrays

}
void print(int ar[],int size){
	for (int i = 0; i <size; ++i)
	{
		cout<<ar[i]<<" ";
	}
}
int main(){
	int size=5;
	int ar[]={4,5,1,2,3};
	cout<<"UNSORTED: ";
	print(ar,size);
	merge_sort(ar,0,size-1);
	cout<<endl<<"SORTED: ";
	print(ar,size);
	return 0;
}