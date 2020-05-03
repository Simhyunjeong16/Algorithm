#include <iostream>
#include <vector>

using namespace std;

int main(){
    int num;
    cin >> num;
    
    vector<int> dp(num+1);

    for(int i=1; i<=num; i++){
        dp[i] = i;//다 1일때 개수
    
        if(i < 4) continue;//1,2,3은 pass

        for(int j=1; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-(j*j)]+1);
        }
    }
    
    cout << dp[num] << endl;
    return 0;
}