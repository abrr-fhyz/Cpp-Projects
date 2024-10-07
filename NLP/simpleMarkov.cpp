#include<bits/stdc++.h>
using namespace std;

void parseWords(vector<string>& wordList, string inputFile){
    int n;
    string text;
    ifstream infile(inputFile);
    if(!infile) {
        cout << "Hey man, this kinda doesn't exist" << endl;
        return;
    }

    while (getline(infile, text)) {
        n = text.length();
        string currentWord;

        for (int i = 0; i < n; i++) {
            if(isalnum(text[i]) || text[i] == '\'') {
                currentWord += text[i];
            } else {
                if(!currentWord.empty()) {
                    wordList.push_back(currentWord);
                    currentWord.clear();
                }
                if(text[i] == 63 || text[i] == 33 || text[i] == 46 || text[i] == 44) {
                    wordList.push_back(string(1, text[i]));
                    i++;
                }
            }
        }

        if(!currentWord.empty())
            wordList.push_back(currentWord);
    }
}

void markovModel(int sampleSize, vector<string> wordList){
    int n;
    vector<string> newList;
    srand(static_cast<unsigned>(time(0)));

    n = rand() % wordList.size();
    cout << wordList[n] << " ";

    for (int i = 0; i < sampleSize; i++) {
        int cnt = 0;
        newList.clear();

        for (size_t j = 0; j < wordList.size() - 1; j++) {
            if(wordList[j] == wordList[n]) {
                newList.push_back(wordList[j + 1]);
                cnt++;
            }
        }

        int randChar = rand() % cnt;

        if(newList[randChar][0] == 44 || newList[randChar][0] == 46)
            cout << "\b" << newList[randChar] << " ";  
        else
            cout << newList[randChar] << " ";

        for (size_t j = 0; j < wordList.size(); j++) {
            if(newList[randChar] == wordList[j]) {
                n = j;
                break;
            }
        }
    }

    cout << "\b.\nTHE END" << endl;
}

int main() {
    string fileName = "input.txt";
    vector<string> wordList;

    parseWords(wordList, fileName);

    cout << "\nEnter Length of Sample = ";
    int a;
    cin >> a;
    cout << endl << endl;
    markovModel(a, wordList);

    return 0;
}
