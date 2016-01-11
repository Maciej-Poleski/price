#define _GLIBCXX_CONCEPT_CHECKS

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cassert>
#include <unordered_map>
#include <map>
#include <set>
#include <unistd.h>
#include <fcntl.h>
#include <functional>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int current = 1; current <= t; ++current) {
        int n, p;
        cin >> n >> p;
        vector<int> input(n);
        for (auto &p : input) {
            cin >> p;
        }
        int a = 0, b = 1;
        long sum = 0;
        long result = 0;
        for (; b <= n; ++b) {
            sum += input[b - 1];
            while (sum > p) {
                sum -= input[a];
                a += 1;
            }
            assert(sum >= 0);
            assert(a <= b);
            result += b - a;
        }

        cout << "Case #" << current << ": " << result << '\n';
    }
}