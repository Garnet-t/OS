#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <limits>
// Определение типов функций
typedef char* (*translation_func)(long);
typedef float (*EFunc)(int);//тип указателя на функцию
int main() {
    // Пути к библиотекам
    LPCSTR Path_library1;
    LPCSTR Path_library2;
    HMODULE handle1;
    HMODULE handle2;
    HMODULE current_handle;
    Path_library1 = "liblimit_binary.dll";//у меня называется liblimit.dll
    Path_library2 = "libtaylor_third.dll";

    // Загрузка библиотек
    handle1 = LoadLibrary(Path_library1);//загрузка данной библиотеки + это дескриптор библиотеки необходимый для закрытия FreeLibrary
    if (handle1==NULL) {
        std::cerr << "cant open library1 " << Path_library1 << ": " << GetLastError() << std::endl;
        FreeLibrary(handle1);
        return 1;
    }

    handle2 = LoadLibrary(Path_library2);
    if (handle2==NULL) {
        std::cerr << "cant open library2 " << Path_library2 << ": " << GetLastError() << std::endl;
        FreeLibrary(handle2);
        return 1;
    }
    EFunc E=(EFunc)GetProcAddress(handle1, "E");
    //EFunc_addr верно но надо E 
    // Начальная библиотека пусть  данная буфер()такая 
    current_handle = handle1;
    translation_func translation = (translation_func)GetProcAddress(current_handle, "translation");
    //translation_addr верно но надо translation
    if (translation==NULL){
        std::cerr << "No function E in biblothek" << std::endl;
        FreeLibrary(current_handle);
        return 1;
    }
    /*EFunc  efunc_addr= (EFunc)GetProcAddress(current_handle, "E");
    if (efunc_addr == NULL) {
        std::cerr << "No function E in biblothek" << std::endl;
        FreeLibrary(current_handle);
        return 1;
    }*/
  /*  EFunc efunc_addr = (EFunc)GetProcAddress(current_handle, "E");
    if (efunc_addr == NULL) {
        DWORD errorCode = GetLastError();
        if (errorCode != 0) {
            printLastError("No E function in bibliothek");
        } else {
            std::cerr << "No E function in bibliothek" << std::endl;
        }
        FreeLibrary(current_handle);
        return 1;
    }*/



    //команды
    std::string input;
    while(true) {
        std::cout << "Input command: ";
        std::getline(std::cin, input);
        if(input.empty()) continue;
        if(input[0] == '0') {
            std::cout<<"bibliotheks are buffing"<<std::endl;

            // Переключение библиотек
            if(current_handle == handle1) {
                current_handle = handle2;
                std::cout << "from limit_binary to taylor_third" << std::endl;
            }
            else {//если данная библиотека оказалась тейлор+3чная
                current_handle = handle1;
                std::cout << "from second library to first library(taylor to limit)" << std::endl;
                
            }
            // Обновление функций
           // EFunc E = (EFunc)GetProcAddress(current_handle, "E");
            translation = (translation_func)GetProcAddress(current_handle, "translation");
            E = (EFunc)GetProcAddress(current_handle, "E");
            if (translation == NULL || E == NULL) {
                std::cerr << "Failed to get address for function. Error code: " << GetLastError() << std::endl;
                FreeLibrary(handle1);
                FreeLibrary(handle2);
                return 1;
            }
            /*if  (translation == NULL) {
               // printLastError("No function translation in library1");
                std::cerr << "Failed to get address for function 'translation'. Error code: " << GetLastError() << std::endl;
                FreeLibrary(handle1);
                FreeLibrary(handle2);
                return 1;
                 }
            E = (EFunc)GetProcAddress(current_handle, "E");
            if  (E == NULL) {
                //printLastError("No function translation in library2");
                std::cerr << "Failed to get address for =exponenta. Error code: " << GetLastError() << std::endl;
                FreeLibrary(handle1);
                FreeLibrary(handle2);
                return 1;
                 }*/
           /* if (E == NULL) {
                DWORD errorCode = GetLastError();
                if (errorCode != 0) {
                    printLastError("No E function");
                } else {
                    std::cerr << "No E function in biblothek" << std::endl;
                }
                FreeLibrary(current_handle);
                return 1;
            }*/
        continue;
        }
         else if(input[0] == '1') {
            int x;
            float resultexp;
            std::cout << "exponenta, input x  ";
            std::cin>>x;//EFunc_addr это верно но надо E
            resultexp=E(x);
            std::cout<<"result of exponenta is:"<<resultexp<< std::endl;
            break;
        }
        else if(input[0] == '2') {
            long num;//вычисление числа е должно быть
            char* result;
            std::cout << " num >0 for binary/ trinary ";
            std::cin >> num;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера
            result = translation(num);
            std::cout << "In other system num is:" << result << std::endl;
            delete[] result;
            break;
        }
        else {
            std::cout<<"error command or symbol"<<std::endl;
            break;
        }
        
    }

    // Закрытие библиотек 
    FreeLibrary(handle1);
    FreeLibrary(handle2);
    return 0;
}