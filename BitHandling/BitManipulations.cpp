#include <iostream>
#include <bitset>
#include <cmath>

namespace BitManipulation {
    void setBit(int& value, const uint8_t position){
        value |= (1 << position);
    }

    void clearBit(int& value, const uint8_t position){
        value &= ~(1 << position);
    }

    void toggleBit(int& value, const uint8_t position){
        value ^= (1 << position);
    }

    void invert(int& value){
        value = ~value;
    }

    bool isBitSet(const int value, const uint8_t position){
        return value & (1 << position);
    }

    void getTwosComplement(int& value){
        value = -value;
    }

    void getTwosComplement2(int& value){
        value = ~value + 1;
    }

    int getLowestSetBit(const int value){
        return (value & (-value));
    }

    void clearLowBitsUntilPosition(int& value, const uint8_t position){
        const auto mask = ~((1 << (position+1)) - 1);
        value &= mask;
    }

    void clearHighBitsUntilPosition(int& value, const uint8_t position){
        const auto mask = (1 << position) - 1;
        value &= mask;
    }

    void doubleValue(int& value){
        value <<= 1;
    }

    void halfValue(int& value){
        value >>= 1;
    }

    int countSetBits(const int value){
        auto temp = value;
        auto count = 0;
        while(temp){
            count += 1;
            temp &= (temp - 1);
        }
        return count;
    }

    void lowerUpper(char& c){
        c &= ~0x20;
    }

    int log2(const int value){
        int res = 0; 
        auto temp = value;
        while (temp >>= 1) {
            res++; 
        }
        return temp; 
    }

    bool isPowerOfTwo(const int x){
        return (x && !(x & x-1)); 
    }

    void swapping(int& a, int&b){
        a ^= b; 
        b ^= a; 
        a ^= b;
    }

    int numberOfDigits(const int number){
        return std::floor(std::log10(number)) + 1;  
    }
}

int main(){
    int number = 0x01;
    std::cout << "0b" << std::bitset<8>(number) << std::endl;
    BitManipulation::setBit(number, 3);
    std::cout << "Set Bit#3: 0b" << std::bitset<8>(number) << std::endl;
    BitManipulation::setBit(number, 4);
    std::cout << "Set Bit#4: 0b" << std::bitset<8>(number) << std::endl;
    BitManipulation::clearBit(number,3);
    std::cout << "Clear Bit#3: 0b" << std::bitset<8>(number) << std::endl;
    BitManipulation::toggleBit(number, 0);
    std::cout << "Toggle Bit#0: 0b" << std::bitset<8>(number) << std::endl;
    BitManipulation::toggleBit(number, 0);
    std::cout << "Toggle Bit#0: 0b" << std::bitset<8>(number) << std::endl;
    BitManipulation::invert(number);
    std::cout << "Invert all bits: 0b" << std::bitset<8>(number) << " " << number << std::endl;

    for(int i = 7; i >= 0; i--){
        std::cout << BitManipulation::isBitSet(number, i) << " ";
    }
    std::cout << std::endl;

    BitManipulation::getTwosComplement(number);
    std::cout << "Twos complement: 0b" << std::bitset<8>(number) << " " << number << std::endl;
    BitManipulation::getTwosComplement2(number);
    std::cout << "Twos complement2: 0b" << std::bitset<8>(number) << " " << number << std::endl;
    std::cout << "Lowest SetBit: " << BitManipulation::getLowestSetBit(number) << std::endl;
    BitManipulation::clearLowBitsUntilPosition(number, 4);
    std::cout << "Clear Low Bits until #4: " << std::bitset<8>(number) << std::endl;
    BitManipulation::clearHighBitsUntilPosition(number, 5);
    std::cout << "Clear High Bits until #5: " << std::bitset<8>(number) << std::endl;

    int number2 = 5;
    std::cout << number2 << std::endl;
    BitManipulation::doubleValue(number2);
    std::cout << "Double: " << number2 << std::endl;
    BitManipulation::halfValue(number2);
    std::cout << "Half: " << number2 << std::endl;
    std::cout << "Count Set Bits: " << BitManipulation::countSetBits(number2) << std::endl;
    std::cout << "Log2: " << BitManipulation::log2(number2) << std::endl;
    std::cout << "PowerOfTwo: " << BitManipulation::isPowerOfTwo(number2) << std::endl;

    int number3 = 1234;
    std::cout << "Number2: " << number2 << ", Digits: " << BitManipulation::numberOfDigits(number2) << ", Number3: " << number3 << ", Digits: " << BitManipulation::numberOfDigits(number3) << std::endl;

    char c = 'a';
    std::cout << c << std::endl;
    BitManipulation::lowerUpper(c);
    std::cout << "ToUpper: " << c << std::endl;

    return 0;
}