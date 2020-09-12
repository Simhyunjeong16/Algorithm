#include <string>
#include <vector>

using namespace std;

int n, m, board_size;

void rotateKey(vector<vector<int>>& key){
    
    vector<vector<int>> tmp(m, vector<int>(m));
        
     for(int j = m - 1; j >= 0; j--) {
        for(int i = 0; i < m; i++) {
            tmp[i][j] = key[m -j-1][i];
        }
    }
    
    key = tmp;
}

bool putKey(int x, int y, vector<vector<int>> k, vector<vector<int>> b){
    
    //key 더하기
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            b[i+x][j+y] += k[i][j];
        }
    }
    
    //lock확인 1이 아니라면 홈 부분에 제대로 안맞은 것
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(b[i+m-1][j+m-1] != 1) return false;
        }
    }
    return true;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    n = lock.size();
    m = key.size();
    board_size = n + (m-1)*2;//최소 한칸이 겹칠 수 있다, 위아래해서 *2임
    
    vector<vector<int>> board(board_size, vector<int>(board_size, 0));
    
    //board에 lock 더하기
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            board[i+m-1][j+m-1] = lock[i][j];
        }
    }
    
    //회전 방향 4번
    for(int k = 0; k < 4; k++){
        
        for(int i = 0; i <= board_size-m; i++){
            for(int j = 0; j <= board_size-m; j++){
                if(putKey(i, j, key, board)) {
                    answer = true;    
                    return answer;
                }
            }
        }
        
        rotateKey(key);//시계방향으로 90도 회전
    }
    
    
    return answer;
}
