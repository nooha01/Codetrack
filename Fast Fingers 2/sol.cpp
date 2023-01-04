#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m,f,b,max,min;
    char d,s;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>d>>f>>s>>b;
        if(s=='+'){
            max=m*f+b;
            min=m+b;
        }
        else{
            max=m*f-b;
            min=m-b;
        }
        cout<<min<<" "<<max<<"\n";
        
        
    }
    return 0;
}
