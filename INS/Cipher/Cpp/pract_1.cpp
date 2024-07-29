#include <iostream>
#include <string>

// Function to encrypt the text using Caesar Cipher
std::string encryptCaesarCipher(std::string text, int shift) {
    std::string result = "";

    // Traverse text
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (isupper(ch))
            result += char(int(ch + shift - 65) % 26 + 65);

        // Encrypt lowercase letters
        else if (islower(ch))
            result += char(int(ch + shift - 97) % 26 + 97);

        // Encrypt digits
        else if (isdigit(ch))
            result += char(int(ch + shift - 48) % 10 + 48);

        // Leave other characters unchanged
        else
            result += ch;
    }

    return result;
}

// Function to decrypt the text using Caesar Cipher
std::string decryptCaesarCipher(std::string text, int shift) {
    std::string result = "";

    // Traverse text
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        // Decrypt uppercase letters
        if (isupper(ch))
            result += char(int(ch - shift - 65 + 26) % 26 + 65);

        // Decrypt lowercase letters
        else if (islower(ch))
            result += char(int(ch - shift - 97 + 26) % 26 + 97);

        // Decrypt digits
        else if (isdigit(ch))
            result += char(int(ch - shift - 48 + 10) % 10 + 48);

        // Leave other characters unchanged
        else
            result += ch;
    }

    return result;
}

int main() {
    std::string text;
    int shift;
    char choice;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);
    std::cout << "Enter the shift value: ";
    std::cin >> shift;
    std::cout << "Do you want to (e)ncrypt or (d)ecrypt? ";
    std::cin >> choice;

    if (choice == 'e' || choice == 'E') {
        std::cout << "Encrypted text: " << encryptCaesarCipher(text, shift) << std::endl;
    } else if (choice == 'd' || choice == 'D') {
        std::cout << "Decrypted text: " << decryptCaesarCipher(text, shift) << std::endl;
    } else {
        std::cout << "Invalid choice" << std::endl;
    }

    return 0;
}
