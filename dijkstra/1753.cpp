#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> dist[20001];//간선 정보
int d[20001];//최소 비용
const int INF = 987654321;

void dijkstra(int start){

    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    d[start] = 0;

    while(!pq.empty()){
        int distance = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(d[cur] < distance) continue;//최단거리가 아니면 Continue

        for(int i = 0; i < dist[cur].size(); i++){
            int next = dist[cur][i].first;
            int next_distance = distance + dist[cur][i].second;

            if(next_distance < d[next]){//if 최단거리
                d[next] = next_distance;
                pq.push({-next_distance, next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int v, e, k;
    cin >> v >> e >> k;

    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        dist[a].push_back({b, c});
    }

    for(int i = 1; i <= v; i++){
        d[i] = INF;
    }

    dijkstra(k);

    for(int i = 1; i <= v; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }

    return 0;
}
