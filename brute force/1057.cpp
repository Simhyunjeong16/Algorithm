#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    int n;
    double a, b;
    int round = 0;

    cin >> n >> a >> b;//참가자수, 김지민, 임한수

    while(a != b){

        a = ceil(a / 2);//(a + 1) / 2 = 반올림 <-> 반내림은 floor
        b = ceil(b / 2);//(b + 1) / 2

        round++;
    }

    cout << round;
    //토너먼트가 끝날 때까지 둘이 대결하지 않는 경우는 없으므로 -1 출력은 하지않는다.
    
    return 0;
}
