#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string convertedTime = "";

    // splits the string to hours, minutes and seconds + midday identifier (AM/PM)
    string del = ":";
    vector<string> substrings;
    int start, end = -1*del.size();
    do {
        start = end + del.size();
        end = s.find(del, start);
        cout << s.substr(start, end - start) << endl;
        substrings.push_back(s.substr(start, end - start));
    } while (end != -1);
    // divides the seconds and AM/PM from each other
    string seconds, midday;
    seconds = substrings[2].substr(0,2);
    midday = substrings[2].substr(2,4);
    substrings.pop_back();
    substrings.push_back(seconds);

    // converts the time
    if (midday == "AM") {
        if (substrings[0] == "12"){
            convertedTime = "00:" 
                        + substrings[1] + ":" 
                        + substrings[2];
        }
        else {
            convertedTime = substrings[0] + ":" 
                        + substrings[1] + ":" 
                        + substrings[2];
        }
        
    }
    else if (midday == "PM") {
        if (substrings[0] == "12"){
            convertedTime = substrings[0] + ":" 
                        + substrings[1] + ":" 
                        + substrings[2];
        }
        else{
        int hour = stoi(substrings[0]) + 12;
        convertedTime = to_string(hour) + ":" 
                        + substrings[1] + ":" 
                        + substrings[2];
        }
    }
    return convertedTime;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
