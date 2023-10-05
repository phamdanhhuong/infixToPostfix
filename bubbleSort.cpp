#include<bits/stdc++.h>
using namespace std;
int bubbleSort(int A[],int n);
int main ()
{
	int A[10]={1,3,6,3,7,8,10,2,9,4},n=10;
	bubbleSort(A,n);
 	return 0;
}
int bubbleSort(int A[],int n){
//	bool check =true;
//	int i=0;
//	int j;
//	while(check){
//		check=false;
//		i++;
//		for(j=n-1;j>=i;j--){
//			if(A[j-1]<A[j]){
//				swap(A[j],A[j-1]);
//				check=true;
//			}
//		}
//	}
	for(int i=0;i<n;i++){
		for(int j=n-1;j!=i;j--){
			if(A[j-1]<A[j]){
				swap(A[j],A[j-1]);	
		}
		}
	}
	for(int i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
}

