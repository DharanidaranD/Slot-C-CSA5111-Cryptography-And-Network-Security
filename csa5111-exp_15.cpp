#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string c; int top;
    cout<<"Enter ciphertext: "; getline(cin,c);
    cout<<"Enter number of candidates: "; cin>>top;

    vector<pair<int,int>> score;
    const string freq="ETAOINSHRDLCUMWFGYPBVKJXQZ";
    for(int k=0;k<26;k++) {
        int s=0;
        for(char ch:c) if(ch>='A'&&ch<='Z')
            if(ch==freq[k]) s++;
        score.push_back({s,k});
    }
    sort(score.rbegin(),score.rend());

    cout<<"\nPossible plaintexts (rough frequency ranking):\n";
    for(int n=0;n<top && n<26;n++) {
        int shift=score[n].second;
        cout<<n+1<<". Shift "<<shift<<": ";
        for(char ch:c) {
            if(ch>='A'&&ch<='Z') cout<<char('A'+(ch-'A'-shift+26)%26);
            else cout<<ch;
        }
        cout<<"\n";
    }
    return 0;
}
