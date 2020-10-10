#include <vector>

using namespace std;

int solution(int n, vector<int> money) {//DP, 백준 동전1과 동일
    int d[100001];
    d[0] = 1;
    
    for(int i = 0; i < money.size(); i++){
        for(int j = money[i]; j <= n; j++){
            d[j] += d[j - money[i]] % 1000000007;//점화식
        }
    }
    
    return d[n];
}
