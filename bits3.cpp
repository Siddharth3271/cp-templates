//sieve algorithm
#include<bits/stdc++.h>
using namespace std;

const int N=1e7+10;
vector<bool>isPrime(N,true);  //considering all nos as prime at first

int main(){

	isPrime[0]=isPrime[1]=false;

	for(int i=2;i<N;++i){
		if(isPrime[i]==true){
			for(int j=2*i;j<N;j=j+i){
				isPrime[j]=false;
			}
		}
	}

	for(int i=1;i<100;++i){
		cout<<isPrime[i]<<endl;
	}

	int q;
	cin>>q;

	while(q--){
		int num;
		cin>>num;
		if(isPrime[num]){
			cout<<"prime"<<endl;
		}
		else{
			cout<<"not prime"<<endl;
		}
	}

}