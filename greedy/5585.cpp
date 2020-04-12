#include <iostream>

using namespace std;

//거스름돈 개수를 적게 준다. 1000 => 500 100 50 10 5 1
int main(){
    int coin;
    cin >> coin;

    int c = 1000-coin;
    int r = 0;

    //이게 더 간편.
    r += c/500;
    c %= 500;
    
    r += c/100;
    c %= 100;
    
    r += c/50;
    c %= 50;
    
    r += c/10;
    c %= 10;
    
    r += c/5;
    c %= 5;

    r += c;

    // while(c != 0){

    //     if(c >= 500){
    //             r += c/500;
    //             c %= 500;
    //     }
            
    //     else if(c >= 100){
    //             r += c/100;
    //             c %= 100;
    //     }

    //     else if(c >= 50){
    //             r += c/50;
    //             c %= 50;
    //     }

    //     else if(c >= 10){
    //             r += c/10;
    //             c %= 10;
    //     }

    //     else if(c >= 5){
    //             r += c/5;
    //             c %= 5;
    //     }
        
    //     else if(c >= 1){
    //             r += c;
    //             c %= 1;
    //     }
    // }
    
    cout << r << endl;

    return 0;
}