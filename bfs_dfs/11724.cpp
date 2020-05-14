#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> a[1001];
bool chk[1001];

void dfs(int x){

    chk[x] = true;

    for(int i = 0; i < a[x].size(); i++){
        int y = a[x][i];
        if(!chk[y]) dfs(y);
    }

    
}

int main(){
    cin >> n >> m;//정점의 개수, 간선의 개수

    for(int i=0; i<m; i++){

        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int count = 0;
    for(int i=1; i<=n; i++){
        if(!chk[i]){
            dfs(i);
            count++;
        }
    }


    cout << count;
    return 0;
}