#include <bits/stdc++.h>

using namespace std;
#define maxn 10005

int n; // so khach hang
int x[maxn];
int visited[maxn]; // luu cac khach hang da di qua
int cnt = 0; // dem xem co bao nhieu cach ship hang

int check(int v, int k){
	if(visited[v] == 0) return 1;
	return 0;
}

void Try(int k){
	for(int v = 1; v <= n; v++){
		if(visited[v] == 0){
			x[k] = v;
			visited[v] = 1;
			if(k == n){
				for(int i = 1; i <= n; i++){
					cout << x[i] << " ";
				}
				cnt++;
				cout << endl;
			} else Try(k+1);
			visited[v] = 0;
		}
	}
}

int main(){
	cin >> n;
	visited[maxn] = {0};
	Try(1);
	cout << cnt;
	return 0;
}
