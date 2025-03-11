#include <iostream>
#include <string>
#include <algorithm> // Для std::reverse

//библиотека неэфф
//это верно
/*float E(int x) {
    double sum = 1.0;
    double term = 1.0;
    for (int n = 1; n <= x; ++n) {
        term /= n;
        sum += term;
    }
    std::cout << "taylor ";
    return sum;
}*/
/*unsigned long long factorial(int n) {
    unsigned long long result_factorial = 1;
    for (int i = 1; i <= n; ++i) {
        result_factorial *= i;
    }
    return result_factorial;
}*/
extern "C" {
char* translation(long x){
long num;
std::string str3;
char* result;
num=x;
if (num==0){
    result =new char[2];
    result[0]='0';
    result[1]='\0';
    return result;
}
std::cout<<"num in taylor_third "<<num<<std::endl;
while (num > 0) {
    //std::cout<<"here3";
    str3+= (num % 3) + '0'; // Добавляем остаток от деления на 3
    num /= 3;
}
std::cout<<"str3_1";
std::reverse(str3.begin(), str3.end());

    result = new char[str3.size() + 1];
    std::copy(str3.begin(), str3.end(), result);
    result[str3.size()] = '\0';
    return result;
}
//тейлор
// Функция для вычисления суммы ряда
float E(int x) {
    double sum = 1.0;
    double term = 1.0;
    for (int n = 1; n <= x; ++n) {
        term /= n;
        sum += term;
    }
    std::cout << "taylor ";
    return sum;
}
/*float E(int x) {
    double sum = 0.0;
    for (int n = 0; n <= x; ++n) {
        sum += 1.0 / factorial(n);
    }
    std::cout<<"taylor ";
    return sum;
}*/

} //extern C закончился