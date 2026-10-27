#include <iostream>
#include <string>
using namespace std;

int mod26(int x) { x %= 26; if (x < 0) x += 26; return x; }

int main() {
    int a=9,b=4,c=5,d=7;
    string p="MEETMEATTHEUSUALPLACEATTENRATHERTHANEIGHTOCLOCK";
    while (p.size()%2) p += 'X';

    cout << "Key matrix:\n9 4\n5 7\n\n";
    cout << "Ciphertext: ";
    for (size_t i=0;i<p.size();i+=2) {
        int x=p[i]-'A', y=p[i+1]-'A';
        cout << char('A'+mod26(a*x+b*y));
        cout << char('A'+mod26(c*x+d*y));
    }
    cout << "\n";
    return 0;
}
