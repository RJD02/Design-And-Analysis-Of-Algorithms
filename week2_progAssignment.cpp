#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void initialise(int *a, int n) {
    for(int i = 0; i < n; i++) {
        a[i] = 0;
    }
}

void printScore(int *a, int n) {
    for(int i = 0;i < n; i++) {
        cout << 2 * a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n][2];
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    int count[n];
    initialise(count, n);
    for(int i = 0;i < n; i++) {
        int diff = a[i][1] - a[i][0];
        for(int ii = 0; ii < n; ii++) {
            if(diff > a[ii][1] - a[ii][0]) {
                count[i]++;
            }
        }
    }
    printScore(count, n);
    return 0;
}
