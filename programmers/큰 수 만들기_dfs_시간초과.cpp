#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<char> v;
bool chk[1000001];
string answer = "";

void dfs(int cnt, int start, int finish, string n){
    
    if(cnt == finish){
        string str = "";
        // for(int i = 0; i < finish; i++){
        //     str += v[i];
        // }
        for(int i = 0; i < n.size(); i++){
            if(chk[i]) str += n[i];
        }
        
        cout << str << endl;
        
        if(answer < str) answer = str;
    }
    
    for(int i = start; i < n.size(); i++){
        if(chk[i]) continue;
        
        chk[i] = true;
        // v.push_back(n[i]);
        
        dfs(cnt+1, i+1, finish, n);
        
        chk[i] = false;
        // v.pop_back();
    }
    
}


string solution(string number, int k) {
    
    dfs(0, 0, number.size()-k, number);
    
    return answer;
}