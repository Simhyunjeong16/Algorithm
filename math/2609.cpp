#include <iostream>

using namespace std;

int calculate_gcd(int x, int y){
    if(x % y == 0)
        return y;
    
    return calculate_gcd(y, x%y);
}


int main(){

    int x, y;
    int gcd = 1, lcm = 1;
    cin >> x >> y;

    if(x < y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
    
    //내가 푼 방식
    // for(int i = y; i >= 1; i--){
    //     if(x%i == 0 && y%i == 0){
    //         gcd *= i;
    //         x = x/i;
    //         y = y/i;
    //     }
    // }
    // lcm = gcd * x * y;

    //새로운 방식(유클리드 호제법)
    gcd = calculate_gcd(x, y);
    lcm = x * y / gcd;
    

    cout << gcd << "\n" << lcm;

    return 0;
}