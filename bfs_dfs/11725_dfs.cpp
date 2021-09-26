#include <iostream>
#include <vector>

using namespace std;

int n, node1, node2;
vector<int> v[100001];
bool chk[100001] = {false};
int parent[100001];

void dfs(int x){
    chk[x] = true;

    for(int i = 0; i < v[x].size(); i++){
        int k = v[x][i];

        if(!chk[k]){
            parent[k] = x;
            dfs(k);
        }
    }
}

int main(){
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
        cin >> node1 >> node2;
        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }

    dfs(1);//루트노드 1

    for(int i = 2; i <= n; i++){
        cout << parent[i] << "\n";
    }
    
    return 0;
}