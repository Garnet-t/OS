#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <general.h>
// Объявление функций из библиотеки
extern "C" {
    char* translation(long x);
    float E(int x);
}
void handle_command_1() {
    //число e 
    int x;
    float resultexp;
            std::cout << "exponenta, input x  ";
            std::cin>>x;
            resultexp=E(x);
            std::cout<<"resulty of exponenta:"<<resultexp<<std::endl;
            return;
}
void handle_command_2() {
    long num;
    char* result;
    std::cout << "enter num for translating >=0 ";
    std::cin >> num;
    result = translation(num);
    std::cout << "result is " << result << std::endl;
    delete[] result;
    return ;
}



int main() {
    std::string input;
    while(true) {
        std::cout << "Input command ONLY: "<<std::endl;
        std::getline(std::cin, input);
        if(input.empty()) continue;

        if(input[0] == '1') {
            handle_command_1();
            break;
        }
        else if(input[0] == '2') {
            handle_command_2();
            break;
        }
        else {
            std::cout << "Error command or symbol" << std::endl;
            break;
        }
    }
    return 0;
}
