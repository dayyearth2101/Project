#include<bits/stdc++.h>

using namespace std;
#define maxn 10005

int a[maxn];
int n;

bool check(int v, int k){
	return true;
}

void Try(int k){
	for(int v = 0; v <= 1; v++){
		if(check(v, k)){
			a[k] = v;
			if(k == n){
				for(int i = 1; i <= n; i++) cout << a[i];
				cout << endl;
			}
			else Try(k+1);
		}
		 	
	}
}

int main(){
	cin >> n;
	Try(1);
	return 0;
}
