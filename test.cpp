//
// Created by Alfred T on 2022/5/27.
// Description: 
//

#include <iostream>

using namespace std;

int maxValue(int a, int b) {
    return a > b ? a : b;
}

int minValue(int a, int b) {
    return a > b ? b : a;
}

int add(int a, int b) {
    return a + b;
}

bool processNum(int a, int b, int(*p)(int, int)) {
    cout << p(a, b) << endl;
}

int main(){

    processNum(10, 20, add);

}