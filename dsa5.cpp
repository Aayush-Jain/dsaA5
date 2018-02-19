// median of medians 
#include <iostream>
using namespace std;

void swap(int A[],int i,int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
int Partition(int A[],int p,int r){
	int x = A[r],i = p-1;
	for(int j=p;j<r;j++) if(A[j]<x) swap(A,++i,j);
	swap(A,i+1,r);
	return i+1;
}
void sort(int A[],int p,int r){
	if(p<r){
		int q = Partition(A,p,r);
		sort(A,p,q-1);
		sort(A,q+1,r);
	}
}
int medians(int A[],int M[],int n){
	int j=0 , t=n/5;
	for(int i=0;i<t;i++){
		sort(A,j,j+4);
		M[i] = A[j+2];
		//cout << "starts at " << j << " " << "ends at " << j+4 << " " << "median is" << M[i] << endl;
		j=j+5;
	}
	int remainder = n%5;
	if(remainder!=0){
		sort(A,t*5,n);
		if(remainder%2==1) M[t] = A[t*5+(remainder/2)];
		else M[t] = A[t*5+(remainder/2)-1];
	}

	return t + 1;
}

int main(){
	int n; cin >> n;
	int A[1000];for(int i=0;i<n;i++) cin >> A[i];
	int M[500];
	int len = medians(A,M,n);
	
	sort(M,0,len-1);
	
	for(int i=0;i<len;i++) cout << M[i] << " ";
	cout << endl;
	
	if(len%2==1) cout << M[len/2];
	else cout << M[len/2-1];

	return 0;

}