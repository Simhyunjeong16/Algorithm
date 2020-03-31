#include <iostream>
#include <algorithm>

using namespace std;

int d[11];

int main(){
    int n;
    cin >> n;//사람의 수
    
    int p;
    for(int i=1; i<=n; i++){//사람들의 키 : 1~n까지 1 2 3 4 키순서대로 입력.
        cin >> p; //자기보다 키 큰 사람이 왼쪽에 몇명이 있었는지 주어짐.

        int count = 0;
        for(int j=1; j<=n; j++){
            
            if(count == p & d[j] == 0){
                d[j] = i;
                break;
            }
            
            else if(d[j] == 0)
                count++; 
        }
    }

    for(int i=1; i<=n; i++)
        cout << d[i] << " ";

    return 0;
}