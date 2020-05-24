#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool chk[10001];
vector<string> v;
vector<vector<string>> vec;

void dfs(string depart, vector<vector<string>> &tickets, int cnt){
    
    if (cnt == tickets.size()) {
        vec.push_back(v);
        return;
    }
    
    for(int i=0; i<tickets.size(); i++){
        if(depart == tickets[i][0] && !chk[i]){
            chk[i] = true;
            v.push_back(tickets[i][1]);
            
            dfs(tickets[i][1], tickets, cnt+1);
            
            chk[i] = false;
            v.pop_back();
        }
    }
}

bool cmp(vector<string> x, vector<string> y){
    return x[1] < y[1];
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    sort(tickets.begin(), tickets.end(), cmp);
    dfs("ICN", tickets, 0);
    
    answer.push_back("ICN");
    for(string s : vec[0]) answer.push_back(s);
    
    
    return answer;
}