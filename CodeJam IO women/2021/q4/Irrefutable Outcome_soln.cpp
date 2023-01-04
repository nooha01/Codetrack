#include <bits/stdc++.h>
#define int long long
#define ld long double
#define vc vector
#define s second
#define f first
#define p(v) cout << #v << ": " << v << endl;
#define print(v) cout << #v << ": "; for (auto x : v )cout << x << " "; cout << endl;

using namespace std;

typedef pair <int, int> pii;

int xmax(int & a, int b){
    return a = max(a, b);
}
int xmin(int & a, int b){
    return a = min(a, b);
}

void do_test(){
   string s;
   cin >> s;

   int n = s.size();
    char winn = 'X';
    int anzz = 0;
    vc <int> a (4);
  for (int k=0; k<4; k++){
    char win = 'X';
    int i = 0;
       int j = n-1;

    int t = 1;

    int anz = 0;
   while(true){
        t++;
        if (t%2 == 0){
            if (i > j){
                win = 'O';
                anz = 1;
                break;
            }
            if (s[i]!='I' && s[j]!='I'){
                win = 'O';
                anz = j - i + 2;
                break;
            }
            if (s[i] == 'O'){
                j--;
                continue;
            }
            if (s[j] == 'O'){
                i++;
                continue;
            }
            if (i == j){
                win = 'I';
                anz = 1;
                break;
            }
            if (s[i+1] == 'I'){
                i++;
                continue;
            }
            if (s[j-1] == 'I'){
                j--;
                continue;
            }
            if (s[i+2]=='O'){
                j--;
                continue;
            }
            if (s[j-2] == 'O'){
                i++;
                continue;
            }
            if (k%2 == 0){
                i++;
            }else{
                j--;
            }

        }else{
            if (i > j){
                win = 'I';
                anz = 1;
                break;
            }
            if (s[i]!='O' && s[j]!='O'){
                win = 'I';
                anz = j - i+ 2;
                break;
            }
            if (s[i] == 'I'){
                j--;
                continue;
            }
            if (s[j] == 'I'){
                i++;
                continue;
            }
            if (i == j){
                win = 'O';
                anz = 1;
                break;
            }
            if (s[i+1] == 'O'){
                i++;
                continue;
            }
            if (s[j-1] == 'O'){
                j--;
                continue;
            }
            if (s[i+2]=='I'){
                j--;
                continue;
            }
            if (s[j-2] == 'I'){
                i++;
                continue;
            }
            if (k/2 == 0){
                i++;
            }else{
                j--;
            }

        }

   }
   a[k] = anz;
   if (k == 0){
        winn = win;
        anzz = anz;
    }else{
        assert(winn == win);
    }

   }
   if (winn == 'I'){
    anzz = max(min(a[1], a[3]), min(a[0], a[2]));
   }else{
    anzz = max(min(a[0], a[1]), min( a[2], a[3]));
   }
   cout << winn << " " << anzz << "\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for (int i=1; i<=T; i++){
        cout <<"Case #" << i << ": ";
        do_test();
    }
}


