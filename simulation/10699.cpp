#include <iostream>
#include <time.h>

using namespace std;

int main(){
    
    time_t curtime;
    struct tm* t;
    
    curtime = time(NULL);
    t = localtime(&curtime);

    cout << t->tm_year+1900 << "-";
    
    cout.width(2);//최소 너비 2로
    cout.fill('0');//최소 너비에 빈 공간을 채울 문자 지정 ->> '0'
    cout<< t->tm_mon+1 << "-" << t->tm_mday;

    return 0;
}
