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
void KhoiTao(LINKEDLIST &List);
NODE*CreateNode(int x);
void AddFirst(LINKEDLIST &List,NODE*p);
void AddLast(LINKEDLIST &List,NODE*p);
void AddNode(LINKEDLIST &List,NODE*p,NODE*q);
void RemoveFirst(LINKEDLIST &List);
void RemoveLast(LINKEDLIST &List);
void RemoveNodeSauQ(LINKEDLIST &List, NODE* p);
NODE* SearchNode(LINKEDLIST &List,int x);
void RemoveX(LINKEDLIST &List,int x);
bool IsEmptyList(LINKEDLIST &List);
void printList(LINKEDLIST List);
bool IsUnderFive(NODE*p);
void RemoveUnderFive(LINKEDLIST &List);
NODE* MaxList(LINKEDLIST &List);
NODE* MinList(LINKEDLIST &List);
void MaxFirstMinLast(LINKEDLIST &List);
int main ()
{
	LINKEDLIST List;
	KhoiTao(List);
	//them danh sach
	NODE*a=CreateNode(9);
	AddFirst(List,a);
	NODE*b=CreateNode(7);
	AddFirst(List,b);
	NODE*c=CreateNode(1);
	AddFirst(List,c);
	NODE*d=CreateNode(10);
	AddFirst(List,d);
	NODE*e=CreateNode(5);
	AddFirst(List,e);
	NODE*f=CreateNode(4);
	AddFirst(List,f);
	NODE*g=CreateNode(8);
	AddFirst(List,g);
	NODE*h=CreateNode(3);
	AddFirst(List,h);
	NODE*x=CreateNode(2);
	AddFirst(List,x);
	NODE*y=CreateNode(6);
	AddFirst(List,y);
	printList(List);
	//Xoa Diem duoi 5
	RemoveUnderFive(List);
	printList(List);
	//
	MaxFirstMinLast(List);
	printList(List);
 	return 0;
}
void MaxFirstMinLast(LINKEDLIST &List){
	NODE*max=MaxList(List);
	NODE*min=MinList(List);
	if(max==List.Head){
	}else{
		int temp=max->data;
		max->data=List.Head->data;
		List.Head->data=temp;
	}
	if(min==List.Tail){
	}else{
		int temp=min->data;
		min->data=List.Tail->data;
		List.Tail->data=temp;
	}
	
}
NODE* MinList(LINKEDLIST &List){
	NODE*p=List.Head->next;
	NODE*Min=List.Head;
	while(p!=NULL){
		if(p->data<Min->data){
			Min=p;
		}
		p=p->next;
	}
	return Min;	
}
NODE* MaxList(LINKEDLIST &List){
	NODE*p=List.Head->next;
	NODE*Max=List.Head;
	while(p!=NULL){
		if(p->data>Max->data){
			Max=p;
		}
		p=p->next;
	}
	return Max;	
}
void RemoveUnderFive(LINKEDLIST &List){
	while(IsUnderFive(List.Head))
		RemoveFirst(List);
	while(IsUnderFive(List.Tail))
		RemoveLast(List);
	NODE*p=List.Head;
	while(p->next!=NULL){
		if(IsUnderFive(p->next))
			RemoveNodeSauQ(List,p);
		else
			p=p->next;
	}	
}
bool IsUnderFive(NODE*p){
	if(p->data<5)
		return true;
	return false;
}
void printList(LINKEDLIST List){
	for(NODE*i=List.Head;i!=NULL;i=i->next){
		cout<<i->data<<" ";
	}
	cout<<endl;
}
bool IsEmptyList(LINKEDLIST &List){
	if(List.Head==NULL){
		return true;
	}else{
		return false;
	}
}
NODE* SearchNode(LINKEDLIST &List,int x){
	NODE*i;
	for(i=List.Head;i!=NULL;i=i->next){
		if(i->data==x){
			return i;
		}
	}
	return NULL;
}
void RemoveX(LINKEDLIST &List,int x){
	if(IsEmptyList(List)){
		cout<<"mang rong\n";
		return ;
	}
	if(List.Head->data==x){
		RemoveFirst(List);
		return;
	}
	NODE*i;
	NODE*j=NULL;
	for(i=List.Head;i!=NULL;i=i->next){
		if(i->data==x)
			break;
		j=i;
	}
	if(i==NULL){
		cout<<"x does not exist\n";
		return;
	}else if(j!=NULL){
		RemoveNodeSauQ(List,j);
	}
}
void RemoveNodeSauQ(LINKEDLIST &List, NODE* p){
	NODE*q=p->next;
	if(q==NULL){
		cout<<"khong co phan tu sau\n";
	}else{
		p->next=q->next;
		if(q->next==NULL){
			List.Tail=p;
		}
		delete q;
	}
}
void RemoveLast(LINKEDLIST &List){
	if(IsEmptyList(List)){
		cout<<"List is empty !"<<endl;
	}else{
		NODE*p=List.Tail;
		if(List.Head==List.Tail)
			List.Head=List.Tail=NULL;
		else{
			NODE*i;
			for(i=List.Head;i->next!=List.Tail;i=i->next){
				
			}
			i->next=NULL;
			List.Tail=i;
		}
		delete p;
	}
}
void RemoveFirst(LINKEDLIST &List){
	if(IsEmptyList(List)){
		cout<<"danh sach rong"<<endl;
	}else{
		NODE*p=List.Head;
		if(List.Head==List.Tail)
			List.Head=List.Tail=NULL;
		else
			List.Head=List.Head->next;
		delete p;
	}
}
void AddNode(LINKEDLIST &List,NODE*p,NODE*q){
	if(IsEmptyList(List)){
		List.Head=List.Tail=p;
		return;
	}
	p->next=q->next;
	q->next=p;
	if(List.Tail==q)
		List.Tail=p;
}
void AddLast(LINKEDLIST &List,NODE*p){
	if(IsEmptyList(List)==true){
		List.Head=List.Tail=p;
	}else{
		List.Tail->next=p;
		List.Tail=p;
	}
}
void AddFirst(LINKEDLIST &List,NODE*p){
	if(IsEmptyList(List)==true){
		List.Head=List.Tail=p;
	}else{
		p->next=List.Head;
		List.Head=p;
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
void KhoiTao(LINKEDLIST &List){
	List.Head=List.Tail=NULL;
} 
