#include <iostream>

using namespace std;

class ICryptage
{
public:
    virtual ~ICryptage() {}
    virtual string encrypt() {}
};


class CeasarCipher: public ICryptage {
public:
    string text;
    int s;

    CeasarCipher(string text, int s) {
        this->text=text;
        this->s=s;
    }

    const string &getText() const {
        return text;
    }

    int getS() const {
        return s;
    }

    string encrypt(){
        string result = "";
        for (int i=0;i<text.length();i++) {
            if (isupper(text[i]))
                result += char(int(text[i]+s-65)%26 +65);
            else
                result += char(int(text[i]+s-97)%26 +97);
        }
        return result;
    }
    string decrypt(){
        string result = "";
        for (int i=0;i<text.length();i++) {
            if (isupper(text[i]))
                result += char(int(text[i]-s-65)%26 +65);
            else
                result += char(int(text[i]-s-97)%26 +97);
        }
        return result;
    }
};



class VigenereCipher: public ICryptage {
public:
    string text;
    string key;

    VigenereCipher(string text, string key) {
        this->text=text;
        this->key=key;
    }

    const string &getText() const {
        return text;
    }

    const string &getKey() const {
        return key;
    }

    string encrypt(){
        string out;
        for(int i = 0, j = 0; i < text.length(); ++i) {
            char c = text[i];
            if(c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if(c < 'A' || c > 'Z')
                continue;

            out += (c + key[j] - 2*'A') % 26 + 'A';
            j = (j + 1) % key.length();
        }
        return out;
    }
    string decrypt(){
        string out;
        for(int i = 0, j = 0; i < text.length(); ++i) {
            char c = text[i];

            if(c >= 'a' && c <= 'z')
                c += 'A' - 'a';
            else if(c < 'A' || c > 'Z')
                continue;

            out += (c - key[j] + 26) % 26 + 'A';
            j = (j + 1) % key.length();
        }
        return out;
    }
};


int main() {
    cout << "\n==============\n ";

    CeasarCipher *myCeaser = new CeasarCipher("bonjour", 5);
    cout << "\nCRYPTAGE CESAR";
    cout << "\nMessage d'origine : " << myCeaser->getText() << "\nPas de : " << myCeaser->getS();
    cout << "\nCipher: " << myCeaser->encrypt()<< "\n";

    CeasarCipher *myCeaser2 = new CeasarCipher(myCeaser->encrypt(), myCeaser->getS());
    cout << "\nDECRYPTAGE CESAR";
    cout << "\nMessage d'origine : " << myCeaser2->getText() << "\nPas de : " << myCeaser2->getS();
    cout << "\nCipher: " << myCeaser2->decrypt()<< "\n";

    cout << "\n==============\n ";

    VigenereCipher *myVigenere = new VigenereCipher("bonjour", "oui");
    cout << "\nCRYPTAGE VIGENERE";
    cout << "\nMessage d'origine : " << myVigenere->getText() << "\nClef : " << myVigenere->getKey();
    cout << "\nCipher: " << myVigenere->encrypt() << "\n";

    VigenereCipher *myVigenere2 = new VigenereCipher(myVigenere->encrypt(), myVigenere->getKey());
    cout << "\nDECRYPTAGE VIGENERE";
    cout << "\nMessage d'origine : " << myVigenere2->getText() << "\nClef : " << myVigenere2->getKey();
    cout << "\nCipher: " << myVigenere2->decrypt() << "\n";

    cout << "\n==============\n ";

    return 0;
}