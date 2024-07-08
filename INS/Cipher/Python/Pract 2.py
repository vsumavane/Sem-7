def encrypt(str:str, shift:int):
    result=''
    digit="0123456789"
    for char in str:
        if char.isalpha():
            if char.isupper():
                result+=chr((ord(char)+shift-65)%26 + 65)
            else:
                result+=chr((ord(char)+shift-97)%26 + 97)
        elif char in digit:
            index = digit.find(char)
            result += digit[(index+shift)%10]
        else:
            result += char            
    return result
def decrypt(str:str, shift:int):
    return encrypt(str,-shift)

givenString="The Quick Brown Fox"
shift=3
encryptedString = encrypt(givenString,shift)
print(f'Original String: {givenString}')
print(f'Encoded String: {encryptedString}')
print(f'Decoded String: {decrypt(encryptedString,shift)}')