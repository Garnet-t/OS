#include <iostream>
#include <cmath> // Для функции pow
#include <cstdlib>
#include <string>
#include <algorithm>

extern "C" {
//Сигнатура 
// Char* translation(long x)
// в  двоичную систему
char* translation(long x) {
    long num;
    std::string str2;
    char* result;
    num = x;
    if (num == 0) {
        result    = new char[2];
        result[0] = '0';
        result[1] = '\0';
        std::cout<<"str2";
        return result;
    }
    while (num > 0) {
        if (num % 2 ==0 ) {str2 += '0';} else {
            str2 += '1';
        }
           num  = num / 2;
    }
    std::cout<<"str2_1";
    std::reverse(str2.begin(), str2.end());

    result = new char[str2.size() + 1];
    std::copy(str2.begin(), str2.end(), result);
    result[str2.size()] = '\0';
    return result;
}
//(1+1/x)


// Функция для вычисления числа e с использованием формулы (1 + 1/x)^x
float E(int x) {
       if (x <= 0) {
        throw std::invalid_argument("x must be > 0 ");
       }
       std::cout<<"with (1 + 1/x)^x";
      return pow(1.0 + 1.0 / x, x);
   }
} // extern "C"