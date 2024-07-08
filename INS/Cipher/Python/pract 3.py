def create_cipher_mapping():
    import string
    from random import shuffle

    letters = list(string.ascii_lowercase)
    shuffled_letters = letters[:]
    shuffle(shuffled_letters)

    cipher_mapping = dict(zip(letters, shuffled_letters))
    return cipher_mapping

def encrypt_MonoAlphabetic(plain_text, cipher_mapping):
    encrypted_text = []
    for char in plain_text.lower():
        if char in cipher_mapping:
            encrypted_text.append(cipher_mapping[char])
        else:
            encrypted_text.append(char)  
    return ''.join(encrypted_text)

def decrypt(encrypted_text, cipher_mapping):
    reversed_mapping = {v: k for k, v in cipher_mapping.items()}
    decrypted_text = []
    for char in encrypted_text:
        if char in reversed_mapping:
            decrypted_text.append(reversed_mapping[char])
        else:
            decrypted_text.append(char)  
    return ''.join(decrypted_text)

cipher_mapping = create_cipher_mapping()
print("Cipher Mapping:", cipher_mapping)

plain_text = "Hello, World!"
encrypted_text = encrypt_MonoAlphabetic(plain_text, cipher_mapping)
print("Encrypted Text:", encrypted_text)

decrypted_text = decrypt(encrypted_text, cipher_mapping)
print("Decrypted Text:", decrypted_text)