#include<bits/stdc++.h>
using namespace std;

void wordFrequencyAnalysis(const vector<string>& words, unordered_map<string, unordered_map<string, int>>& nextWordFrequency) {
    for(int idx = 0; idx < words.size() - 1; idx++){
        string thisWord = words[idx];
        string succeedingWord = words[idx + 1];
        for(string word: words)
            if(word == succeedingWord)
                nextWordFrequency[thisWord][succeedingWord]++;
    }

    /*cout << "Frequency Model: " << endl;
    for (const auto& entry : nextWordFrequency) {
        cout << "\"" << entry.first << "\": ";
        for (const auto& nextWord : entry.second)
            cout << nextWord.first << " (" << nextWord.second << "), ";
        cout << endl;
    }*/

}

void ngramModeling(const vector<string>& words, int n_GramSize, unordered_map<string, unordered_map<string, int>>& n_GramFrequency) {
    for (size_t i = 0; i <= words.size() - n_GramSize; i++) {
        string ngram;
        for (int j = 0; j < n_GramSize; j++){
            if (j > 0)
                ngram += " ";
            ngram += words[i + j];
        }
        n_GramFrequency[ngram][words[i + n_GramSize - 1]]++;
    }


    /*cout << "n-Gram model: " << endl;
    for (const auto& entry : n_GramFrequency) {
        cout << "\"" << entry.first << "\": ";
        for (const auto& nextWord : entry.second) 
            cout << nextWord.first << " (" << nextWord.second << "), ";
        cout << endl;
    }*/
}

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
            if(isalnum(text[i]) || text[i] == '\'')
                currentWord += text[i];
            else {
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

void parseGeneratedText(string text){
    string formattedText = "";
    for(int idx = 0; idx < text.length() - 1; idx++){
        if(text[idx] == 32){
            if(text[idx+1] == 44 || text[idx+1] == 46 || text[idx+1] == 63 || text[idx+1] == 33 )
                continue;
        }
        formattedText += text[idx];
    }
    if(text[text.length() - 1] == 32)
        formattedText.pop_back();
    if(text[text.length() - 1] != 46)
        formattedText += ".";
    cout << formattedText << endl;
}

void generateText(vector<string>& wordList, unordered_map<string, unordered_map<string, int>>& n_GramFrequency, unordered_map<string, unordered_map<string, int>>& nextWordFrequency, int n_GramSize, int sampleSize) {
    srand(static_cast<unsigned int>(time(0)));
    string currentWord = wordList[rand() % wordList.size()]; 
    string generatedText = "";

    cout << "Generated Text Sample (~" << sampleSize << " words):" << endl;
    for(int wordCount = 0; wordCount < sampleSize; wordCount += n_GramSize){
        vector<string> matchingNGrams;

        for(const auto& phrase : n_GramFrequency){
            string newWord;
            stringstream ss(phrase.first);
            ss >> newWord;
            if(newWord == currentWord){
                matchingNGrams.push_back(phrase.first);
            }
        }

        if(!matchingNGrams.empty()){
            string selectedNGram = matchingNGrams[rand() % matchingNGrams.size()];
            generatedText += selectedNGram;
            stringstream ss(selectedNGram);
            string lastWord;
            while (ss >> lastWord) 
                currentWord = lastWord;
            generatedText += " ";
        }

        auto nextWords = nextWordFrequency[currentWord];

        int totalFrequency = 0;
        for (const auto& pair : nextWords) 
            totalFrequency += pair.second;

        int randomValue = rand() % totalFrequency;
        for (const auto& pair : nextWords){
            randomValue -= pair.second;
            if (randomValue < 0){
                currentWord = pair.first;
                break;
            }
        }
    }
    parseGeneratedText(generatedText);

}

int main() {
    string fileName = "input.txt";
    vector<string> wordList;
    unordered_map<string, unordered_map<string, int>> nextWordFrequency;
    unordered_map<string, unordered_map<string, int>> n_GramFrequency;
    int n_GramSize = 4; // Polygram
    int sampleSize;
    cout << "Enter desired length of generated sentence: ";
    cin >> sampleSize;
    cout << endl;

    parseWords(wordList, fileName);
    wordFrequencyAnalysis(wordList, nextWordFrequency);
    ngramModeling(wordList, n_GramSize, n_GramFrequency);
    generateText(wordList, n_GramFrequency, nextWordFrequency, n_GramSize, sampleSize);

    return 0;
}
