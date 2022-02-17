#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

long T, n, sum;

void input() {
    cin >> T;
    for (long i = 0; i < T; i++) {
        cin >> n;
        sum = 0;
        // for(long j = 1; j < n; j++) {
        //     if(j % 3 == 0 || j % 5 == 0) sum += j;
        // }

        long curr3 = 3, curr5 = 5;
        long k = 1;
        // sum = 8;    // = 3+5
        while (true) {
            curr3 *= k;
            curr5 *= k;
            if (curr3 < n) sum += curr3;
            if (curr5 < n) sum += curr5;
            if (curr3 >= n && curr5 >= n) break;
            // sum = sum + curr3 + curr5;
            k++;
        }
        cout << sum << endl;
    }
}

int main() {
    cout << "Hello world" << endl;
    input();
    return 0;
}
