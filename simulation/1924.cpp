#include <iostream>

using namespace std;

int main(){
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int x, y;
    cin >> x >> y;

    int m = y;
    for(int i = 0; i < x-1; i++){//저번달 day + 현재달 day라서 -1
        m += mon[i];
    }

    cout << day[m % 7];

    return 0;
}
