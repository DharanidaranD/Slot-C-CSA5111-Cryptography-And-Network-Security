#include <iostream>
#include <iomanip>
using namespace std;

// Educational 64-bit CBC demonstration using a placeholder block cipher.
// Replace encryptBlock() with a real AES/3DES implementation for production use.
unsigned long long encryptBlock(unsigned long long x, unsigned long long key) {
    return x ^ key;
}

int main() {
    unsigned long long key, iv, p1, p2;
    cout<<"Enter key, IV, P1 and P2 in hexadecimal:\n";
    cin>>hex>>key>>iv>>p1>>p2;

    unsigned long long c1=encryptBlock(p1^iv,key);
    unsigned long long c2=encryptBlock(p2^c1,key);

    cout<<"C1 = "<<c1<<"\n";
    cout<<"C2 = "<<c2<<"\n";
    cout<<dec;
    cout<<"Security: use a modern cipher such as AES.\n";
    cout<<"Performance: AES is generally preferred over 3DES on modern hardware.\n";
    return 0;
}
