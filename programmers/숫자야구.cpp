#include <string>
#include <vector>

using namespace std;

vector<int> v;
vector<string> b;
int n[9] = {1,2,3,4,5,6,7,8,9};
bool chk[9] = {false};

void dfs(int cnt){
    
    if(cnt == 3){
        b.push_back(to_string(v[0]*100 + v[1]*10 + v[2]));
        return;
    }
    
    for(int i = 0; i < 9; i++){
        if(chk[i]) continue;
        
        chk[i] = true;
        v.push_back(n[i]);
        
        dfs(cnt+1);
        
        chk[i] = false;
        v.pop_back();
    }
}

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    
    dfs(0);//모든 경우의 수 만들기
    
    for(int k = 0; k < baseball.size(); k++){
        string num = to_string(baseball[k][0]);
        
        for(int i = b.size()-1; i >= 0; i--){
            
            int strike = 0, ball = 0;
            for(int j = 0; j < 3; j++){
                if(num[j] == b[i][j])//숫자, 위치 모두 맞음
                    strike++;
                
                else if(num[j] == b[i][(j+1)%3] || num[j] == b[i][(j+2)%3])//숫자 맞음, 위치 틀림
                    ball++;
            }
            
            if(baseball[k][1] != strike || baseball[k][2] != ball)
                b.erase(b.begin()+i);//삭제
        }
         
    }
    
    answer = b.size();
    return answer;
}