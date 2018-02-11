#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<string> common_words = {
        "the", "be", "to", "of", "and", "a", "in", "that", "have", "I", "it", "for",
        "not", "on", "with", "he", "as", "you", "do", "at", "this", "but", "his", "by",
        "from", "they", "we", "say", "her", "she", "or", "an", "will", "my", "one", "all",
        "would", "there", "their", "what", "so", "up", "out", "if", "about", "who", "get",
        "which", "go", "me", "when", "make", "can", "like", "time", "no", "just", "him", "know",
        "take", "people", "into", "year", "your", "good", "some", "could", "them", "see",
        "other", "than", "then", "now", "look", "only", "come", "its", "over", "think",
        "also", "back", "after", "use", "two", "how", "our", "work", "first", "well",
        "way", "even", "new", "want", "because", "any", "these", "give", "days", "most",
        "us", "is", "are" };
int main() {
    string word;
    map<string, int> word_counts;
    pair<string, int> topword;
    while (cin >> word) {
        if (find(
            common_words.begin(), 
            common_words.end(), 
            word) == common_words.end() ) {
            word_counts[word]++;
        }
    }
    //topword.first topword.second
    for (pair<string, int> p : word_counts) {
        if (p.second>topword.second) {
            topword = p;
        }
    }
    cout << topword.first << endl;
    return 0;
}