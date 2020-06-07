#include <string>
#include <algorithm>
#include <set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    set<int> dp[8];//최솟값이 8
    
    int a = 0;
    for(int i = 0; i < 8; i++){
        a = (10 * a) + 1;
        dp[i].insert(a * N); // N, NN, NNN, ... 삽입
    }
    
    for(int i = 1; i < 8; i++){
        for(int j = 0; j < i; j++){
            for(int op1 : dp[j]){
                for(int op2 : dp[i - j - 1]){
                    dp[i].insert(op1 + op2); // + 연산
                    dp[i].insert(op1 - op2); // - 연산
                    dp[i].insert(op1 * op2); // * 연산
                    if(op2 != 0) dp[i].insert(op1 / op2);// / 연산
                }
            }
        }
        
        if(dp[i].count(number) > 0) {//number값 개수세기
            answer = i + 1;
            break;
        }
    }
    
    
    return answer;
}