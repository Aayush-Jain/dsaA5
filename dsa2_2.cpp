#include <iostream>
using namespace std;

int F(int a,int b){
	int dividend = a;
	int divisor = b;
	while(divisor!=0){
		int remainder = dividend % divisor;
		dividend = divisor;
		divisor = remainder;
	}
	int gcd = dividend;
	int result = (a*b)/gcd;
	return result;
} 
int main(){
	int t; cin >> t;
	for(int i=0;i<t;i++){
		int n; cin >> n;
		int sum = 0;
		for(int j=1;j<=n;j++){
			sum = sum + F(j,n);
		}
		cout << sum << endl;
	}

	return 0;
}