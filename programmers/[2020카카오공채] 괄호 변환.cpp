#include <string>
#include <vector>
#include <stack>

using namespace std;

//올바른 문자열인지 검사하기! stack사용 (면 push, )면 pop
bool correct_str(string u){
    stack<char> s;
    for(char c: u){
        if(c == '(') s.push(c);
        else{
            if(s.empty()) return false;
            s.pop();
        }
    }
    if(s.empty()) return true;
    else          return false;
    
}

string divide(string p){
    //1번
    if(p.size() == 0) return "";
    
    //2번
    int a=0, b=0, index=0;
    for(int i=0; i<p.size(); i++){
        if(p[i] == '(') a++; 
        else            b++;
        index++;
        if(a == b) break;
    }
    
    string u="", v="";
    u = p.substr(0,index);
    v = p.substr(index); 
    
    //3번
    string result="";
    if(correct_str(u) == true){
        result += u;//3-1번
        result += divide(v);
    }
    
    //4번
    else{
        result += '(';//4-1번
        result += divide(v);//4-2번
        result += ')';//4-3번
        
        //4-4번
        u = u.substr(1, u.size()-2);//첫번째와 마지막 문자 제거하기
        for(char r: u){//괄호방향을 뒤집어서 붙이기
            if(r == '(') result += ')';
            else        result += '(';
        }
        
    }
    
    
    return result;
}


string solution(string p) {
    string answer = "";
    
    answer = divide(p);
    
    
    return answer;
}