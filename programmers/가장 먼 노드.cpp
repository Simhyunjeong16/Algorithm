#include <algorithm>
#include <vector>

using namespace std;

void bfs(int cur, vector<vector<bool>>& gragh, vector<int>& dist, vector<int> v){
    vector<int> q;//임시 q
    
    while(!v.empty()){//인자값으로 넘어온 v가 빌때까지 반복
        for(int i = 1; i < gragh.size(); i++){//연결되어 있는 그래프 확인
            if(gragh[v[0]][i] == true && dist[i] == 0){//v에 들어있는 노드와 연결되어 있어야 하고, 거리설정이 안되어 있어야 한다.
                q.push_back(i);//임시 큐에 넣는다.
                dist[i] = cur;//거리를 넣어준다.
            }
        }
        v.erase(v.begin());//v에 있는 데이터 pop
    }
    if(!q.empty()) bfs(cur + 1, gragh, dist, q);//임시 q가 비어있지 않다면 bfs 재귀
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<bool>> gragh(n, vector<bool>(n, false));//노드 수 만큼 2차원 벡터를 만들고, 1차원 벡터는 false로 설정한다.
    vector<int> dist(n, 0);//거리는 n개의 1차원 벡터로 0 초기화
    
    for(auto e : edge){//연결되어 있는 엣지들은 true로 변경
        gragh[e[0]-1][e[1]-1] = true;//0부터 시작하니까 -1
        gragh[e[1]-1][e[0]-1] = true;
    }
    
    bfs(1, gragh, dist, { 0 });//첫 노드는 0으로 설정한다.(시작노드가 1이니까)
    
    int max = *max_element(dist.begin(), dist.end());//최대거리를 구해서 최대거리와 같은 수 만큼 answer 증가
    for(auto d : dist){
        if(d == max) answer++;
    }
    
    return answer;
}