// day con tang dai nhat 
// vd 1 2 5 4 6 3 => op: 4 do day con tang lon nhat la 1 2 4 6 co 4 ptu

#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, ans=0;
	cin >> n;
	int a[n], f[10005]; // f[n] la day con tang dai nhat den n
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(int i = 1; i <= n; i++){
		f[i] = 1;
		for(int j = 1; j <= i; j++){
			if(a[j] < a[i]){
				if(f[j]+1 > f[i]) f[i] = f[j]+1;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(f[i] > ans) ans = f[i];
	}
	cout << ans;
}
