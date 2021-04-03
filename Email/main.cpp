#include <iostream>

std::string firstHalf (std::string email){
    std::string res;
    for (int i = 0; i <email.length(); i++){
        if (email[i]=='@'){
            return res;
        }else res += email[i];
    }
    return res;
}

std::string secondHalf (std::string str, int lenFirstHalf){
    std::string res;
    for (int i = lenFirstHalf + 2; i < str.length(); i++){
        res += str[i];
    }
    return res;
}

bool symbols (std::string email, std::string example){
    bool ok = false;
    for (int i = 0; i < email.length(); i++){
        for (int n = 0; n < example.length(); n++){
            if (firstHalf(email)[i] != example[n]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::string email, firstExample, secondExample;
    std::cout << "Enter your email:\n";
    std::cin >> email;
    secondExample = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM-.";
    firstExample = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM-.!#$%&'*+-/=?^_`{|}~";

    int dotPosition = 0;
    for (int i = 0; i < email.length()-1; i++){
        if (email[i] == '.' && email[i+1] == '.'){
            std::cout << "No. Two dots one after the another\n";
            return 0;
        }
    }

    if (firstHalf(email).length() > 63 || secondHalf(email, firstHalf(email).length()).length() > 62
        || firstHalf(email).length() < 1 || secondHalf(email, firstHalf(email).length()).length() < 1){
        std::cout << "No, too much or too few symbols in first or second half\n";
        return 0;
    }
    bool dog = false;
    int dogDot = email.length();
    for (int i = 0; i < email.length(); i++){
        if (email[i] == '@' && i < dogDot) {
            dog = true;
            dogDot = i;
        }else if (email[i] == '@' && i > dogDot){
            dog = false;
        }
    }
    if (dog == false){
        std::cout << "No. No @ in email or more then 1 @\n";
        return 0;
    }
    else if (symbols(firstHalf(email), firstExample) == false){
        std::cout << "No. Invalid symbols\n";
        return 0;
    }
    else if (symbols(secondHalf(email,firstHalf(email).length()), secondExample) == false){
        std::cout << "No. Invalid symbols\n";
        return 0;
    }
    else if (email[0] == '.' || email[email.length()-1] == '.') {
        std::cout << "No. dot on the first or last position\n";
        return 0;
    }else std::cout << "Yes\n";

}
