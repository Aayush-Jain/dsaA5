#include <iostream>
using namespace std;

int FindMax(int A[][100],int rows,int mid,int* max){
	int max_index = 0;
	for(int i=0;i<rows;i++){
		if(*max < A[i][mid]){
			*max = A[i][mid];
			max_index = i;
		}
	}
	return max_index;
}
int FindPeakRec(int A[][100],int rows,int columns,int mid){

	int max = 0;
	int max_index = FindMax(A,rows,mid,&max);
	if(mid==0 || mid==columns-1) return max;
	if(max>=A[max_index][mid-1] && max >= A[max_index][mid+1]) return max;
	if(max < A[max_index][mid-1]) return FindPeakRec(A,rows,columns,mid-mid/2);
	else return FindPeakRec(A,rows,columns,mid+mid/2);	
}
int FindPeak(int A[][100],int rows,int columns){
	return FindPeakRec(A,rows,columns,columns/2);
}
int main(){
	int n,m; cin >> n >> m;
	int A[100][100];
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];
	cout << FindPeak(A,n,m);
		

	return 0;
}