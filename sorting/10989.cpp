#include <iostream>
#include <algorithm>

using namespace std;

//counting algorithm

int main(){

    int n, k;
    int arr[10001] = {0, };

    scanf("%d", &n);

    int max_num = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        arr[k]++;
        if(k > max_num) max_num = k;//최댓값구하기
    }

    for(int i = 1; i <= max_num; i++){
        
        if(arr[i] != 0){
            for(int j = 0; j < arr[i]; j++){
                printf("%d\n", i);
            }
        }
        
    }

    return 0;
}