/*
The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1, 2,..., n. 
The warehouse i has amount of ai (aiai is non-negative integer) and is located at coordinate i (i=1,...,n). 
The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses having largest total amount of golds
 with respect to the condition that the distance between two selected warehouses must be greater than or equal to L1 and less than or equal to L2.

Input
Line 1 contains n, L1, and L2 (1<=n<=1000000,1<=L1<=L2<=n)
Line 2 contains n integers a1, a2,..., an

Output
Contains only one single integer denoting the total amount of golds of selected warehouses.

Example
Input
6 2 3
3 5 9 6 7 4

Output
19 */
#include <bits/stdc++.h> // Dequeu

using namespace std;
#define maxn 1000005

int n, L1, L2; // N la so cua warehouse lien tiep, L1 L2 la nguong gioi han tren va duoi cua 2 warehouse gan nhau => 2 warehouse gan nhat phai cach nhau tu 2-3 vi tri
int a[maxn];
int f[maxn]; // mang luu ket qua cua bai toan
deque<int> q;

int max(int a, int b){
	if(a > b) return a;
	return b;
}


int main(){
	int ans = 0;
	cin >> n >> L1 >> L2;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		f[i] = a[i];
	}
	f[0] = 0;
	q.push_back(1);
	for(int i = L1+1; i <= n; i++){
		f[i] = max(f[q.front()]+a[i], f[i]);
		ans = max(f[i], ans);
		while(!q.empty() && f[q.back()] <= f[i-L1+1])
			q.pop_back();
		while(!q.empty() && q.front() <= i-L2)
			q.pop_front();
		q.push_back(i-L1+1);
	}
	cout << ans;
	return 0;
}
