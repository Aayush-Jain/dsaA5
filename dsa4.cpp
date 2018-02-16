#include <iostream>
using namespace std;

int main(){
	int A[10][10];int k=1,n,m,r;
	cin >> n >> m >> r;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> A[i][j];	
    
    for(int k=0;k<r;k++){
	    int temp ; int lr = 0 , hr = n-1, lc = 0 , hc = m-1;
		while(lr<hr && lc<hc){
			temp = A[lr][lc];
			
			for(int j=1+lc;j<=hc;j++) A[lr][j-1] = A[lr][j];
			lr++;
			
			for(int i=lr;i<=hr;i++) A[i-1][hc] = A[i][hc];
			hc--;	

			for(int j=hc;j>=lc;j--) A[hr][j+1] = A[hr][j];
			hr--;
			
			for(int i=hr;i>=lc;i--) A[i+1][lc] = A[i][lc];
			lc++;
			
			A[lr][lc-1] = temp;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cout << A[i][j] << " ";
		cout << endl;
	}
	return 0;
}