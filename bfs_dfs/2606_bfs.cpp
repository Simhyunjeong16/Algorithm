#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, x, y;
vector<int> v[101];
int chk[101];
int answer = -1;

void bfs(int a){

    queue<int> q;
    q.push(a);
    chk[a] = true;

    while(!q.empty()){

        int f = q.front();
        q.pop();
        answer++;

        for(int i=0; i<v[f].size(); i++){
            int r = v[f][i];
            if(!chk[r]){
                q.push(r);
                chk[r] = true;
            }
        }

    }

}


int main(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    bfs(1);//1번 컴퓨터가 맨 처음에 웜 바이러스에 걸림

    cout << answer;
    return 0;
}