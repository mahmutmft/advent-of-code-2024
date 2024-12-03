#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
    int totalSum = 0;
    string input;

    while (true) {
        getline(cin, input);

        if (input == ".") {
            break;
        }

        regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
        smatch match;

        string::const_iterator searchStart(input.cbegin());
        while (regex_search(searchStart, input.cend(), match, pattern)) {
            int x = stoi(match[1]); 
            int y = stoi(match[2]);
            totalSum += x * y;

            searchStart = match.suffix().first;
        }
    }

    cout << totalSum << endl;

    return 0;
}
