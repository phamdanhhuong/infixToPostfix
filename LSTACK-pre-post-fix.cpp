#include <bits/stdc++.h>
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
NODE* Pop(LINKEDSTACK& myS);
void printStack(LINKEDSTACK myS);
void nhap(string input,LINKEDSTACK& inputStack);
void postFix(LINKEDSTACK inputStack,LINKEDSTACK& post);
void Reverse(LINKEDSTACK& myS);
int main ()
{
	string input;
	cin>>input;
	LINKEDSTACK main;
	Init(main);
	LINKEDSTACK inputStack;
	Init(inputStack);
	nhap(input,inputStack);
	postFix(inputStack,main);
	printStack(main);
 	return 0;
}
void postFix(LINKEDSTACK inputStack,LINKEDSTACK& post){
	LINKEDSTACK op;
	Init(op);
	NODE*p;
	while(inputStack.Top!=NULL){
		if(inputStack.Top->data=="("){
			Push(op,Pop(inputStack));
		}else if(inputStack.Top->data==")"){
			while(op.Top->data!="("){
				Push(post,Pop(op));
			}
			Pop(op);
			Pop(inputStack);
		}else if(inputStack.Top->data=="^"){
			Push(op,Pop(inputStack));
		}else if(inputStack.Top->data=="*"||inputStack.Top->data=="/"){
			if (op.Top == NULL) {
				Push(op, Pop(inputStack));
			}else {
				while(op.Top->data=="*"||op.Top->data=="/"||op.Top->data=="^"){
					Push(post,Pop(op));
					if (op.Top == NULL)
						break;
				}
				Push(op, Pop(inputStack));
			}
		}else if(inputStack.Top->data=="+"||inputStack.Top->data=="-"){
			if (op.Top == NULL) {
				Push(op, Pop(inputStack));
			}else {
				while(op.Top->data=="*"||op.Top->data=="/"||op.Top->data=="^"||op.Top->data=="+"||op.Top->data=="-"){
					Push(post,Pop(op));
					if (op.Top == NULL)
						break;
				}
				Push(op, Pop(inputStack));
			}
		}else{
			Push(post,Pop(inputStack));
		}
	}
	while(op.Top!=NULL){
		Push(post,Pop(op));
	}
	Reverse(post);
}
void Reverse(LINKEDSTACK& myS){
	LINKEDSTACK tam;
	tam=myS;
	Init(myS);
	while(tam.Top!=NULL){
		Push(myS,Pop(tam));
	}
	cout<<endl;
}
void nhap(string input,LINKEDSTACK& inputStack){
	reverse(input.begin(),input.end());
	string tam="";
	for(int i=0;i<input.length();i++){
		if(input[i]>='0'&&input[i]<='9'){
			while(input[i]>='0'&&input[i]<='9'){
				tam+=input[i];
				i++;
			}
			reverse(tam.begin(),tam.end());
			NODE*p=CreateNode(tam);
			Push(inputStack,p);
			tam="";
			i--;
		}else{
			tam=input[i];
			NODE*p=CreateNode(tam);
			Push(inputStack,p);
			tam="";
		}
	}
}
void printStack(LINKEDSTACK myS){
	for(NODE*i=myS.Top;i!=NULL;i=i->next){
		cout<<i->data;
	}
	cout<<endl;
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
NODE* Pop(LINKEDSTACK& myS){
	if(myS.Top==NULL)
		cout<<"stack is empty";
	else{
		NODE*p=myS.Top;
		myS.Top=myS.Top->next;
		p->next=NULL;
		return p;
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
