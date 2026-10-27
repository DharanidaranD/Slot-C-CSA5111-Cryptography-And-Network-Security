#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Playfair keyspace: 25! possible arrangements of the 25 letters.
    long double keys = 1.0L;
    for (int i = 2; i <= 25; i++) keys *= i;

    cout << "Possible Playfair keys = 25! = " << keys << endl;
    cout << "Approximate power of 2 = 2^" << log2(keys) << endl;

    // Effectively unique keys: divide by 2^? for row/column symmetries is
    // commonly estimated as 2^49 for the standard Playfair keyspace.
    cout << "Effectively unique keys are approximately 2^49." << endl;
    return 0;
}
