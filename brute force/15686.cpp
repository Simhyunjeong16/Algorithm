#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int a[50][50];
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<pair<int, int>> res;
bool chk[14] = {false};

int n, m;
int result = INT_MAX;

void chicken_dist(){

    int r = 0, d = INT_MAX;
    
    for(int i=0; i<home.size(); i++){
        for(int j=0; j<res.size(); j++){
            int dist = abs(home[i].first - res[j].first) + abs(home[i].second - res[j].second);
            d = min(d, dist);
        }
        r += d;
        d = INT_MAX;//d를 또다시 최대값으로 초기화
    }

    result = min(result, r);
    res.clear();//벡터의 모든 요소 지우기
}


void dfs(int x, int y, int MAX){//dfs로 조합만들기

    if(y == m){

        //true값 res에 넣기
        for(int i = 0; i < MAX; i++){
            if(chk[i] == true){
                res.push_back(chicken[i]);
            }
        }

        chicken_dist();
        return;
    }
    
    for(int i = x; i < MAX; i++){
        if(chk[i] == true) continue;
        chk[i] = true;

        dfs(i, y + 1, MAX);
        chk[i] = false;
    }

}

int main() { 
    cin >> n >> m;//m:최대 치킨집의 개수

    //도시 입력받기
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];

            if(a[i][j] == 1) home.push_back(make_pair(i, j));
            else if(a[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }

    dfs(0, 0, chicken.size());

    cout << result;

    return 0;
}