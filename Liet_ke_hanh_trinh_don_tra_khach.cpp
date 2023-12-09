#include<bits/stdc++.h>

using namespace std;
#define maxn 100005

int n; // so khach phai don va tra
int x[maxn];
int cnt = 0;
int visited[maxn] = {0}; // luu khach da don
int back[maxn] = {0}; //  luu khach da tra

void Try(int k){
	for(int v = 1; v <= n; v++){
		if(visited[v] == 0){
			x[k] = v;
			visited[v] = 1;
			back[v] = 1;
			if(k == n){
				for(int i = 1; i <= n; i++) cout << x[i] << "-" << x[i]+n << "/";
				cout << endl;
				cnt++;
			}else Try(k+1);
			visited[v] = 0;
			back[v] = 0;
		}
	}
}


int main(){
	cin >> n;
	Try(1);
	cout << cnt;
	return 0;
}
