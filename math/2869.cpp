#include <iostream>

using namespace std;

int main(){
    int a, b, v;
    cin >> a >> b >> v;

    //도착했을 시, 밤에는 미끌어지지 않는다.
    //하루에 a-b 만큼씩 올라간다.
    //(v-b) / (a-b)로 딱 나눠떨어지지 않으면 몫에 +1
    //int형이라서 나눠떨어지는지 구분하기 귀찮으니까, 미리 -1을 하고 몫에 +1
    int res = (v-b-1) / (a-b) +1;

    cout << res;

    return 0;
}
