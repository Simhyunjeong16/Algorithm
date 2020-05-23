#include <string>
#include <vector>

using namespace std;

bool chk[50];
int answer = 51;//큰 숫자

void dfs(int x, string s, string target, vector<string> &words, int ans){
    
    if(s == target) {
        answer = min(answer, ans);
        return;
    }
    
    
    for(int i=0; i<words.size(); i++){
        int cnt = 0;
        for(int j=0; j<s.size(); j++){
            if(s[j] != words[i][j]) cnt++;
        }
        if(cnt == 1 && !chk[i]){
            chk[i] = true;
            dfs(i, words[i], target, words, ans+1);
            chk[i] = false;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    
    dfs(-1, begin, target, words, 0);
    
    if(answer == 51) answer = 0;
    
    return answer;
}