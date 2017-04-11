#include<iostream>
using namespace std;

int factorial(int n){
	if(n==0){
		return 1;
	}
	int ans = factorial(n-1);
	ans = n*ans;
	return ans;
}

int fibonacci(int n){
	if(n==1 || n==2){
		return 1;
	}
	return fibonacci(n-1) + fibonacci(n-2);
}

int gcd(int a, int b){
	if(b==0){
		return a;
	}
	int ans = gcd(b,a%b);
	return ans;
}

void printArrayVersion()

int main(){
	// cout<<factorial(5)<<endl;
	// cout<<fibonacci(7)<<endl;
	// cout<<gcd(96,504)<<endl;

}
