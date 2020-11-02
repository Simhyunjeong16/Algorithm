#include <string>
#include <vector>

using namespace std;

bool chk[201] = {false, };
vector<int> v[201];

void dfs(int k){
    
    chk[k] = true;
    
    for(int i = 0; i < v[k].size(); i++){
        if(!chk[v[k][i]]) dfs(v[k][i]);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;//네트워크의 개수
    
    
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < computers.size(); j++){
            if(i == j) continue;
            
            if(computers[i][j] == 1) v[i].push_back(j);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(!chk[i]) {
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}
