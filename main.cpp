#include "encryptor.hpp"
#include <iostream>

int main() {
    Encryptor encryptor;

    std::string input = "Hello, Huntsville!";
    uint32_t key = 0x12345678;

    std::string encrypted = encryptor.encrypt(input, key);
    std::string decrypted = encryptor.decrypt(encrypted, key);

    std::cout << "Original: " << input << "\n";
    std::cout << "Encrypted: " << encrypted << "\n";
    std::cout << "Decrypted: " << decrypted << "\n";

    return 0;

}