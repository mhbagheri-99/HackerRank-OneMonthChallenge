#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {
    vector<int> alphabetFrequency(26, 0);
    bool isPangram = true;
    for (char c : s){
        int index = bitset<8>(tolower(c)).to_ulong() - 97;
        alphabetFrequency[index]++;
    }
    for (int i : alphabetFrequency){
        if (i == 0){
            isPangram = false;
            break;
        }
    }
    if (isPangram) {
        return "pangram";
    } else {
        return "not pangram";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
