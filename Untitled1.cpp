#include<iostream>
#include<string>
#include<sstream>
using namespace std;
struct chu{
	string n;
};
int soSanh(string str1,string str2);
bool kt(chu M[20],int n);
int main ()
{
	string str1,str2;
	int dem=0;
	getline(cin,str1);
	getline(cin,str2);
	dem=soSanh(str1,str2);
	cout<<dem;
 	return 0;
}
bool kt(chu M[20],int n){
	for(int i=0;i<n-1;i++){
		if(M[i].n==M[n-1].n)
			return false;
	}
	return true;
}
int soSanh(string str1,string str2){
	// tach tu
	stringstream s1(str1);
	stringstream s2(str2);
	chu ss1[20];
	int m=0;
	chu ss2[20];
	int n=0;
	while(s1>>ss1[m].n){
		if(kt(ss1,m+1)==true){
			m++;
		}
	}
	while(s2>>ss2[n].n){
		if(kt(ss2,n+1)==true){
			n++;
		}
	}
	//so sanh
	int dem =0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(ss1[i].n==ss2[j].n){
				dem++;
			}
		}
	}
	return dem;
}
