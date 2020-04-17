#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int n;
int a[20][20];
int chk[20];
int result = INT_MAX;
vector<int> start;
vector<int> link;

void dfs(int x, int cnt){

    if(cnt == n/2){//반으로 팀을 갈랐을때

        int start_team=0, link_team=0;
    
         for(int i=0; i<n; i++){
            if(chk[i] == true) start.push_back(i);  
            else link.push_back(i);
        }

        //스타트 팀 능력치 구하기
        for(int i=0; i<start.size(); i++){
            for(int j=0; j<start.size(); j++){
                if(i == j) continue;//자기자신
                start_team += a[start[i]][start[j]];
            }
        }

        //링크 팀 능력치 구하기
        for(int i=0; i<link.size(); i++){
            for(int j=0; j<link.size(); j++){
                if(i == j) continue;//자기자신
                link_team += a[link[i]][link[j]];
            }
        }

        result = min(result, abs(start_team-link_team));//능력치 차이가 젤 적은거
        
        start.clear(); link.clear();//초기화
        
        return;
    }

    for(int i=x; i<n; i++){
        chk[i] = true;
        dfs(i+1, cnt+1);//i+1해서 시간초과가 나지 않았다
        chk[i] = false;
    }

}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    dfs(0, 0);

    cout << result;

    return 0;
}