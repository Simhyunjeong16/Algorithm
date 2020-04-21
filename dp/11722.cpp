#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int d[1001];

int main(){
    int num;
    cin >> num; //수열의 크기


    for(int i=0; i<num; i++){
        cin >> a[i];
    }


    int result = 0;
    for(int i=0; i<num; i++){
        d[i] = 1;

        for(int j=0; j<i; j++){
            if(a[j] > a[i]){//여기만 바꿔주면 됨
                d[i] = max(d[i], d[j]+1);//점화식
            }
        }
        result = max(result, d[i]);
    }


    cout << result;

    return 0;
}