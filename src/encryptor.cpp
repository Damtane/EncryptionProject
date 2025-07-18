#include "encryptor.hpp"

#include <bitset>
#include <stdexcept>

// stores the key
Encryptor::Encryptor(uint32_t k) : key(k) {}

// simple feistel cipher
uint32_t Encryptor::roundFunction(uint32_t halfBlock, uint32_t roundKey) {
    return (halfBlock ^ roundKey) + ((halfBlock & roundKey) << 1 );
}

std::string Encryptor::encrypt(const std::string& plainText, uint32_t key) {
    std::string cipherText = plainText;

    for (size_t i = 0; i < cipherText.size(); i += 2) {
        uint32_t left = static_cast<uint8_t>(cipherText[i]);
        uint32_t right = (i + 1 < cipherText.size()) ? static_cast<uint8_t>(cipherText[i + 1]) : 0;

        for (int r = 0; r < NUM_ROUNDS; ++r) {
            uint32_t temp = left;
            left = right ^ roundFunction(left, key);
            right = temp;
        }

        cipherText[i] = static_cast<char>(left);
        if (i + 1 < cipherText.size()) {
            cipherText[i + 1] = static_cast<char>(right);
        }
    }

    return cipherText;
}


std::string Encryptor::decrypt(const std::string& cipherText, uint32_t key) {
    std::string plainText = cipherText;

    for (size_t i = 0; i < plainText.size(); i += 2) {
        uint32_t left = static_cast<uint8_t>(plainText[i]);
        uint32_t right = (i + 1 < plainText.size()) ? static_cast<uint8_t>(plainText[i + 1]) : 0;

        for (int r = 0; r < NUM_ROUNDS; ++r) {
            uint32_t temp = right;
            right = left ^ roundFunction(right, key);
            left = temp;
        }

        plainText[i] = static_cast<char>(left);
        if (i + 1 < plainText.size()) {
            plainText[i + 1] = static_cast<char>(right);
        }
    }

    return plainText;
}