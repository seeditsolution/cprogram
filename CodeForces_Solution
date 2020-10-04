#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'
#define mod 1000000007
int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
bool compare(int a, int b) {
    return a > b;
}
int32_t main() {
    fio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v;
        v.push_back(0);
        for (int i = 3; i <= n; i += 2) {
            v.push_back(2 * i + (i - 2) * 2);
        }
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            cnt += v[i] * i;
        }
        cout << cnt << endl;
    }
}
