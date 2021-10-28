#include <iostream>

using namespace std;

int main(){
    int x, y;
    int answer;

    cin >> x >> y;

    if(x > 0 && y > 0) answer = 1;
    else if(x < 0 && y > 0) answer = 2;
    else if(x > 0 && y < 0) answer = 4;
    else answer = 3;

    cout << answer;
    return 0;
}
