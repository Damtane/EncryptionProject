#ifndef ENCRYPTOR_HPP
#define ENCRYPTOR_HPP

#include <string>

using namespace std;

class Encryptor {
public:
    explicit Encryptor(uint32_t key);

    string encrypt(const string& plainText);

    string decrypt(const string& cipherText);

private:
    uint32_t roundFunction(uint32_t halfBlock, uint32_t key);

    uint32_t key;

    static const int NUM_ROUNDS = 4;

    
};

#endif