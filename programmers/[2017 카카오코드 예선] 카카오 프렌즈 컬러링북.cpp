//BFS

#include <vector>
#include <queue>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int cnt;
    int color;

    bool chk[101][101];
    for(int i = 0 ; i <m;i++)
        for(int j = 0 ; j < n; j++)
            chk[i][j] = false;


    int dx[4] = {0, 1, -1, 0};
    int dy[4] = {1, 0, 0, -1};
    
    queue<pair<int, int>> q;
    pair<int, int> f;
    
    for(int x=0; x<m; x++){
        for(int y=0; y<n; y++){
            if (picture[x][y] <= 0) continue;
            
            if(picture[x][y] != 0 && chk[x][y] == false){
                number_of_area++;//몇개의 영역으로 나눠져 있는지 세기
                q.push(make_pair(x,y));
                chk[x][y] = true;
                cnt=1;
                color = picture[x][y];
            }
            

            while(!q.empty()){
                
                f = q.front();
                q.pop();
                

                for(int k=0; k<4; k++){
                    int nx = f.first + dx[k];
                    int ny = f.second + dy[k];

                    if(nx>=0 && nx<m && ny>=0 && ny<n){
                        if(chk[nx][ny] == false && picture[nx][ny] == color){
                            q.push(make_pair(nx, ny));
                            chk[nx][ny] = true;
                            cnt++;
                            
                        }
                        
                    }
                }
            }
            
            max_size_of_one_area = max(cnt, max_size_of_one_area);//가장 큰 영역은 몇칸인지 세기
            
            
        }
    }
    
   
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}