#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int L[100],R[100];
	for(int i=0;i<n;i++) cin >> L[i] >> R[i];

	int time = 1;
	for(int i=0;i<n;i++){
		if(L[i]<=time && R[i]>=time) cout << time++ << endl;
		else cout << 0 << endl;
	}

	return 0;
} 