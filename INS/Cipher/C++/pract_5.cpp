#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to generate the key matrix from the key string
void getKeyMatrix(string key, int keyMatrix[][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

// Function to get the cofactor matrix
void getCofactor(int matrix[3][3], int temp[3][3], int p, int q, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (row != p && col != q) {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Function to calculate the determinant of the matrix
int determinant(int matrix[3][3], int n) {
    int det = 0;
    if (n == 1) return matrix[0][0];

    int temp[3][3];
    int sign = 1;
    for (int i = 0; i < n; i++) {
        getCofactor(matrix, temp, 0, i, n);
        det += sign * matrix[0][i] * determinant(temp, n - 1);
        sign = -sign;
    }
    return det;
}

// Function to find adjoint of a matrix
void adjoint(int matrix[3][3], int adj[3][3]) {
    if (3 == 1) {
        adj[0][0] = 1;
        return;
    }

    int sign = 1, temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            getCofactor(matrix, temp, i, j, 3);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, 3 - 1));
        }
    }
}

// Function to find the modular inverse of a number
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Function to find the inverse of the key matrix
bool inverseKeyMatrix(int keyMatrix[3][3], int inverse[3][3]) {
    int det = determinant(keyMatrix, 3);
    int invDet = modInverse(det, 26);
    if (invDet == -1) {
        cout << "Inverse doesn't exist";
        return false;
    }

    int adj[3][3];
    adjoint(keyMatrix, adj);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inverse[i][j] = (adj[i][j] * invDet) % 26;
            if (inverse[i][j] < 0) inverse[i][j] += 26;
        }
    }
    return true;
}

// Function to encrypt the message
void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) {
    for (int i = 0; i < 3; i++) {
        cipherMatrix[i][0] = 0;
        for (int j = 0; j < 3; j++) {
            cipherMatrix[i][0] += keyMatrix[i][j] * messageVector[j][0];
        }
        cipherMatrix[i][0] = cipherMatrix[i][0] % 26;
    }
}

// Function to decrypt the message
void decrypt(int plainMatrix[][1], int inverseKeyMatrix[][3], int cipherVector[][1]) {
    for (int i = 0; i < 3; i++) {
        plainMatrix[i][0] = 0;
        for (int j = 0; j < 3; j++) {
            plainMatrix[i][0] += inverseKeyMatrix[i][j] * cipherVector[j][0];
        }
        plainMatrix[i][0] = plainMatrix[i][0] % 26;
    }
}

// Function to implement Hill Cipher encryption
void HillCipherEncrypt(string message, string key) {
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    // Pad the message to make its length a multiple of 3
    while (message.length() % 3 != 0) {
        message += 'X'; // Padding with 'X'
    }

    string CipherText;
    for (size_t i = 0; i < message.length(); i += 3) {
        int messageVector[3][1];
        for (int j = 0; j < 3; j++) {
            messageVector[j][0] = (message[i + j]) % 65;
        }

        int cipherMatrix[3][1];
        encrypt(cipherMatrix, keyMatrix, messageVector);

        for (int j = 0; j < 3; j++) {
            CipherText += cipherMatrix[j][0] + 65;
        }
    }

    // Print the ciphertext
    cout << "Ciphertext: " << CipherText << endl;
}

// Function to implement Hill Cipher decryption
void HillCipherDecrypt(string ciphertext, string key) {
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int inverseMatrix[3][3];
    if (!inverseKeyMatrix(keyMatrix, inverseMatrix)) {
        cout << "Key matrix is not invertible. Decryption aborted." << endl;
        return;
    }

    string PlainText;
    for (size_t i = 0; i < ciphertext.length(); i += 3) {
        int cipherVector[3][1];
        for (int j = 0; j < 3; j++) {
            cipherVector[j][0] = (ciphertext[i + j]) % 65;
        }

        int plainMatrix[3][1];
        decrypt(plainMatrix, inverseMatrix, cipherVector);

        for (int j = 0; j < 3; j++) {
            PlainText += plainMatrix[j][0] + 65;
        }
    }

    // Print the plaintext
    cout << "Plaintext: " << PlainText << endl;
}

int main() {
    string message;
    string key = "GYBNQKURP";

    cout << "Enter the message: ";
    getline(cin, message);

    HillCipherEncrypt(message, key);

    string ciphertext;
    cout << "Enter the ciphertext: ";
    getline(cin, ciphertext);

    HillCipherDecrypt(ciphertext, key);

    return 0;
}