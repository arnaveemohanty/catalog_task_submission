#include <bits/stdc++.h>
using namespace std;

// Convert string value in given base to decimal
long long convertToDecimal(const string &value, int base) {
    long long result = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else digit = 10 + (tolower(c) - 'a');
        result = result * base + digit;
    }
    return result;
}

// Lagrange interpolation at x=0
long long lagrangeAtZero(const vector<pair<long long,long long>> &points) {
    int n = points.size();
    long double result = 0.0;

    for (int i = 0; i < n; i++) {
        long double term = (long double) points[i].second;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            long double xi = (long double) points[i].first;
            long double xj = (long double) points[j].first;
            term *= (0.0 - xj) / (xi - xj);
        }
        result += term;
    }

    return (long long) llround(result); // round safely to nearest integer
}

int main() {
    // ------------------ TEST CASE 1 ------------------
    {
        cout << "Test Case 1:\n";
        int k = 3;
        vector<pair<int,string>> raw = {
            {1,"4"}, {2,"111"}, {3,"12"}, {6,"213"}
        };
        vector<int> bases = {10,2,10,4};

        vector<pair<long long,long long>> points;
        for (int i=0; i<k; i++) {
            long long y = convertToDecimal(raw[i].second, bases[i]);
            points.push_back({raw[i].first, y});
        }

        cout << "Secret (P(0)) = " << lagrangeAtZero(points) << "\n\n";
    }

    // ------------------ TEST CASE 2 ------------------
    {
        cout << "Test Case 2:\n";
        int k = 7;
        vector<pair<int,string>> raw = {
            {1,"13444211440455345511"},
            {2,"aed7015a346d635"},
            {3,"6aeeb69631c227c"},
            {4,"e1b5e05623d881f"},
            {5,"316034514573652620673"},
            {6,"2122212201122002221120200210011020220200"},
            {7,"20120221122211000100210021102001201112121"}
        };
        vector<int> bases = {6,15,15,16,8,3,3};

        vector<pair<long long,long long>> points;
        for (int i=0; i<k; i++) {
            long long y = convertToDecimal(raw[i].second, bases[i]);
            points.push_back({raw[i].first, y});
        }

        cout << "Secret (P(0)) = " << lagrangeAtZero(points) << "\n";
    }

    return 0;
}
