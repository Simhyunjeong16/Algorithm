#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<string> com;
int column_cnt = 0;

bool cmp(string& a, string& b){//길이 순으로 오름차순 -> 숫자 오름차순
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    return a < b;
}

void Combination(int k = 0, string t= ""){//모든 조합을 만드는 함수
    for(int i = k; i < column_cnt; i++){
        t += to_string(i);
        com.push_back(t);
        Combination(i+1, t);
        t = t.substr(0, t.length()-1);//뒤에 하나 없애기
    }
}

//조합에 따른 후보키 판단 함수
bool subset(vector<vector<string>>& relation, string c){
    map<string, int> chk;
    
    for(int i = 0; i < relation.size(); i++) {
        
        //후보키 조합에 따른 string 합치기
        string tmp = "";
        for(int j = 0; j < c.length(); j++){
            int n = c[j] - '0';
            tmp += relation[i][n] + " ";
        }

        if(chk[tmp]) return false;//이미 있다면 후보키 불가

        chk[tmp]++;
    }
    return true;//끝까지 중복이 없다면, 최소성과 유일성 만족 true
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    column_cnt = relation[0].size();
    
    Combination();//가능한 조합수 가져오기

    sort(com.begin(), com.end(), cmp);//가능한 조합수 정렬(낮은 조합부터) -> 오름차순
    // for(int i = 0; i < com.size(); i++) cout << com[i] << " ";
    
    //조합수만큼 반복
    for(int i = 0; i < com.size(); i++){
        if(subset(relation, com[i])){//후보키라면
            string str = com[i];
            
            for(int j = com.size()-1; j >= i; j--){//후보키와 겹치는 조합 없애기
                bool flag = true;
                for(auto s : str){
                    if(com[j].find(s) == string::npos){//찾는 문자열이 없는 경우, string::npos를 반환한다.
                        flag = false;
                        break;
                    }
                }
                
                if(flag) com.erase(com.begin() + j);
            }
            i--;
            answer++;
        }
    }
    return answer;
}