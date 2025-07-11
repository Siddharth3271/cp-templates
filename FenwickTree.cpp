struct FenwickTree{
	int n;
	vector<int>bit;

	FenwickTree(int size){
		n=size;
		bit.assign(n,0);
	}

	void update(int idx,int value){
		idx++;
		while(idx<=n){
			bit[idx]=(bit[idx]+value);
			idx=idx+(idx&(-idx));
		}
	}

	int sum(int idx){
		idx++;
		int res=0;
		while(idx>0){
			res=(res+bit[idx]);
			idx=idx-(idx&(-idx));
		}

		return res;
	}

	int rangeSum(int l,int r){
		return (sum(r)-sum(l-1));
	}
};
