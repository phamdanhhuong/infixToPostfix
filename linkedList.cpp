 #include<iostream>
using namespace std;
struct NODE{
	int data;
	struct NODE*next;
};
struct LINKEDLIST{
	NODE*Head;
	NODE*Tail;
};
void InitList(LINKEDLIST &myList);
NODE*CreateNode(int x);
void AddFirst(LINKEDLIST &myList,NODE*p);
void AddLast(LINKEDLIST &myList,NODE*p);
void AddNode(LINKEDLIST &myList,NODE*p,NODE*q);
void RemoveFirst(LINKEDLIST &myList);
void RemoveLast(LINKEDLIST &myList);
void RemoveNode(LINKEDLIST &myList, NODE* p);
NODE* SearchNode(LINKEDLIST &myList,int x);
void RemoveX(LINKEDLIST &myList,int x);
bool IsEmptyList(LINKEDLIST &myList);
void printList(LINKEDLIST myList);
void QuickSort(LINKEDLIST& myList);
int main ()
{
	LINKEDLIST List;
	InitList(List);
	NODE*p=CreateNode(10);
	AddFirst(List,p);
	NODE*q=CreateNode(12);
	AddLast(List,q);
	NODE*z=CreateNode(11);
	AddNode(List,z,p);
	NODE*a=CreateNode(1);
	AddLast(List,a);
	NODE*b=CreateNode(9);
	AddLast(List,b);
	NODE*c=CreateNode(8);
	AddLast(List,c);
	printList(List);
	QuickSort(List);
	printList(List);
 	return 0;
}
void QuickSort(LINKEDLIST& myList){
	if(IsEmptyList(myList))
		return;
	LINKEDLIST l1,l2;
	InitList(l1);
	InitList(l2);
	NODE*pivot=myList.Head;
	NODE*p;
	myList.Head=myList.Head->next;
	while(myList.Head!=NULL){
		p=myList.Head;
		myList.Head=myList.Head->next;
		p->next=NULL;//co lap p
		if(p->data<=pivot->data)
			AddFirst(l1,p);
		else
			AddFirst(l2,p);
	}
	QuickSort(l1);
	QuickSort(l2);
	if(IsEmptyList(l1)){
		myList.Head=pivot;
	}else{
		myList.Head=l1.Head;
		l1.Tail->next=pivot;
	}
	pivot->next=l2.Head;
	if(IsEmptyList(l2)){
		myList.Tail=pivot;
	}else{
		myList.Tail=l2.Tail;
	}
}
void printList(LINKEDLIST myList){
	for(NODE*i=myList.Head;i!=NULL;i=i->next){
		cout<<i->data<<" ";
	}
	cout<<endl;
}
bool IsEmptyList(LINKEDLIST &myList){
	if(myList.Head==NULL){
		return true;
	}else{
		return false;
	}
}
NODE* SearchNode(LINKEDLIST &myList,int x){
	NODE*i;
	for(i=myList.Head;i!=NULL;i=i->next){
		if(i->data==x){
			return i;
		}
	}
	return NULL;
}
void RemoveX(LINKEDLIST &myList,int x){
	if(IsEmptyList(myList)){
		cout<<"mang rong\n";
		return ;
	}
	if(myList.Head->data==x){
		RemoveFirst(myList);
		return;
	}
	NODE*i;
	NODE*j=NULL;
	for(i=myList.Head;i!=NULL;i=i->next){
		if(i->data==x)
			break;
		j=i;
	}
	if(i==NULL){
		cout<<"x does not exist\n";
		return;
	}else if(j!=NULL){
		RemoveNode(myList,j);
	}
}
void RemoveNode(LINKEDLIST &myList, NODE* p){
	NODE*q=p->next;
	if(q==NULL){
		cout<<"khong co phan tu sau\n";
	}else{
		p->next=q->next;
		if(q->next==NULL){
			myList.Tail=p;
		}
		delete q;
	}
}
void RemoveLast(LINKEDLIST &myList){
	if(IsEmptyList(myList)){
		cout<<"List is empty !"<<endl;
	}else{
		NODE*p=myList.Tail;
		if(myList.Head==myList.Tail)
			myList.Head=myList.Tail=NULL;
		else{
			NODE*i;
			for(i=myList.Head;i->next!=myList.Tail;i=i->next){}
			i->next=NULL;
			myList.Tail=i;
		}
		delete p;
	}
}
void RemoveFirst(LINKEDLIST &myList){
	if(IsEmptyList(myList)){
		cout<<"danh sach rong"<<endl;
	}else{
		NODE*p=myList.Head;
		if(myList.Head==myList.Tail)
			myList.Head=myList.Tail=NULL;
		else
			myList.Head=myList.Head->next;
		delete p;
	}
}
void AddNode(LINKEDLIST &myList,NODE*p,NODE*q){
	if(IsEmptyList(myList)){
		myList.Head=myList.Tail=p;
		return;
	}
	p->next=q->next;
	q->next=p;
	if(myList.Tail==q)
		myList.Tail=p;
}
void AddLast(LINKEDLIST &myList,NODE*p){
	if(IsEmptyList(myList)==true){
		myList.Head=myList.Tail=p;
	}else{
		myList.Tail->next=p;
		myList.Tail=p;
	}
}
void AddFirst(LINKEDLIST &myList,NODE*p){
	if(IsEmptyList(myList)==true){
		myList.Head=myList.Tail=p;
	}else{
		p->next=myList.Head;
		myList.Head=p;
	}
}
NODE*CreateNode(int x){
	NODE*p=new NODE;
	if(p==NULL){
		cout<<"Khong du bo nho\n";
		return NULL;
	}
	p->data=x;
	p->next=NULL;
	return p;
}
void InitList(LINKEDLIST &myList){
	myList.Head=myList.Tail=NULL;
} 
