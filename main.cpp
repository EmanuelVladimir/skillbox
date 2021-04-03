#include <iostream>

char encrypt_caesar (char sim, int shift){
    if (sim > 64 && sim < 91){
        return (sim+shift) > 90 ? ((sim + shift) - 90 + 64) : ((sim + shift) < 65 ? 90 - 64 + (sim+shift) : sim+shift);
    } else if (sim > 96 && sim < 123){
        return (sim+shift) > 122 ? ((sim + shift) - 122 + 96) : ((sim + shift) < 97 ? 122 - 96 + (sim+shift) : sim+shift);
    }
}
char decrypt_caesar (char sim, int shift){
    return encrypt_caesar(sim, -shift);
}

int main() {
    int shift;
    std::string str, resEncrypt, resDecrypt;
    std::cout << "Enter thr line:\n";
    std::getline(std::cin, str);
    std::cout << "Enter shift number:\n";
    std::cin >> shift;

    for (int i = 0; i < str.length(); i++){
        if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'){
            resEncrypt += encrypt_caesar(str[i], shift);
        }else resEncrypt += str[i];
    }
    std::cout << resEncrypt << "\n";

    for (int i = 0; i < resEncrypt.length(); i++){
        if (resEncrypt[i] >= 'A' && resEncrypt[i] <= 'Z' || resEncrypt[i] >= 'a' && resEncrypt[i] <= 'z'){
            resDecrypt += decrypt_caesar(resEncrypt[i], shift);
        }else resDecrypt += resEncrypt[i];
    }
    std::cout << resDecrypt << "\n";
}
