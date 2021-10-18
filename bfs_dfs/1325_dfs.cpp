#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
vector<int> v[10001];
bool chk[10001] = { false };
int cnt = 0;

void dfs(int x){

    chk[x] = true;

    for(int i = 0; i < v[x].size(); i++){
        int res = v[x][i];

        if(chk[res]) continue;

        cnt++;
        dfs(res);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);//B를 해킹하면, A도 해킹할 수 있다
    }

    vector<int> ans;
    int big = 0;//한 번에 가장 많은 컴퓨터를 해킹할 수 있는 것

    for(int i = 1; i <= n; i++){
        
        //초기화
        cnt = 0;
        memset(chk, false, sizeof(chk));
            
        dfs(i);

        if(big == cnt){//가장 많은 컴퓨터 해킹 할 수 있는 번호가 여러개 입니다!
            ans.push_back(i);
        }
        else if(big < cnt){
            big = cnt;
            ans.clear();
            ans.push_back(i);
        }
    }
    
    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}
