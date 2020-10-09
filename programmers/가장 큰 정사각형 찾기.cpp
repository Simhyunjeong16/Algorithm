#include <vector>

using namespace std;

int solution(vector<vector<int>> board){//DP
    int answer = board[0][0];

    for(int i = 1; i < board.size(); i++){//1,1부터 시작
        for(int j = 1; j < board[0].size(); j++){
            if(board[i][j] == 1) {//0인 경우에는 정사각형이 만들어지지 않으므로 1인 경우만 계산
                //위쪽, 왼쪽, 왼쪽 대각선에 있는 점 비교하는 점화식
                board[i][j] = min(board[i-1][j], board[i][j-1]);
                board[i][j] = min(board[i-1][j-1], board[i][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;//오른쪽 아래에는 변의 길이만 저장되어 있어서 제곱!
}
