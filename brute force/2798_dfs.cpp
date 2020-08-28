#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, a;
vector<int> v;
bool chk[101] = {false};
int answer = 0;

void dfs(int x, int sum, int cnt){

    if(cnt == 3){
        if(sum > answer && sum <= m) answer = sum;
        return;
    }


    for(int i = x; i < n; i++){
        if(chk[i]) continue;

        chk[i] = true;
        dfs(i, sum + v[i], cnt+1);
        chk[i] = false;
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), greater<int>());

    dfs(0, 0, 0);
    cout << answer;

    return 0;
}