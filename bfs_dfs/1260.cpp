#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1001

using namespace std;

vector<int> v[1001];
bool c[MAX] = { false };
bool chk[MAX] = { false };


void dfs(int x){

    if(c[x]) return;

    c[x] = true;
    cout << x << ' ';

    for(int i=0; i< v[x].size(); i++){
        int r = v[x][i];
        dfs(r);   
    }

}

void bfs(int x){

    queue<int> q;
    q.push(x);
    chk[x] = true;

    while(!q.empty()){

        int f = q.front();
        q.pop();

        cout << f << ' ';

        for(int i=0; i< v[f].size(); i++){

            int r = v[f][i];

            if(!chk[r]){
                q.push(r);
                chk[r] = true;
            }

        }
    }

}


int main(){

    int n, m, num;//정점의 개수, 간선의 개수, 정점의 번호
    cin >> n >> m >> num;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=0; i<n; i++)
        sort(v[i].begin(), v[i].end());


    dfs(num);//깊이우선탐색
    cout << "\n";
    bfs(num);//너비우선탐색

    return 0;
}