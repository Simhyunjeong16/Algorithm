#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];//가중치에 따른 오름차순 정렬
}

int getParent(vector<int>& parent, int x){//부모노드 찾기
    if(parent[x] == x) return x;//부모노드가 자신이라면 return 
    
    return parent[x] = getParent(parent, parent[x]);//부모노드가 자신이 X, 최상위 부모노드 찾기
}

void unionParent(vector<int>& parent, int a, int b){//부모노드 병합하기
    //부모노드 가져오기
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool findParent(vector<int>& parent, int a, int b){//부모노드가 같은지 비교
    //부모노드 가져오기
    a = getParent(parent, a);
    b = getParent(parent, b);
    
    return a == b;
}


int solution(int n, vector<vector<int>> costs) {//크루스칼 알고리즘(UnionFind)
    int answer = 0;
    int max_node = 0;
    
    sort(costs.begin(), costs.end(), cmp);//가중치 기준으로 정렬
    
    //costs 순회해서 제일 높은 노드 찾기
    for(auto arr : costs){
        if(max_node < arr[1]) max_node = arr[1];
    }
    
    vector<int> parent;//부모용 vector
    for(int i = 0; i <= max_node; i++){
        parent.push_back(i);
    }
    
    for(auto arr : costs){
        if(!findParent(parent, arr[0], arr[1])){//사이클이 발생하지 않는 경우
            answer += arr[2];//결과에 가중치 추가
            unionParent(parent, arr[0], arr[1]);//부모노드 병합
        }
    }
    
    
    return answer;
}