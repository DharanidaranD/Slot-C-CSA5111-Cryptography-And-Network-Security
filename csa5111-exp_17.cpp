#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    unsigned long long key=0x133457799BBCDFF1ULL;
    cout<<"DES decryption key schedule (reverse order)\n";
    cout<<"Initial key: "<<hex<<uppercase<<key<<dec<<"\n";
    cout<<"Encryption uses K1..K16; decryption uses K16..K1.\n";
    cout<<"For decryption, generate the same 16 subkeys and apply them in reverse order.\n";
    for(int i=16;i>=1;i--) cout<<"K"<<i<<" -> round "<<17-i<<"\n";
    return 0;
}
