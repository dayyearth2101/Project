#include <bits/stdc++.h>

/* 
input: 
5
2 5 7 8 4
4 9 10 10

output:
18
*/

using namespace std;
#define MAX 60005

int n; // so nguoi mua ve
int t[MAX]; // thoi gian mua ve cua n nguoi
int r[MAX]; // thoi gian mua ve n-1 nguoi neu nguoi i+1 nho nguoi i mua ho ve 
int f[MAX]; // array luu thoi gian phuc vu nho nhat

int min(int a, int b){
	if(a < b) return a;
	else return b;
}

int tuMua(int f[], int i, int t[]){
	f[i] = f[i-1] + t[i];
	return f[i];
}

int nhoMua(int f[], int i, int r[]){
	f[i] = f[i-2] + r[i-1];
	return f[i];
}

void solve(int n, int t[], int r[]){
	f[1] = t[1];
	for(int i = 2; i <= n; i++){
		f[i] = min(tuMua(f,i,t), nhoMua(f,i,r));
	}
	cout << f[n];
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i < n; i++) cin >> r[i];
	solve(n,t,r);
}
