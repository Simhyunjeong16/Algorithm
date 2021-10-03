#include <iostream>

using namespace std;

int main(){
    int n, m;
    int answer = 1;
    int a[51][51];

    scanf("%d %d", &n, &m);
    
    int tmp = min(n, m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d",&a[i][j]);
        }
    }

    int n1, n2, n3, n4;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            
            n1 = a[i][j];//왼쪽 위
            for(int k = 1; k < tmp; k++){
                if(i+k < n && j+k < m){
                    n2 = a[i][j+k];//오른쪽 위
                    n3 = a[i+k][j];//왼쪽 아래
                    n4 = a[i+k][j+k];//오른쪽 아래

                    if(n1 == n2 && n2 == n3 && n3 == n4){
                        answer = max(answer, (k+1)*(k+1));
                    }
                }
            }
        }
    }

    printf("%d", answer);
    return 0;
}
