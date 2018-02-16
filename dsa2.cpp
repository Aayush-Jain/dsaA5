#include <iostream>
using namespace std;

int BS(int A[],int n,int x){
	int low = 0,high = n-1;
	while(low<=high){
		int mid = (low + high)/2;
		if(A[mid] == x) return mid;
		if(A[mid] <= A[high]){
			if(x > A[mid] && x <= A[high]) low = mid+1;
			else high = mid-1;
		}
		else if(A[low] <= A[mid]){
			if(x > A[low] && x <= A[high]) high = mid-1;
			else low = mid+1;
		}
	}
	return -1;
}
int main(){
	int n,x; cin >> n >> x;
	int A[100]; for(int i=0;i<n;i++) cin >> A[i];
	cout << BS(A,n,x);
	return 0;
}