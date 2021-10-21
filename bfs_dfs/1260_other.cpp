#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1001

using namespace std;

bool v[MAX][MAX] = { false };
bool c[MAX] = { false };
bool chk[MAX] = { false };

int n, m, num;//정점의 개수, 간선의 개수, 정점의 번호

void dfs(int x){

    c[x] = true;
    cout << x << ' ';

    for(int i=1; i<= n; i++){//정점의 갯수대로 반복문을 돈다.
        
        if(c[i] == true || v[x][i] == false) continue;
        
        dfs(i);   
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

        for(int i=1; i<= n; i++){//1부터 시작하니까 정점 번호가 작은 것 부터 방문함.
            
            if(chk[i] == true || v[f][i] == false) continue;

            q.push(i);
            chk[i] = true;

        }
    }

}


int main(){

    cin >> n >> m >> num;

    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        v[a][b] = true;//이 배열에 간선이 존재한다.
        v[b][a] = true;//이 배열에 간선이 존재한다.
    }


    dfs(num);//깊이우선탐색
    cout << "\n";
    bfs(num);//너비우선탐색

    return 0;
}