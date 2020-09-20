#include <string>

using namespace std;

int solution(string s){
    int answer = 1;
   
    for(int i = 0; i < s.length()-1; i++){
        string str(1, s[i]);
        
        if(answer != 1 && answer > s.length()-1-i) break;//어차피 최대길이 구했기에 break
        
        for(int j = i+1; j < s.length(); j++){
            str += s[j];
            
            bool flag = true;
            for(int k = 0; k < str.length()/2; k++){//palindrome 확인 -> 반만 확인해도 됨
                if(str[k] != str[str.length()-k-1]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag && answer < str.length()) answer = str.length();
        }
    }

    return answer;
}
