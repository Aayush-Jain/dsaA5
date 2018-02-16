/* this is for first question
1. step1 : Get all the possible substrings of the given string.
2. step2 : calculate the number of times that substring is present in the main string.
3. step3 : keep track of the maximum F(s). 
*/

#include <iostream>
#include <string.h>
using namespace std;

int naive_stringmatch(char T[],char P[],int m){
	int n = strlen(T),count = 0;
	for(int i=0;i<=n-m;i++){
		if(P[0]==T[i]){
			int k = 1;
			while(k<m){
				if(P[k]==T[i+k])k++;
				else break;
			}
			if(k==m) count++;
		}
	}
	return count;
}
int substrings(char T[],int n){
	int max = 0;
	for(int len=1;len<=n;len++){
		for(int i=0;i<=n-len;i++){
			int j = i-1+len; 
			char P[1000];
			int count = 0;
			for(int k=i;k<=j;k++){
				P[count] = T[k];
				count++; 
			}
			//for(int t = 0;t<count;t++) cout << P[t];
			int occurrence = naive_stringmatch(T,P,count);
			int value = occurrence * len;
			//cout << " " <<occurrence << " " << value <<endl;
			if(value > max) max = value;
			//cout << endl;
		}
	}
	return max;
}
int main(){
	char T[1000],P[1000];
	cin >> T ;//>> P;
	int len = strlen(T);
	cout << substrings(T,len);
	return 0; 
}