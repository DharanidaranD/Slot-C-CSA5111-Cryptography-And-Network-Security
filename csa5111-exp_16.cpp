#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string c; int top;
    cout<<"Enter ciphertext: "; getline(cin,c);
    cout<<"Enter number of candidates: "; cin>>top;

    string order="ETAOINSHRDLCUMWFGYPBVKJXQZ";
    int count[26]={0};
    for(char ch:c) if(ch>='A'&&ch<='Z') count[ch-'A']++;

    vector<int> idx(26);
    for(int i=0;i<26;i++) idx[i]=i;
    sort(idx.begin(),idx.end(),[&](int a,int b){return count[a]>count[b];});

    cout<<"\nFrequency-based substitution candidates:\n";
    for(int n=0;n<top;n++) {
        int map[26];
        for(int i=0;i<26;i++) map[i]=i;
        int limit=min(26,n+1);
        for(int i=0;i<limit;i++) map[idx[i]]=order[i]-'A';

        cout<<n+1<<". ";
        for(char ch:c) {
            if(ch>='A'&&ch<='Z') cout<<char('A'+map[ch-'A']);
            else cout<<ch;
        }
        cout<<"\n";
    }
    return 0;
}
