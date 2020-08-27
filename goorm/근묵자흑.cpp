#include <iostream>

using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	
	int m;
	for(int i = 0; i < n; i++){
		cin >> m;
	}
	
	int c = 0;
	int cnt = 0;
	while(1){
		cnt++;
		c = c + k - 1;
		if(c >= n-1) break;
	}
	
	cout << cnt;
	return 0;
}