#include <iostream>
#include <string>
using namespace std;

int main() {
    string p="SENDMOREMONEY";
    int key[]={9,0,1,7,23,15,21,14,11,11,2,8,9};
    string c;
    for(int i=0;i<p.size();i++) c += char('A'+(p[i]-'A'+key[i])%26);
    cout<<"Ciphertext: "<<c<<"\n";

    string target="CASHNOTNEEDED";
    cout<<"Key stream for target plaintext: ";
    for(int i=0;i<c.size();i++) {
        int k=(c[i]-target[i]+26)%26;
        cout<<k<<" ";
    }
    cout<<"\n";
    return 0;
}
