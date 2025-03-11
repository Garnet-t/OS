запуск lab4 main_linked. ucrt64 gcc -c -fPIC limit_binary.cpp -o limit_binary.o аналагичная команда для taylor_third.cpp 
gcc -shared -c -o liblimit_binary.dll limit_binary.o -lstdc++ -lgcc аналогичная команда для taylor_third.cpp
gcc -o main_linked main_linked.cpp -L. -llimit_binary -ltaylor_third -I/c/Users/79152/cpp4/MyDLL/.vscode -lstdc++ -lgcc 
./main_linked.exe
теперь main_dynamic 
путь относительный надо указать тот который прописан в пути к компилятору (то есть liblimit_binary и т д ) 
gcc -c -fPIC limit_binary.cpp -o limit_binary.o

$ gcc -c -fPIC taylor_third.cpp -o taylor_third.o

$ gcc -shared -o liblimit_binary.dll limit_binary.o -lstdc++ -lgcc

$ gcc -shared -o libtaylor_third.dll taylor_third.o -lstdc++ -lgcc

$ gcc -o main_dynamic main_dynamic.cpp -lstdc++ -lgcc
./main_dynamic.exe
