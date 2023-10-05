#include<iostream>
using namespace std;
void quickSort(int A[], int l, int r);
int main ()
{
	int A[10]={5,6,11,13,5,7,12},n=7;
	quickSort(A,0,n-1);
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
 	return 0;
}
void quickSort(int A[], int l, int r){
	int i=l;
	int j=r;
	int mid=(r+l)/2;
	int x=A[mid];
//	cout<<mid<<endl;
	while(i<=j){
		while(A[i]<x)
			i++;
		while(A[j]>x)
			j--;
		if(i<=j){
			swap(A[i],A[j]);
			i++;
			j--;
		}
	}
	if(l<j)
		quickSort(A,l,j);
	if(i<r)
		quickSort(A,i,r);
}

