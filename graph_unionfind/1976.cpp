#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 1000000 + 1;
int arr[MAX];


int find(int n){//부모 찾는 연산
    
    if (arr[n] < 0) return n;
            
    arr[n] = find(arr[n]);
    return arr[n];
}

void weight_merge(int a, int b){//큰 트리 하위에 작은 트리가 연결되도록 함.
    
    if(abs(a) < abs(b)){ //b가 더 큼.
        arr[b] += arr[a]; 
        arr[a] = b;
        
    }

    else { //a가 더 큼.
        arr[a] += arr[b];
        arr[b] = a;
        
    }
}


 
int main()
{   
    //실행 속도 높이기 위한 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;//도시의수, 여행 계획에 속한 도시들의 수

    memset(arr, -1, sizeof(arr));
    
    
    //인접한 도시들끼리 한 집합으로 합쳐준다.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++){

            int x;
            cin >> x;
            
            if(x == 1){
                int a = find(i);
                int b = find(j);

                if (a == b) continue;//자기 자신이니까 당연히 0이어서 넘어간다.    
                
                weight_merge(a, b);
            }
        }
    }

             
    //여행계획 -> 주어진 도시들이 모두 같은 집합에 있나용?
    int r;
    bool result = true;
    for (int i = 0; i < M; i++){

        int city;
        cin >> city;

        if (i == 0){ //첫번째로 여행계획한 도시
            r = find(city);
        }

        else { //두번째 부터 ~ 나머지 도시들
            if (r != find(city)){//루트가 아니야?
                result = false;
                break;
            }
        }
        
    }

    if (result == true){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}