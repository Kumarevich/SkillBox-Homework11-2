#include <iostream>

int alpha_find (std::string mail) {
    for (int i = 0; i < mail.length(); ++i) {
        if (mail[i] == '@') {
            return i;
        }
    }
    return 0;
}

bool point_check (std::string mail, int alpha) {
    int l = mail.length() - 1;
    if (mail[0] == '.' || mail[alpha - 1] == '.' || mail[alpha + 1] == '.' || mail[l] == '.') {
        return false;
    } else {
        for (int i = 1; i < l; ++i) {
            if (mail[i] == '.' && mail[i - 1] == '.') {
                return false;
            }
        }
    }
    return true;
}

bool checking (std::string mail, int alpha) {
    std::string failCh = "\\(),:;<>@[]'\"";
    if (alpha == 0 || alpha > 64 || (mail.length() - alpha - 1) > 63 || !point_check(mail, alpha)) {
        return false;
    } else {
        for (int i = 0; i < alpha; ++i) {
            if (mail[i] < '!' || mail[i] > '~') {
                return false;
            } else {
                for (int j = 0; j < failCh.length(); ++j) {
                    if (mail[i] == failCh[j]) {
                        return false;
                    }
                }
            }
        }
        for (int i = alpha + 1; i < mail.length(); ++i) {
            if (mail[i] < '-' || (mail[i] > '.' && mail[i] < 'A') || (mail[i] > 'Z' && mail[i] < 'a') || mail[i] > 'z') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::string mail;
    std::cout <<"Input e-mail: ";
    std::cin >> mail;
    int alpha;
    alpha = alpha_find(mail);
    if (checking(mail, alpha)) {
        std::cout << "Yes";
    } else {
        std::cout << "No";
    }
    return 0;
}