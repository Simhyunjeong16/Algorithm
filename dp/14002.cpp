#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int a[1001];
int d[1001];
int index_arr[1001];
int n;
vector<int> v;

int main(){

    cin >> n;

    for(int i=0; i<n; i++)
        cin >> a[i];
    
    memset(index_arr, -1, sizeof(index_arr));

    for(int i=0; i<n; i++){
        d[i] = 1;

        for(int j=0; j<i; j++){
             if(a[j] < a[i] && d[i] < d[j]+1){
                d[i] = d[j]+1;
                index_arr[i] = j;
            }
        }
    }
    
    int result = 0, idx = 0;
    for(int i=0; i<n; i++){
        if(result < d[i]){
            result = d[i];//최댓값 찾기
            idx = i;//최댓값의 인덱스값
        }
    }
    cout << result << "\n";

    while(idx >= 0){
        v.push_back(a[idx]);
        idx = index_arr[idx];
    }

    for(int i=v.size()-1; i>=0; i--)
        cout << v[i] << " ";

    return 0;
}