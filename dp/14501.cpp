#include <iostream>
#include <vector>

using namespace std;

int n, time, price;
vector<pair<int, int>> v;
int result = 0;


void dp(int t, int p){

    if(t >= n){
        result = max(result, p);
        return;
    }
        
    if(t + v[t].first <= n){//상담을 마무리하고 난 다음 날(해당일)
        dp(t + v[t].first, p + v[t].second);
    }
    if(t + 1 <= n){//해당일에 상담X, 다음날에 O
        dp(t + 1, p);
    }

}


int main(){
    cin >> n;//n일까지 일한다

    for(int i=0; i<n; i++){
        cin >> time >> price;
        v.push_back(make_pair(time, price));
    }

    dp(0, 0);

    cout << result;
    return 0;
}