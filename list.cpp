#include<iostream>
#define MAX 100
using namespace std;
struct List{
	int A[MAX];
	int n;
};
bool isFullList(List num);
void initList(List &num);
void addFirst(List &num,int x);
void addLast(List &num,int x);
void Add(List &num,int x,int k);
void removeItemByIndex(List &num,int k);
int main ()
{
	List num;
	initList(num);
	cout<<isFullList(num)<<endl;
	addFirst(num,1);
	addLast(num,3);
	Add(num,2,1);
	removeItemByIndex(num,2);
	for(int i=0;i<num.n;i++){
		cout<<num.A[i]<<" ";
	}
 	return 0;
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
void addFirst(List &num,int x){
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
void addLast(List &num,int x){
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
