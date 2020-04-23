#include <iostream>
#include <algorithm>

using namespace std;

int a[9];
int all_height = 0;

void brute(){

    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if( (all_height - (a[i]+a[j])) == 100){//두명의 난쟁이의 키를 뺀 값이 100이라면?
                a[i] = -1; a[j] = -1;
                return;
            }
        }
    }
}

int main(){

    for(int i=0; i<9; i++){
        cin >> a[i];
        all_height += a[i];//총 9명 키의 합
    }

    brute();

    sort(a, a+9);

    for(int i=2; i<9; i++) cout << a[i] << "\n";//두명의 난쟁이를 제외해야하니까

    return 0;
}