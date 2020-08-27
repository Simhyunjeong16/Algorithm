#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool chk[10001] = {false, };
vector<pair<int, int>> v[10001];
int far;
int length = 0;//지름 길이

void dfs(int x, int len){
    if(chk[x]) return;

    chk[x] = true;
    if(length < len){
        length = len;
        far = x;
    }

    for(int i = 0; i <v[x].size(); i++){
        dfs(v[x][i].first, v[x][i].second + len);
    }
}

int main(){
    int n;
    int p, c, w;
    
    cin >> n;

    for(int i = 1; i < n; i++){
        cin >> p >> c >> w;//부모노드, 자식노드, 가중치
        
        v[p].push_back(make_pair(c, w));
        v[c].push_back(make_pair(p, w));
    }
    
    //어떤 정점에서 출발해도 가장 멀리 있는 지점은 원의 지름에 해당하는 두 정점중에 하나이다.
    //1에서 가장 멀리있는 지점 찾기
    dfs(1, 0);

    //초기화
    length = 0;
    memset(chk, false, sizeof(chk));
    
    //위에서 찾은 지점에서 가장 멀리 있는 지점찾고 거리 구하기
    dfs(far, 0);
    
    cout << length;
    return 0;
}