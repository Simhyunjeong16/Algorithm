#include <iostream>
#include <vector>

using namespace std;

int n, l;
int road = 0;

void cal(vector<vector<int>> a){

    for(int i=0; i<n; i++){

        int cnt = 1;//경사로의 길이를 비교
        int j;
        for(j=0; j<n-1; j++){

            int x = a[i][j+1] - a[i][j];

            if(x == 0) cnt++; //길의 높이가 같은 경우

            else if(x == 1 && cnt >= l) cnt = 1; //올라가는 경사로가 필요
                
            else if(x == -1 && cnt >= 0) cnt = -l + 1; //내려가는 경사로가 필요
                
            else break;
        }

        if(j == n-1 && cnt >= 0) road++;
    }

}


int main(){

    cin >> n >> l;
    
    vector<vector<int>> h(n,vector<int>(n,0)); //(i,j)
    vector<vector<int>> v(n,vector<int>(n,0)); //(j,i)

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> h[i][j];
            v[j][i] = h[i][j];
        }
    }

    cal(h);
    cal(v);

    cout << road;
    return 0;
}