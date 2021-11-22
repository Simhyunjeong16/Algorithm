#include <iostream>

using namespace std;

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    //가감법
    int x = (c*e - f*b) / (a*e - d*b);
    int y = (c*d - a*f) / (b*d - a*e);


    cout << x << ' ' << y;

    return 0;
}
