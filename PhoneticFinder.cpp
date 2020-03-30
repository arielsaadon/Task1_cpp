#include "PhoneticFinder.hpp"
#include <iostream>
#include <stdexcept>

namespace phonetic {

    bool equalString(const std::string text,const std::string word){
        if(!text.compare(word))
            return true;
        return false;
    }

    std::string getWordFromText(const std::string text,const int index){
        std::string word;
        int i = 0;

        while(index+i < text.length()){
            if(text.at(index+i) == ' ')
                break;
            word += text.at(index+i);
            i++;
        }
        return word;
    }

    std::string lowCase(std::string word){
        std::string temp;

        for(int i = 0; i < word.length(); i++){
            if((word.at(i) >= 'A') && (word.at(i) <= 'Z')){
                temp += word.at(i)+32;
            }else
                temp += word.at(i);
        }
        return temp;
    }

    bool checkSwapLetters(const std::string textWord,const std::string word){
        if(textWord.length() != word.length())
            return false;

        bool similarWords = false;
        std::string testTextWord = textWord;
        int i = 0;

        while((i < textWord.length()) && (i < word.length())){
            if(((textWord.at(i) == 'v') || (textWord.at(i) == 'w')) && ((word.at(i) == 'v') || (word.at(i) == 'w'))) {
                testTextWord.at(i) = word.at(i);
            }
            if(((textWord.at(i) == 'g') || (textWord.at(i) == 'j')) && ((word.at(i) == 'g') || (word.at(i) == 'j'))) {
                testTextWord.at(i) = word.at(i);
            }
            if(((textWord.at(i) == 's') || (textWord.at(i) == 'z')) && ((word.at(i) == 's') || (word.at(i) == 'z'))) {
                testTextWord.at(i) = word.at(i);
            }
            if(((textWord.at(i) == 'd') || (textWord.at(i) == 't')) && ((word.at(i) == 'd') || (word.at(i) == 't'))) {
                testTextWord.at(i) = word.at(i);
            }
            if(((textWord.at(i) == 'o') || (textWord.at(i) == 'u')) && ((word.at(i) == 'o') || (word.at(i) == 'u'))) {
                testTextWord.at(i) = word.at(i);
            }
            if(((textWord.at(i) == 'i') || (textWord.at(i) == 'y')) && ((word.at(i) == 'i') || (word.at(i) == 'y'))) {
                testTextWord.at(i) = word.at(i);
            }
            if(((textWord.at(i) == 'b') || (textWord.at(i) == 'f') || (textWord.at(i) == 'p')) && ((word.at(i) == 'b') || (word.at(i) == 'f') || (word.at(i) == 'p'))) {
                testTextWord.at(i) = word.at(i);
            }
            if(((textWord.at(i) == 'c') || (textWord.at(i) == 'k') || (textWord.at(i) == 'q')) && ((word.at(i) == 'c') || (word.at(i) == 'k') || (word.at(i) == 'q'))) {
                testTextWord.at(i) = word.at(i);
            }
            i++;
        }
        if(equalString(testTextWord,word))
            return true;
        return similarWords;
    }

    bool spaceCase(std::string word,int index){
        bool haveLetter = false;

        while(index < word.length()){
            if(word.at(index) != ' ')
                return true;
            index++;
        }
        return haveLetter;
    }

    std::string cutWordSpaces(std::string word){
        std::string wordWithoutSpaces;
        int i = 0;

        while(i < word.length()){
            if(word.at(i) == ' ')
                i++;
            else {
                wordWithoutSpaces += word.at(i);
                i++;
                if (i < word.length()) {
                    if (word.at(i) == ' ' && spaceCase(word, i))
                        throw std::out_of_range{"Word cannot contain space"};
                }
            }
        }
        return wordWithoutSpaces;
    }

    std::string find(const std::string text,const std::string word){
        std::string WordFromText;
        std::string lowWordFromText;
        std::string lowWord;
        int lenWordFromText = 0;
        bool notFound = false;

        if(!spaceCase(text,0) && !spaceCase(word,0))
            throw std::out_of_range{"The word cannot be empty"};

        std::string searchWord = cutWordSpaces(word);

        for(int i = 0; i < text.length(); ){
            WordFromText = getWordFromText(text,i);
            lenWordFromText = WordFromText.length();

            lowWordFromText = lowCase(WordFromText);
            lowWord = lowCase(searchWord);

            if(equalString(lowWordFromText,lowWord))
                return WordFromText;

            if(checkSwapLetters(lowWordFromText,lowWord))
                return WordFromText;

            if(equalString(WordFromText,""))
                i++;
            else
                i += lenWordFromText;
        }
        if(!notFound)
            throw std::out_of_range{"The Word not found in text"};

        return word;
    }
}