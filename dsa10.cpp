#include <iostream>
#include <math.h>
using namespace std;

int factors(int n){
	int value = 1;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			int count = 1;
			while(n%i==0){
				n = n/i;
				count++;
			}
			value = value * count;
		}
	}
	if(n!=1) value = value * 2;
	return value;
}

int main(){
	int a,b,n,count=0; cin >> a >> b >> n;
	for(int i=a;i<=b;i++){
		if(factors(i)==n) count++;
	}
	cout << count;
	return 0;
}