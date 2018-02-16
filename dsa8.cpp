#include <iostream>
#include <string.h>
using namespace std;

struct node
{
	int sum;
	char str[100];
};
void update_sum(struct node A[],int n){
	for(int i=0;i<n;i++){
		char string[100]; strcpy(string,A[i].str);
		for(int j=0;j<strlen(A[i].str);j++) A[i].sum = A[i].sum + string[j];
	}
}
void swap_sum(struct node A[],int i,int j){
	int temp = A[i].sum;
	A[i].sum = A[j].sum;
	A[j].sum = temp;
}
void swap_str(struct node A[],int i,int j){
	char temp[100];
	strcpy(temp,A[i].str);
	strcpy(A[i].str,A[j].str);
	strcpy(A[j].str,temp);
}
int fn(int n){
	int count = 0;
	while(n>0){
		if(n%2==1) count++;
		n = n/2;
	}
	return count;
}
void sort(struct node A[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(fn(A[i].sum)>fn(A[j].sum)){
				swap_sum(A,i,j);
				swap_str(A,i,j);
			}
		}
	}
}
int main(){
	int n; cin >> n;
	struct node A[100];
	for(int i=0;i<n;i++){
		cin >> A[i].str;
		A[i].sum = 0; 
	}
	update_sum(A,n);
	sort(A,n);
	for(int i=0;i<n;i++){
		cout << A[i].str <<" "<< A[i].sum <<endl;
	}
	
	return 0;
}