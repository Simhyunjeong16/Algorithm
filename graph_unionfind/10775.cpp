#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100000 + 1;

int G, P;
int arr[MAX];

//루트를 찾는 함수
int find(int n){
    
    if(arr[n] < 0)
        return n;//arr의 안에 있는 값을 다 -1로 초기화했기 때문에 자기 자신이 루트면 -1이어서!
    
    arr[n] = find(arr[n]);//재귀함수로 경로의 모든 노드의 부모를 루트로 재설정함.
    
    return arr[n];
}

//집합의 크기를 계산하지 않고 합치기
void merge(int a, int b){
    a = find(a);
    b = find(b);
   
    arr[b] = a;
}


int main(){
    
    //실행 속도 높이기 위한 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> G >> P;// 게이트 수, 비행기 수
    
    memset(arr, -1, sizeof(arr));//arr를 -1로 채움.

    int r = 0;
    bool dock = true;

    for(int i = 0; i < P; i++){

        int t;
        cin >> t;

        if(!dock) continue;

        int open = find(t);

        if (open > 0){
            r++;
            merge(open-1, open);
        }
        else{
            dock = false;
        }
    }

    
    //최대 비행기 수
    cout << r << endl;

    return 0;
}




//큰 트리 하위에 작은 트리가 연결되도록 함.
// void weight_merge(int a, int b){
    
//   if(abs(a) < abs(b)){ //b가 더 큼.
//         arr[b] += arr[a]; 
//         arr[a] = b;
        
//     }

//     else { //a가 더 큼.
//         arr[a] += arr[b];
//         arr[b] = a;
        
//     }
// }