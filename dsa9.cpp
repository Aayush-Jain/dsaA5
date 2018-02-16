#include <iostream>
using namespace std;

int main(){
	int n,A[100],C[100];cin >> n;
	for(int i=0;i<n;i++) cin >> A[i];
	for(int i=0;i<100;i++) C[i] = 0;
	for(int i=0;i<n;i++) C[A[i]]++;

	int k=0;
	for(int i=0;i<100;i++) if(C[i]%2==1){k++; break;}
	if(k!=0) cout << "Vishal";
	else cout << "Tanmay";
	return 0;
}