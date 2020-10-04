#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    sort(arr.begin(), arr.end());//오름차순 정렬
    
    int m = arr[arr.size()-1];
    int n = 0;
    
    while(1){
        answer = m * (++n);//가장 큰수를 골라서 1,2,3... 배를 해보며 체크
        int i;
        
        for(i = 0; i < arr.size(); i++){
            if(answer % arr[i] != 0) break;// while문 다시 실행
        }
        
        if(i == arr.size()) break;//탈출
    }
    
    return answer;
}
