#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> v = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

int Calc(char p1, char p2){
    int p1_pos, p2_pos;
    
    for(int i = 0; i < v.size(); i++){//위치 찾기
        if(v[i] == p1) p1_pos = i;
        if(v[i] == p2) p2_pos = i;
    }
    
   return abs(p1_pos - p2_pos)-1;//옆에 붙어있으면 간격이 0이니까, -1을 해야한다.
}

int solution(int n, vector<string> data) {
    int answer = 0;
    
    do{
        int i;
        for(i = 0; i < n; i++){
            char p1 = data[i][0];
            char p2 = data[i][2];
            char op = data[i][3];
            int num = data[i][4] - '0';

            if(op == '='){
                if(Calc(p1, p2) != num) break;
            }
            else if(op == '>'){
                if(Calc(p1, p2) <= num) break;
            }
            else if(op == '<'){
                if(Calc(p1, p2) >= num) break;
            }
        }
        
        if(i == n) answer++;//끝까지 잘 돌았으면 answer++
        
    }while(next_permutation(v.begin(), v.end()));//순열
    
    
    return answer;
}
