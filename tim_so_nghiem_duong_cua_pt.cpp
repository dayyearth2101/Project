#include <bits/stdc++.h>

using namespace std;
#define maxn 10005

int x[maxn];
int m, n, cnt; // m la tong cua pt, n la so nghiem cua pt, cnt la dem cac tap nghiem thao man
int t; // luu tong den so hang thu x[k] 

int check(int v, int k){
	if(k < n) return 1;
	return t+v == m; // kiem tra so hang co phai la so hang phu hop + m m hay ko	
}

void Try(int k){
	for(int v = 1; v <= m-t-(n-k); v++){
		if(check(v, k)){
			x[k] = v;
			t = t + x[k]; // update tong hien tai
			if(k == n){
				for(int i = 1; i <= n; i++)
					cout << x[i] << " ";
					cnt++;
				cout << endl;
			} else Try(k+1);
			t = t - x[k]; // khoi phuc lai sau khi quay lui
		}
	}	
}

int main(){
	cin >> n >> m;
	t = 0;
	Try(1);
	cout << cnt;
	return 0;
}
