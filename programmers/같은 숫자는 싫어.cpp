#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
//     int n = arr[0];
//     answer.push_back(n);
    
//     for(int i = 1; i < arr.size(); i++){
//         if(n != arr[i]) {
//             n = arr[i];
//             answer.push_back(n);
//         }
//     }
    
    //unique가 끝났으면 반환되는값은 vector의 쓰레기값의 첫번째 위치
    arr.erase(unique(arr.begin(), arr.end()), arr.end());//벡터 중복 제거, 범위 erase
    
    answer = arr;
    
    return answer;
}
