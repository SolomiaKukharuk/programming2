
//13_23
#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
using namespace std;


bool isArticle(const string &word) {
    return word == "a" || word == "an" || word == "the";
}

string processSentence(const string &sentence) {
    stringstream input(sentence);
    stringstream output;
    string previousWord, currentWord;
    input >> previousWord;
    output << previousWord;

    while (input >> currentWord) {
        output << ' ';
        if (isArticle(previousWord) && !currentWord.empty()) {
            currentWord[0] = tolower(currentWord[0]);
        }
        output << currentWord;
        previousWord = currentWord;
    }

    return output.str();
}

void task_17() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);
    string result = processSentence(sentence);
    cout << "Modified sentence: " << result << endl;
}


string replacePossessivePhrase(const string &input) {
    string output = input;
    regex pattern(R"(\b(\w+)'s (\w+)\b)");
    output = regex_replace(output, pattern, "$2 of $1");
    return output;
}

void task_23() {
    string inputLine;
    cout << "Enter a string: ";
    getline(cin, inputLine);
    string result = replacePossessivePhrase(inputLine);
    cout << "Modified string: " << result << endl;

}