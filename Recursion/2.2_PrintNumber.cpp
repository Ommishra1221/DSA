#include <bits/stdc++.h>
using namespace std;

void printNtoOne(int n){
    if(n == 1){
        cout << 1 << " ";
        return;
    }
    printNtoOne(n-1);
    cout << n << " ";
}
void printOnetoN(int n){
    if(n==1){
        cout<<1<<" ";
        return;
    }
    cout<<n<<" ";
    printOnetoN(n-1);
}
int main() {
    int n;
    cout<<"Enter a number :";
    cin>>n;
    printNtoOne(n);
    cout<<"\n";
    printOnetoN(n);
    return 0;
}