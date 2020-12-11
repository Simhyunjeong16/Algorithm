#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x, y;
int a, b;
vector<int> v[101];
vector<int> chk(101, 0);
queue<int> q;

void bfs(int k){

    q.push(k);
    
    while(!q.empty()){
        k = q.front();
        q.pop();

        if(k == b) break;

        for(int i = 0; i < v[k].size(); i++){
            int t = v[k][i];
            if(!chk[t]){
                chk[t] = chk[k] + 1;
                q.push(t);   
            }
        }
    }

}

int main(){

    cin >> n;
    cin >> a >> b;//촌수를 계산해야 하는 서로 다른 두 사람의 번호
    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> x >> y;//x는 y의 부모 번호
        v[x].push_back(y);
        v[y].push_back(x);
    }

    bfs(a);

    if(chk[b] != 0) cout << chk[b];
    else cout << -1;

    return 0;
}