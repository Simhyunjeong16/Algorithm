#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    vector<int> v;
    
    // 레이저()를 !로 바꿔주기
    for(int i = 0; i < arrangement.size()-1; i++){
        if(arrangement[i] == '(' && arrangement[i+1] == ')'){
            arrangement[i] = '!';
            arrangement.erase(i+1, 1);
        }
    }
    

    for(char s : arrangement){//	! ( ( ( ! ! ) ( ! ) ! ) ) ( ! ) 
        if(s == '('){
            v.push_back(1);
        }
        else if(s == ')'){
            answer += v.back();
            v.pop_back();
        }
        else{//레이저
            for(int i=0; i<v.size(); i++) v[i]++;
        }
    }
    
    
    return answer;
}