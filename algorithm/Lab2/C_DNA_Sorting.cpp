#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct DNA {
    string s;
    int inversions;
};

int countInversions(const string& s) {
    int inversions = 0;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (s[i] > s[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

int main() {
    int M;
    cin >> M;
    while (M--) {
        int n, m;
        cin >> n >> m;
        vector<DNA> arr(m);

        for (int i = 0; i < m; ++i) {
            cin >> arr[i].s;
            arr[i].inversions = countInversions(arr[i].s);
        }

        stable_sort(arr.begin(), arr.end(), [](const DNA& a, const DNA& b) {
            return a.inversions < b.inversions;
        });

        for (const auto& dna : arr) {
            cout << dna.s << endl;
        }

        if (M) {
            cout << endl;
        }
    }

    return 0;
}