#include <string>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

vector<char> n;    
bool chk[10];
set<string> s;
    
bool is_Prime(string str){
    if(str[0] == '0') return false;
    if(str == "1") return false;
    
    int x = stoi(str);
    for(int i = 2; i <= sqrt(x); i++){//제곱근까지만 돌려봐도 됨!
        if(x % i == 0) return false;
    }
    
    return true;
}

void dfs(int cnt, int len, string str){
    
    if(cnt == len){//끝까지 돌았다면    
        if(is_Prime(str)) s.insert(str);
        return;
    }
    
    for(int i = 0; i < n.size(); i++){
        if(chk[i]) continue;
        
        chk[i] = true;
        dfs(cnt + 1, len, str + n[i]);
        chk[i] = false;
    }
    
}

int solution(string numbers) {
    
    for(int i = 0; i < numbers.size(); i++){
        n.push_back(numbers[i]);   
    }
    
    for(int i = 1; i <= numbers.size(); i++){
        dfs(0, i, "");//시작, 최대길이, string
    }
    
    return s.size();
}
