#include<iostream>
#include<string.h>
#include<fstream>
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
struct STACK{
	char A[MAX];
	int top;
};
bool IsEmptyStack(STACK myS);
void InitStack(STACK& S);
bool IsFullStack(STACK myS);
void Push(STACK& myS,char x);
char Pop(STACK& myS);
char Top(STACK& myS);
void postFix(STACK input,STACK& post);
void preFix(STACK input,STACK& post);
int main ()
{
	////input
	STACK inputStack;
	InitStack(inputStack);
	gets(inputStack.A);
	inputStack.top=strlen(inputStack.A)-1;
	////	
	STACK post;
	InitStack(post);
	STACK pre;
	InitStack(pre);
	postFix(inputStack,post);
	preFix(inputStack,pre);
	cout<<"prefix  "<<pre.A<<endl;
	cout<<"postfix  "<<post.A<<endl;
 	return 0;
}
void postFix(STACK input,STACK& post){
	STACK op;
	InitStack(op);
	char rac;
	for(int i=0;i<strlen(input.A);i++){
		if(input.A[i]=='('){
			Push(op,input.A[i]);
		}else if(input.A[i]==')'){
			while(Top(op)!='('){
				Push(post,Pop(op));
			}
			rac=Pop(op);
		}else if(input.A[i]=='^'){
			Push(op,input.A[i]);
		}else if(input.A[i]=='*'||input.A[i]=='/'){
			while(Top(op)=='^'||Top(op)=='*'||Top(op)=='/'){
				Push(post,Pop(op));
			}
			Push(op,input.A[i]);
		}else if(input.A[i]=='+'||input.A[i]=='-'){
			while(Top(op)=='*'||Top(op)=='/'||Top(op)=='+'||Top(op)=='-'){
				Push(post,Pop(op));
			}
			Push(op,input.A[i]);
		}else{
			Push(post,input.A[i]);
		}
	}
	while(!IsEmptyStack(op)){
		//cout<<"Top op "<<Top(op)<<endl;
		Push(post,Pop(op));
		//cout<<"post "<<post.A<<endl;
	}
}
void preFix(STACK input,STACK& pre){
	STACK op;
	InitStack(op);
	char rac;
	for(int i=strlen(input.A)-1;i>=0;i--){
		if(input.A[i]==')'){
			Push(op,')');
		}else if(input.A[i]=='('){
			while(op.A[op.top]!=')'){
				Push(pre,Pop(op));
			}
			rac=Pop(op);//xoa ngoac;
		}else if(input.A[i]=='^'){
			Push(op,input.A[i]);
		}else if(input.A[i]=='*'||input.A[i]=='/'){
			while(Top(op)=='^'){
				Push(pre,Pop(op));
			}
			Push(op,input.A[i]);
		}else if(input.A[i]=='+'||input.A[i]=='-'){
			while(Top(op)=='*'||Top(op)=='/'||Top(op)=='^'){
				Push(pre,Pop(op));
			}
			Push(op,input.A[i]);
		}else{
			Push(pre,input.A[i]);
			//cout<<"dang chay "<<input.A[i]<<endl;
		}
	}
	while(!IsEmptyStack(op)){
		Push(pre,Pop(op));
	}
	reverse(pre.A, pre.A + strlen(pre.A));
}
bool IsEmptyStack(STACK myS){
	if(myS.top==-1)
		return true;
	return false;
}
bool IsFullStack(STACK myS){
	if(myS.top==MAX-1)
		return true;
	return false;
}
char Top(STACK& myS){
	if(IsEmptyStack(myS)){
		//cout<<"Stack is empty\n";
	}else{
		char x= myS.A[myS.top];
		return x;
	}
}
char Pop(STACK& myS){
	if(IsEmptyStack(myS)){
		//cout<<"Stack is empty\n";
	}else{
		char x= myS.A[myS.top];
		myS.top--;
		return x;
	}
}
void Push(STACK& myS,char x){
	if(IsFullStack(myS)){
		cout<<"stack is full ";
	}else{
		myS.A[myS.top+1]=x;
		myS.top++;
		myS.A[myS.top+1]=NULL;
	}
}
void InitStack(STACK& S){
	S.top=-1;
}
