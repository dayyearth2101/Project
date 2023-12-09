#include<bits/stdc++.h>

using namespace std;
#define maxn 100005

int n; // so luong khach phai don tra
int Q; // so luong khach toi da dc phep o tren xe 
int x[maxn];
int visited[maxn] = {0}; // danh dau da don khach nao
int cnt = 0; // dem so nguoi tren xe
int a; // dem so phuong an don tra khach

int check(int v, int k){
	if(visited[v] == 1) return 0;
	if(v <= n){
		if(cnt >= Q) return 0;
	}else{
		if(!visited[v-n]) return 0;
	}
	return 1;
}

void Try(int k){
	for(int v = 1; v <= 2*n; v++){
		if(check(v,k)){
			x[k] = v;
			visited[v] = 1;
			if(v <= n){
				cnt++;
			} else cnt--;
			if(k == 2*n){
				for(int i = 1;  i <= 2*n; i++) cout << x[i] << " ";
				cout << endl;
				a++;
			} else Try(k+1);
			visited[v] = 0;
			if(v <= n) cnt--;
			else cnt++;
		}
	}
}


int main(){
	cin >> n >> Q;
	Try(1);
	cout << a;
	return 0;
}
