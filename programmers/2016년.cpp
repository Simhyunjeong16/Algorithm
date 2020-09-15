#include <string>
#include <vector>

using namespace std;

string day[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};//1월1일이 금요일이기 때문에
int month[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

string solution(int a, int b) {
    string answer = "";    
    int total = b;//현재달 날짜 더하기
    
    for(int i = 0; i < a-1; i++){//저번달 날짜 더하기
        total += month[i];
    }
    
    answer = day[total % 7];
    
    return answer;
}