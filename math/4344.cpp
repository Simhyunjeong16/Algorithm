#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int c;
    scanf("%d", &c);
    
    for(int i = 0; i < c; i++){
        int n, x, sum = 0;
        vector<int> v;

        cin >> n;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            sum += x;
            v.push_back(x);
        }

        int avg = sum / n;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(v[i] > avg) cnt++;
        }
        float res = (float)cnt / (float)n * 100;
        //printf("%0.3lf%\n", round(res * 1000) / 1000);

        cout << fixed;//소수점 자릿수 고정, cout.precision(3)의 3이 소수점 위치를 나타내는 숫자로 변경
        cout.precision(3);//출력 시, 총 몇자리를 출력할 것인가
        cout << round(res * 1000) / 1000 << '%' << endl;
    }


    return 0;
}
