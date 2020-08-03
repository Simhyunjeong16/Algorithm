#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int msize = money.size();
    vector<int> a;//첫번째 집부터 훔치는 경우
    vector<int> b;//두번째 집부터 훔치는 경우
    
    //vector의 크기를 msize로 변경하고 확장되는 공간 값을 money[0]으로 초기화한다.
    a.resize(msize, money[0]); 
    b.resize(msize, money[1]); b[0] = 0;//0위치는 사용하지 않으니 0으로 하기.
    
    for(int i = 2; i < msize-1; i++){
        a[i] = max(a[i-2] + money[i], a[i-1]);
        //(현재 집 -2) 집의 돈 + 현재 도둑질 하려는 집의 돈 vs (현재 집-1)집의 돈
    }
    
    for(int i = 2; i < msize; i++){
        b[i] = max(b[i-2] + money[i], b[i-1]);
        // cout << b[i-2] + money[i] << " " << b[i-1] << endl;
    }
    
    // cout << a[msize - 2] << " " << b[msize - 1] << endl;
    answer = max(a[msize - 2], b[msize - 1]);
    
    return answer;
}