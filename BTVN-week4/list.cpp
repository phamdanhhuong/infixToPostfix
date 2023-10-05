#include<iostream>
#define MAX 100
using namespace std;
struct List{
	int A[MAX];
	int n;
};
bool isFullList(List num);
void initList(List &num);
void addDau(List &num,int x);
void addCuoi(List &num,int x);
void Add(List &num,int x,int k);
void removeItemByIndex(List &num,int k);
void PrintList(List num);
void removeUnderFive(List &num);
void MaxFirstMinLast(List &num);
int main ()
{
	List num;
	initList(num);
	addDau(num,9);
	addDau(num,7);
	addDau(num,1);
	addDau(num,10);
	addDau(num,5);
	addDau(num,4);
	addDau(num,8);
	addDau(num,3);
	addDau(num,2);
	addDau(num,6);
	PrintList(num);
	removeUnderFive(num);
	PrintList(num);
	MaxFirstMinLast(num);
	PrintList(num);
 	return 0;
}
void MaxFirstMinLast(List &num){
	int maxIndex=0;
	int minIndex=0;
	for(int i=1;i<num.n;i++){
		if(num.A[i]>num.A[maxIndex]){
			maxIndex=i;	
		}
		if(num.A[i]<num.A[minIndex]){
			minIndex=i;	
		}
	}
	if(maxIndex==0){
		
	}
	else{
		int max=num.A[maxIndex];
		num.A[maxIndex]=num.A[0];
		num.A[0]=max;
	}
	if(minIndex==num.n-1){
		
	}
	else{
		int min=num.A[minIndex];
		num.A[minIndex]=num.A[num.n-1];
		num.A[num.n-1]=min;
	}
}
void removeUnderFive(List &num){
	for(int i=0;i<num.n;i++){
		if(num.A[i]<5){
			removeItemByIndex(num,i);
			i--;
		}
	}
}
void PrintList(List num){
	for(int i=0;i<num.n;i++){
		cout<<num.A[i]<<" ";
	}
	cout<<endl;
}
void removeItemByIndex(List &num,int k){
	for(int i=k;i<num.n-1;i++){
		num.A[i]=num.A[i+1];
	}
	num.n--;
}
void Add(List &num,int x,int k){
	if(isFullList(num)){
		cout<<"the list is full";
	}else{
		for(int i=num.n;i>k;i--){
			num.A[i]=num.A[i-1];
		}	
		num.A[k]=x;
		num.n++;
	}
}
void addDau(List &num,int x){
	if(isFullList(num)){
		cout<<"the list is full";
	}else{
		for(int i=num.n;i>0;i--){
			num.A[i]=num.A[i-1];
		}	
		num.A[0]=x;
		num.n++;
	}
}
void addCuoi(List &num,int x){
	if(isFullList(num)){
		cout<<"the list is full";
	}else{
		num.A[num.n]=x;
		num.n++;
	}
}
void initList(List &num){
	num.n=0;
}
bool isFullList(List num){
	if(num.n==MAX){
		return true;
	}else{
		return false;
	}
}
