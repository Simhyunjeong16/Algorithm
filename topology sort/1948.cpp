#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;

int n, m;//도시 개수, 도로 개수
int s, f, t;//출발도시 번호, 도착도시 번호, 도로를 지나는데 걸리는 시간
int start, finish;//출발도시, 도착도시

int d[MAX], res[MAX];
vector<pair<int, int>> a[MAX];
vector<pair<int, int>> b[MAX];
bool chk[MAX] = {false};

void topologySort(){
    queue<int> q;

    q.push(start);//시작점 노드를 큐에 삽입
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i = 0; i < a[x].size(); i++){
            
            int node = a[x][i].first;
            int time = a[x][i].second;
            
            if(res[node] < res[x] + time){
                res[node] = res[x] + time;
            }

            if(--d[node] == 0) q.push(node);
        }
    }

    //결과 역추적
    int cnt = 0;
    q.push(finish);//도착점 노드를 큐에 삽입
    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i = 0; i < b[x].size(); i++){
            
            int node = b[x][i].first;
            int time = b[x][i].second;
            
            if(res[x] - res[node] == time){
                cnt++;
                // cout << node << ", cnt = " << cnt << endl;
                
                if(!chk[node]){
                    q.push(node);
                    chk[node] = true;
                }
            }
        }
    }

    cout << res[finish] << "\n" << cnt;
}


int main(){

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> s >> f >> t;

        a[s].push_back(make_pair(f, t));//계산용
        b[f].push_back(make_pair(s, t));//역추적용
        d[f]++;
    }

    cin >> start >> finish;

    topologySort();

    return 0;
}