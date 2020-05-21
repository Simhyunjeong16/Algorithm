#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v(200);
bool chk[200];

void dfs(int x){
    if(chk[x]) return;
    chk[x] = true;
    
    for(int i=0; i<v[x].size(); i++){
        dfs(v[x][i]);
    }
    
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<computers.size(); i++){
        for(int j=0; j<computers[i].size(); j++){
            
            if(i == j) continue;//자기자신
            
            if(computers[i][j] == 1) 
                v[i].push_back(j);
        }
    }
    
    for(int i=0; i<n; i++){
        if(!chk[i]){
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}