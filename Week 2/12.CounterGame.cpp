#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'counterGame' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts LONG_INTEGER n as parameter.
 */
 

string counterGame(long n) {
    bool louiseTurn = false;
    long bitMask = numeric_limits<long>::max();
    bitMask = bitMask & ~(bitMask >> 1);
    
    while (n != 1) {
        while ((n & bitMask) == 0) {
            bitMask >>= 1; // right shifts bitMask to reach n
        }
        louiseTurn = !louiseTurn;
        if ((bitMask | n) == bitMask) { // power of 2
            n >>= 1; // n/2
        } else {
            n &= ~bitMask; // n - biggest power of 2
        }
    }
    return louiseTurn ? "Louise" : "Richard";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        string result = counterGame(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
