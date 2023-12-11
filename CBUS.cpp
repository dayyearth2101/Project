/*
There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). 
There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). 
You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). 
Compute the shortest route for the bus, serving n passengers and coming back to point 0. 
Input
	Line 1 contains n and k (1=n=11,1=k=10)
 	Line i+1 (i=1,2,…,2n+1) contains the (i-1)th
 	line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
Output
	Unique line contains the length of the shortest route.

Example:
Input
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
25
*/

#include <bits/stdc++.h>

using namespace std;

int n; // bien luu so passenger
int p; // so noi ma bus den
int x[10005]; // mang luu diem don-tra khach
int xbest[10005];
bool appear[10005]; // mang danh dau cac diem bus da di qua
int load; // ghi nhan so khach hang dang co tren xe
int A[10005][10005]; // mang luu ban do bus di
int f;
int fbest;
int cmin;

int check(int v, int k){
	if(appear[v] == true) return 0; // neu dia diem da den 
	if(v > n){ // neu so dia diem lon hon so khach hang
		if(!appear[v-n]) return 0; // neu so dia diem con lai chua di qua
	} else {
		if(load + 1 > p) // so sanh so khach hang tren xe vs so dia diem can den
			return 0;
	}
	return 1;
}

void Try(int k){
	for(int v = 1; v <= 2*n; v++){
		if(check(v,k)){
			x[k] = v; // gan gia tri v cho x[k]
			f += A[x[k-1]][x[k]]; // cong quang duong giua 2 diem don
			if(v <= n) load++;
			else load--;
			appear[v] = true;
			if(k == 2*n){
				if(f + A[x[2*n]][0] < fbest){
					fbest = f + A[x[2*n]][0];
					for(int i = 1; i <= 2*n; i++) xbest[i] = x[i];
				}
			} else{
				if(f + (2*n+1 - k)*cmin < fbest)   
					Try(k+1);
			}
			f -= A[x[k-1]][x[k]];
			appear[v] = false;
			if(v <= n) load--;
			else load++;
		}
	}
}

int main(){
	cin >> n >> p;
	cmin = 1e6;
	load = 0;
	fbest = 1e6;
	f = 0;
	for(int i = 0; i <= 2*n; i++){
		for(int j = 0; j <= 2*n; j++){
			cin >> A[i][j];
			if(i!=j && cmin > A[i][j]) cmin = A[i][j];
		}
	}
	for(int i = 1; i <= 2*n; i++) appear[i] = false;
	x[0] = 0;
	Try(1);
	cout << fbest;
	return 0;
}
