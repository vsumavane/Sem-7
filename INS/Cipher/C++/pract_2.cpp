#include <iostream>
#include <unordered_map>
#include <string>

// Function to generate the encryption and decryption maps based on the key
void generateMaps(std::string key, std::unordered_map<char, char>& encryptMap, std::unordered_map<char, char>& decryptMap) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < alphabet.length(); i++) {
        encryptMap[alphabet[i]] = key[i];
        decryptMap[key[i]] = alphabet[i];
    }
}

// Function to encrypt the text using Monoalphabetic Cipher
std::string encryptMonoalphabeticCipher(std::string text, std::unordered_map<char, char>& encryptMap) {
    std::string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            result += isupper(ch) ? toupper(encryptMap[lower]) : encryptMap[lower];
        } else {
            result += ch;
        }
    }

    return result;
}

// Function to decrypt the text using Monoalphabetic Cipher
std::string decryptMonoalphabeticCipher(std::string text, std::unordered_map<char, char>& decryptMap) {
    std::string result = "";

    for (char ch : text) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            result += isupper(ch) ? toupper(decryptMap[lower]) : decryptMap[lower];
        } else {
            result += ch;
        }
    }

    return result;
}

int main() {
    std::string text, key;
    char choice;
    std::unordered_map<char, char> encryptMap, decryptMap;

    // Prompt for key
    std::cout << "Enter the 26-letter key for the cipher (e.g., QWERTYUIOPASDFGHJKLZXCVBNM): ";
    std::cin >> key;

    // Generate maps
    generateMaps(key, encryptMap, decryptMap);

    // Clear the input buffer
    std::cin.ignore();

    // Prompt for text and choice
    std::cout << "Enter the text: ";
    std::getline(std::cin, text);
    std::cout << "Do you want to (e)ncrypt or (d)ecrypt? ";
    std::cin >> choice;

    if (choice == 'e' || choice == 'E') {
        std::cout << "Encrypted text: " << encryptMonoalphabeticCipher(text, encryptMap) << std::endl;
    } else if (choice == 'd' || choice == 'D') {
        std::cout << "Decrypted text: " << decryptMonoalphabeticCipher(text, decryptMap) << std::endl;
    } else {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}
