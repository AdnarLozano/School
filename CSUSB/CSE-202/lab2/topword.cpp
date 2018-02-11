#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
vector<string> common_words = {
    "the"s, "be"s, "to"s, "of"s, "and"s, "a"s,
	"in"s, "that"s, "have"s, "I"s, "it"s, "for"s,
	"not"s, "on"s, "with"s, "he"s, "as"s, "you"s,
	"do"s, "at"s, "this"s, "but"s, "his"s, "by"s,
	"from"s, "they"s, "we"s, "say"s, "her"s, "she"s,
	"or"s, "an"s, "will"s, "my"s, "one"s, "all"s,
	"would"s, "there"s, "their"s, "what"s, "so"s,
	"up"s, "out"s, "if"s, "about"s, "who"s, "get"s,
	"which"s, "go"s, "me"s, "when"s, "make"s, "can"s,
	"like"s, "time"s, "no"s, "just"s, "him"s, "know"s,
	"take"s, "people"s, "into"s, "year"s, "your"s,
	"good"s, "some"s, "could"s, "them"s, "see"s,
	"other"s, "than"s, "then"s, "now"s, "look"s,
	"only"s, "come"s, "its"s, "over"s, "think"s,
	"also"s, "back"s, "after"s, "use"s, "two"s,
	"how"s, "our"s, "work"s, "first"s, "well"s,
	"way"s, "even"s, "new"s, "want"s, "because"s,
	"any"s, "these"s, "give"s, "day"s, "most"s,
	"us"s, "is"s, "are"s };
        
int main () {
    
/*  The contents of data.txt are taken from:
    https://protovision.github.io/202-2017-winter/maps.html */
    
    fstream f;
    string fileName;
    cout << "Enter the filename: ";
    cin>>fileName;
    f.open(fileName);
    string word;
    map<string, int> word_counts;
    pair<string, int> topword;
    while (f >> word) {  
    if ( find (common_words.begin(), common_words.end(), word) 
         == common_words.end()) word_counts[word]++;
    }
    for (pair<string, int> p : word_counts) {
        if (p.second > topword.second) topword = p; }
    cout << "The most common word in you file is: \"" << topword.first << "\"\n";
    cout << "The number of ocurrences is: " << topword.second << endl;
    return 0;
}