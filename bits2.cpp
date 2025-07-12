//binary exponentiation
#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int binaryExponentiationRecursive(int a,int b){
	if(b==0) return 1;
	int res=binaryExponentiationRecursive(a,b/2);
	if(b&1){
		return (a*((res*res*1LL)%mod))%mod;
	}
	else{
		return (res*res*1LL)%mod;
	}
}
int main(){
	int a=2,b=13;
	cout<<binaryExponentiationRecursive(a,b)<<endl;

}