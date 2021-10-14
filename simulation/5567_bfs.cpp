#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> v[n+1];

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
    
        v[a].push_back(b);
        v[b].push_back(a);
    }

    //bfs
    queue<int> q;
    bool chk[n+1] = {false};
    int ans = 0;

    //상근이 친구들
    q.push(1);
    chk[1] = true;
    for(int i = 0; i < v[1].size(); i++){
        int t = v[1][i];
        q.push(t);
        chk[t] = true;
        ans++;
    }

    //친구의 친구
    while(!q.empty()){
        int k = q.front();
        q.pop();

        for(int i = 0; i < v[k].size(); i++){
            int t = v[k][i];
            if(chk[t]) continue;
            chk[t] = true;
            ans++;
        }
    }

    cout << ans;
    return 0;
}
