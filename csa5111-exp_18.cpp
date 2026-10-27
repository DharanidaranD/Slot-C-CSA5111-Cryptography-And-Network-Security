#include <iostream>
#include <string>
using namespace std;

int main() {
    cout<<"DES key generation demonstration\n";
    cout<<"PC-1 creates two disjoint 28-bit halves C and D.\n";
    cout<<"Each round applies the prescribed left shifts, then PC-2 selects:\n";
    cout<<"24 bits from the C half and 24 bits from the D half.\n\n";

    int shift[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    for(int i=0;i<16;i++)
        cout<<"Round "<<i+1<<": shift C and D by "<<shift[i]<<" bit(s)\n";
    return 0;
}
