#ifndef ENCRYPTOR_HPP
#define ENCRYPTOR_HPP

#include <string>


class Encryptor {
public:
    Encryptor() = default;

    explicit Encryptor(uint32_t key);

    std::string encrypt(const std::string& plainText, uint32_t key);

    std::string decrypt(const std::string& cipherText, uint32_t key);

private:
    uint32_t roundFunction(uint32_t halfBlock, uint32_t key);

    uint32_t key;

    static const int NUM_ROUNDS = 4;

    
};

#endif