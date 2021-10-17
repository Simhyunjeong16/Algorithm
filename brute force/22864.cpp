#include <iostream>

using namespace std;

int main(){
    int a, b, c, m;//피로도, 일, 피로도감소, 번아웃 조심
    cin >> a >> b >> c >> m;

    int pirodo = 0;
    int time = 0;
    int work = 0;

    while(time < 24){
        time++;

        if(pirodo + a > m){
            if(pirodo - c < 0) pirodo = 0;
            else pirodo = pirodo - c;

            continue;
        }
        
        pirodo += a;
        work += b;
    }

    cout << work;
    return 0;
}
