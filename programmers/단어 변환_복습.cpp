#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 51;//최대값
bool chk[51];

void dfs(string begin, string target, vector<string>& words, int cnt){
    if(begin == target){
        answer = min(cnt, answer);
        return;
    }
    
    for(int i = 0; i < words.size(); i++){
        if(chk[i]) continue;
        
        int c = 0;
        for(int j = 0; j < begin.size(); j++){
            if(begin[j] != words[i][j]) c++;
        }
        
        if(c == 1) {
            chk[i] = true;
            dfs(words[i], target, words, cnt+1);//조건1
            chk[i] = false;
        }
    }
}


int solution(string begin, string target, vector<string> words) {
    
    if(find(words.begin(), words.end(), target) == words.end()) 
        return 0;//target값이 words배열 안에 없을 때
       
    dfs(begin, target, words, 0);
    
    return answer;
}
