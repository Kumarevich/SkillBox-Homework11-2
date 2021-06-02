#include <iostream>

int alpha_find (std::string mail) {
    int alpha = 0;
    for (int i = 0; i < mail.length(); ++i) {
        if (mail[i] == '@') {
            return alpha = i;
        }
    }
    return alpha;
}

bool point_check (std::string mail, int alpha) {
    int l = mail.length() - 1;
    if (mail[0] == 46 || mail[alpha - 1] == 46 || mail[alpha + 1] == 46 || mail[l] == 46) {
        return false;
    } else {
        for (int i = 1; i < l; ++i) {
            if (mail[i] == 46 && mail[i - 1] == 46) {
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
            if (mail[i] < 33 || mail[i] > 126) {
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
            if (mail[i] < 45 || (mail[i] > 46 && mail[i] < 65) || (mail[i] > 90 && mail[i] < 97) || mail[i] > 122) {
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