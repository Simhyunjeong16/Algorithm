#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string a[51];

int WB_cnt(int x, int y){//시작이 white일 경우
    int cnt = 0;
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(a[x+i][y+j] != WB[i][j]) cnt++;
        }
    }

    return cnt;
}

int BW_cnt(int x, int y){//시작이 black일 경우
    int cnt = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(a[x+i][y+j] != BW[i][j]) cnt++;
        }
    }

    return cnt;
}


int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    int answer = 2501;
    for(int i = 0; i + 8 <= n; i++){
        for(int j = 0; j + 8 <= m; j++){
            int m =  min(WB_cnt(i, j), BW_cnt(i, j));

            answer = min(answer, m);
        }
    }

    cout << answer;
    return 0;
}