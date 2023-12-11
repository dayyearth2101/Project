#include <bits/stdc++.h>
#define MAX 100005
/*
5 7 
9 -2 6 2 1 3 4
0 -1 6 7 1 3 3
8 2 8 2 5 3 2
1 -1 6 2 1 6 1
7 -2 6 2 1 3 7

out put: 41 
*/
using namespace std;

int maximum(int a, int b, int c){
	if(a > b){
		if(a > c) return a;
		else return c;
	} else{
		if(b > c) return b;
		else return c;
	}
}

int main(){
	int m, n; // m hang, n cot
	cin >> m >> n;
	int A[105][105];
	int f[105][105]; // luu gia tri lon nhat di den o i,j
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> A[i][j];
		}
	}
	// cho cac o o ngoai ma tran bang am vo cung
	for(int i = 0; i <= n; i++){
		f[0][i] = -1e3;
	}
	for(int i = 0; i <= n; i++){
		f[m+1][i] = -1e3;
	}
	
	for(int j = 1; j <= n; j++){
		for(int i = 1; i <= m; i++){
			f[i][j] = A[i][j] + maximum(f[i-1][j-1], f[i][j-1], f[i+1][j-1]);
		}
	}
	
	int ans = -1e5;
	for(int i = 1; i <= m; i++){
		if(ans < f[i][n]) ans = f[i][n];
	}
	cout << ans;
}
