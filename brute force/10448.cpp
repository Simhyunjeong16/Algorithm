#include <iostream>

using namespace std;

int a[45];

bool Eureka(int num){
    for(int k = 1; k <= 44; k++){
        for(int i = 1; i <= 44; i++){
            for(int j = 1; j <= 44; j++){
                if(a[k] + a[i] + a[j] == num) return true;
            }                                                                                                                                                                                                                                                                                                                                                                                                                           
        }
    }

    return false;
}

int main(){
    int n;
    cin >> n;

    //삼각수 공식
    for(int i = 1; i <= 44; i++){//1000에 가까운 값이 44라서 44까지 계산
        a[i] = i * (i + 1) / 2;
    }

    for(int t = 0; t < n; t++){
        int num;
        cin >> num;
        
        cout << Eureka(num) << endl;
    }
    

    return 0;
}