#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

bool chk[30][30];
bool flag;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(1){
        
        //초기화
        flag = false;
        memset(chk, false, sizeof(chk));
    
        //2x2 블럭 찾기(찾으면 chk를 true로 바꿔주기)
        for(int i=0; i<m-1; i++){//-1 => 맨끝에는 오른쪽으로 터트릴게 없어서 제외
            for(int j=0; j<n-1; j++){

                char block = board[i][j];
                
                if(block != '0' && block == board[i][j+1] && 
                   block == board[i+1][j] && block == board[i+1][j+1]){
                    
                    chk[i][j] = true;//현재
                    chk[i][j+1] = true;//아래
                    chk[i+1][j] = true;//오른
                    chk[i+1][j+1] = true;//대각선

                    flag = true;
                }
            }
        }

        
        if(flag == false) break;//더이상 터드릴게 없어서 종료

        
        if(flag == true){
            
            //블럭 터트리기
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    if(chk[i][j] == true){
                        board[i][j] = '0';//터져서 빈공간이 되었다
                        answer++;//없어진 블럭 수 추가
                    }
                }
            }

        
            //블럭 내리기
            for(int i = m-2; i >= 0; i--){
                for(int j=0; j<n; j++){//-2 => 0부터 시작 -1, 맨 아래값을 아래로 내릴곳이 없어서 -1
                    if(chk[i][j] == false){
                        
                        int t = i;//t는 아래로 이동할 블럭위치
                        
                        while(t < m-1){
                            if(chk[t+1][j] == false) break;
                            t++;
                        }
                        
                        if(t != i){//아래로 이동할 공간이 있다면?
                            board[t][j] = board[i][j];//블럭 이동
                            board[i][j] = '0';//블럭 삭제
                            chk[t][j] = false;
                            chk[i][j] = true;
                        }
                        
                    }
                }
            }
            
        }
        
    }//while 닫개
    
    return answer;
}