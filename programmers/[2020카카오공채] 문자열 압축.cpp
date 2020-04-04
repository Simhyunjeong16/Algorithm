//brute force문제
//다시 공부 필요

#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer= s.size();
    
    int len = s.size();
    for(int i=1; i<=(len/2); i++){
        int count = 1;
        string tmp = s.substr(0, i);//0부터시작해서 i의 길이만큼 반환
        string result = "";
        
        for(int j=i; j<=len; j +=i){
            if(tmp == s.substr(j, i)) count++;//뒷부분과 일치한다면 count 증가
            
            else{
                if(count == 1)  result += tmp;
                else            result += to_string(count) + tmp;
                
                tmp = s.substr(j,i);
                count = 1;
            }
        }
        
        if(len/i != 0) result += s.substr( (len/i) * i);//0부터 시작해서 (len/i)*i까지 문자열 반환.
        
        if(answer > result.size()) answer = result.size();
        
    }
    return answer;
}