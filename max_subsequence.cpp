#include <bits/stdc++.h>

using namespace std;

int maximum(int a, int b){
	if(a>b) return a;
	return b;
}

int main(){
	int n;
	cin >> n;
	int a[n+1];
	for(int i = 1; i <= n; i++) cin >> a[i];
	int f[n+1];
	f[1] = a[1];
	for(int i = 2; i <= n; i++){
		f[i] = maximum(f[i-1] + a[i], a[i]);
	}
	
	int tmp = -1e3;
	for(int i = 1; i <= n; i++){
		if(f[i] > tmp) tmp = f[i];
	}
	cout << tmp;
	return 0;
}
