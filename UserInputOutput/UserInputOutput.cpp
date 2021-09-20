#include <iostream>
#include <iomanip>
#include <string>

int main(){
    int i = 0;
    // std::cout << "Enter a number" << std::endl;
    // std::cin >> i;
    // std::cout << i << std::endl;

    // Changing cout configuration
    std::ios oldState(nullptr);
    oldState.copyfmt(std::cout);
    int number = 0xAA;
    std::cout << std::dec << number << std::endl;
    std::cout << std::hex << number << std::endl;
    std::cout << "0x" << std::setfill('0') << std::setw(4) << std::hex << number << std::endl;
    std::cout << "0x" << std::setfill('0') << std::setw(6) << std::hex << number << std::endl;
    std::cout << "0x" << std::setfill('0') << std::setw(8) << std::hex << number << std::endl;
    std::cout.copyfmt(oldState); // reset output
    std::cout << std::showbase  << std::hex << number << std::endl; // Output: 0XFF
    std::cout << std::uppercase << std::showbase  << std::hex << number << std::endl; // Output: 0XFF
    std::cout << std::nouppercase << std::showbase  << std::hex << number << std::endl; // Output: 0xff
    std::cout.copyfmt(oldState); // reset output

    std::cout<<std::setw(20)<<"setw(20)"<<std::endl;
    std::cout<<std::setw(10)<<"setw(10)"<<std::endl;
    std::cout<<std::setw(15)<<"setw(15)"<<std::endl;

    return 0;
}