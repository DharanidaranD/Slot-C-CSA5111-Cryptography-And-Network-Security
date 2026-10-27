#include <iostream>
using namespace std;

int mod26(int x){ x%=26; if(x<0)x+=26; return x; }

int main() {
    cout << "Hill Cipher Known/Chosen Plaintext Attack Demonstration\n";
    cout << "Enter two plaintext/ciphertext pairs to recover a 2x2 key.\n";
    int p11,p12,p21,p22,c11,c12,c21,c22;
    cout << "Plaintext matrix row 1: "; cin >> p11 >> p12;
    cout << "Plaintext matrix row 2: "; cin >> p21 >> p22;
    cout << "Ciphertext matrix row 1: "; cin >> c11 >> c12;
    cout << "Ciphertext matrix row 2: "; cin >> c21 >> c22;

    int det = mod26(p11*p22-p12*p21);
    int inv=-1;
    for(int i=0;i<26;i++) if(mod26(det*i)==1) inv=i;
    if(inv==-1){ cout<<"Plaintext matrix has no inverse mod 26.\n"; return 0; }

    int k11=mod26((c11*p22-c12*p21)*inv);
    int k12=mod26((-c11*p12+c12*p11)*inv);
    int k21=mod26((c21*p22-c22*p21)*inv);
    int k22=mod26((-c21*p12+c22*p11)*inv);

    cout<<"Recovered key matrix:\n";
    cout<<k11<<" "<<k12<<"\n"<<k21<<" "<<k22<<"\n";
    return 0;
}
