#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string real_path = "";
bool chk[10001];

bool cmp(vector<string> x, vector<string> y){
    return x[1] < y[1];//오름차순
}

void dfs(string start, vector<vector<string>> tickets, int cnt, string path){
    
    if(cnt == tickets.size()){
        if(real_path.empty() || path < real_path) real_path = path;
        return;
    }
    
    for(int i = 0; i < tickets.size(); i++){
        if(chk[i]) continue;
        
        if(tickets[i][0] == start) {
            chk[i] = true;
            dfs(tickets[i][1], tickets, cnt+1, path + tickets[i][1]);
            chk[i] = false;
        }
    }
    
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end(), cmp);//알파벳순
    
    dfs("ICN", tickets, 0, "ICN");
    
    for(int i = 0; i < real_path.length(); i+=3){
        answer.push_back(real_path.substr(i, 3));
    }
    
    return answer;
}
