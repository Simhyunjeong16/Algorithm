#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int a[100001];
queue<int> q;
int dist[100001];

//BFS
int main(){

    int n, k;
    cin >> n >> k;

    memset(dist, 0, sizeof(dist));

    q.push(n);

    while(!q.empty()){

        int f = q.front();
        q.pop();

        if(f == k) break;

        int nx;
        for(int i=0; i<3; i++){
            
            if(i == 0) nx = f-1;
            if(i == 1) nx = f+1;
            if(i == 2) nx = f*2;

            if(nx >=0 && nx <=100000 && dist[nx] == 0){//한번도 들린적없는 곳이어야함
                dist[nx] = dist[f] + 1;//1초가 흘렀습니다.
                q.push(nx);
            }
        }

        
    }

    cout << dist[k];

    return 0;
}