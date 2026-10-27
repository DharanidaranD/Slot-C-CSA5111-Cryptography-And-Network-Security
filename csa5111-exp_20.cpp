#include <iostream>
using namespace std;

int main() {
    cout<<"CBC error propagation analysis\n\n";
    cout<<"a. If C1 has a bit error:\n";
    cout<<"   - P1 is completely corrupted after decryption.\n";
    cout<<"   - P2 has the corresponding bit flipped.\n";
    cout<<"   - Blocks P3 and beyond are NOT affected.\n\n";

    cout<<"b. If one bit of the source plaintext P1 is changed:\n";
    cout<<"   - C1 changes.\n";
    cout<<"   - Because C1 is used in CBC chaining, all later ciphertext blocks\n";
    cout<<"     are affected (C2, C3, ... until the end of the message).\n";
    cout<<"   - At the receiver, P1 has the corresponding one-bit change,\n";
    cout<<"     while subsequent plaintext blocks are recovered normally once\n";
    cout<<"     the correct ciphertext blocks are received.\n";
    return 0;
}
