#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;//돌 개수

    n % 2 == 1 ? cout << "SK" : cout << "CY";

    return 0;
}
