#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();//정사각형이니까 가능
    stack<int> s;
    
    for(int m=0; m<moves.size(); m++){
        int j = moves[m]-1;//0번 시작해서 -1을 뺀다.

        for(int i=0; i<n; i++){//세로
            if(board[i][j] != 0){
                
                if(s.empty()) s.push(board[i][j]);//처음에는 비어있기 때문에 넣는다.
                
                else if(s.top() == board[i][j]) {//stack의 가장 윗부분과 현재값이 같으면
                    s.pop();//터트리기!
                    answer += 2;
                }
                
                else s.push(board[i][j]);
                
                
                board[i][j] = 0;
                break;
            }
        }
        
    }
    
    
    return answer;
}