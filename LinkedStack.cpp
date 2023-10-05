#include<iostream>
#define MAX 100
using namespace std;
struct NODE{
	string data;
	struct NODE*next;
};
struct LINKEDSTACK{
	NODE*Top;
};
NODE*CreateNode(string x);
void Init(LINKEDSTACK& myS);
void Push(LINKEDSTACK& myS,NODE*p);
int Pop(LINKEDSTACK& myS);
int main ()
{

 	return 0;
}
NODE*CreateNode(string x){
	NODE*p=new NODE;
	if(p==NULL){
		cout<<"Khong du bo nho\n";
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}
int Pop(LINKEDSTACK& myS){
	if(myS.Top==NULL)
		cout<<"stack is empty";
	else{
		NODE*p=myS.Top;
		int data=myS.Top->data;
		myS.Top=myS.Top->next;
		delete p;
	}
}
void Init(LINKEDSTACK& myS){
	myS.Top=NULL;
}
void Push(LINKEDSTACK& myS,NODE*p){
	if(myS.Top==NULL){
		myS.Top=p;
	}else{
		p->next=myS.Top;
		myS.Top=p;
	}
}
