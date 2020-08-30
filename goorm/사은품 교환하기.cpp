#include <iostream>
using namespace std;
int main() {
	int t;
	long long n, m, k, a, b;
	cin >> t;
	
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		
		a = n / 5;
		b = (n + m) / 12;
		
		k = a < b ? a : b;//둘중에 작은 수
		
		while(n + m < 12*k){
			if(k == 0) break;
			
			k--;
		}
		
		cout << k << "\n";
	}
	
	
	return 0;
}