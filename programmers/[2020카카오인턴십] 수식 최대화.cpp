#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

long long calc(long long a, long long b, char operand){
    if(operand == '+') return a + b;
    else if(operand == '-') return a - b;
    else return a * b;
}

long long solution(string expression) {
    long long answer = 0;
    string str = "";
    vector<char> op;//현재 갖고 있는 연산자들의 순열을 만들기 위한 벡터
    vector<char> location;//모든 연산자들의 순서를 갖고 있는 벡터
    vector<long long> n;//모든 수들의 순서를 갖고 있는 벡터

    //숫자와 연산자 각 벡터에 push하기
    for(int i = 0; i < expression.length(); i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*'){
            n.push_back(stoi(str));
            str = "";
            
            if(find(op.begin(), op.end(), expression[i]) == op.end()){//존재하지 않으면
                op.push_back(expression[i]);
            }
            location.push_back(expression[i]);
        }
        else{
            str += expression[i];
        }
    }
    
    n.push_back(stoi(str));//마지막 숫자 안들어가니까
    sort(op.begin(), op.end());//next_permutation(순열)을 위해서
    
    //순열
    do{
        vector<long long> tmp_n = n;
        vector<char> tmp_op = location;
        
        for(int i = 0; i < op.size(); i++){
            
            for(int j = 0; j < tmp_op.size(); j++){
                
                if(op[i] == tmp_op[j]){
                    
                    tmp_n[j] = calc(tmp_n[j], tmp_n[j+1], tmp_op[j]);//계산 값 넣기
                    
                    tmp_n.erase(tmp_n.begin() + (j+1));//뒤에 값 삭제하기
                    tmp_op.erase(tmp_op.begin() + j);//사용한 연산자 삭제하기
                    j--;//하나 삭제했으니까, -1 해줘야함
                }
            }
        }
        if(answer < abs(tmp_n[0])) answer = abs(tmp_n[0]);
        
    }while(next_permutation(op.begin(), op.end()));//모든 순열을 다 구했다면 false를 리턴
    
    
    return answer;
}
