#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    string key = "CIPHERABDGJKLMNOQSTUVWXYZ";

    cout << "Enter the plaintext: ";
    getline(cin, text);

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] >= 'A' && text[i] <= 'Z')
            text[i] = key[text[i] - 'A'];
        else if (text[i] >= 'a' && text[i] <= 'z')
            text[i] = key[text[i] - 'a'];
    }

    cout << "Ciphertext: " << text << endl;
    return 0;
}
