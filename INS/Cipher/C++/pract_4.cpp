#include <iostream>
#include <string>

// Function to extend the key to match the length of the text
std::string extendKey(const std::string &text, const std::string &key) {
    std::string extendedKey = key;
    int textLength = text.length();
    int keyLength = key.length();
    for (int i = 0; i < textLength - keyLength; i++) {
        extendedKey += key[i % keyLength];
    }
    return extendedKey;
}

// Function to encrypt the text using Vigenère Cipher
std::string encryptVigenereCipher(const std::string &text, const std::string &key) {
    std::string encryptedText = "";
    std::string extendedKey = extendKey(text, key);
    
    for (size_t i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyCh = toupper(extendedKey[i]) - 'A';
            encryptedText += (ch - base + keyCh) % 26 + base;
        } else {
            encryptedText += ch;
        }
    }

    return encryptedText;
}

// Function to decrypt the text using Vigenère Cipher
std::string decryptVigenereCipher(const std::string &text, const std::string &key) {
    std::string decryptedText = "";
    std::string extendedKey = extendKey(text, key);
    
    for (size_t i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyCh = toupper(extendedKey[i]) - 'A';
            decryptedText += (ch - base - keyCh + 26) % 26 + base;
        } else {
            decryptedText += ch;
        }
    }

    return decryptedText;
}

int main() {
    std::string text, key;
    char choice;

    // Prompt for key
    std::cout << "Enter the key for the cipher: ";
    std::getline(std::cin, key);

    // Prompt for text and choice
    std::cout << "Enter the text: ";
    std::getline(std::cin, text);
    std::cout << "Do you want to (e)ncrypt or (d)ecrypt? ";
    std::cin >> choice;

    if (choice == 'e' || choice == 'E') {
        std::cout << "Encrypted text: " << encryptVigenereCipher(text, key) << std::endl;
    } else if (choice == 'd' || choice == 'D') {
        std::cout << "Decrypted text: " << decryptVigenereCipher(text, key) << std::endl;
    } else {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}