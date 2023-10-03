//
// Created by Olcay Taner Yıldız on 18.01.2019.
//

#include <sstream>
#include "NamedEntityWord.h"
#include "NamedEntitySentence.h"
#include "NamedEntityType.h"

/**
 * Empty constructor for NamedEntitySentence
 */
NamedEntitySentence::NamedEntitySentence() {
}

/**
 * Another constructor of NamedEntitySentence. It takes input a named entity annotated sentence in string
 * form, divides the sentence with respect to space and sets the tagged words with respect to their tags.
 * @param sentence Named Entity annotated sentence in string form
 */
NamedEntitySentence::NamedEntitySentence(const string& sentence) {
    string entityType, candidate;
    NamedEntityType type = NamedEntityType::NONE;
    vector<string> wordArray = Word::split(sentence);
    for (const string& word : wordArray){
        if (!word.empty()){
            if (word != "<b_enamex"){
                if (Word::startsWith(word, "TYPE=\"")){
                    int typeIndexEnd = word.find_first_of('\"', 6);
                    if (typeIndexEnd != -1){
                        entityType = word.substr(6, typeIndexEnd - 6);
                        type = getNamedEntityType(entityType);
                    }
                    if (Word::endsWith(word, "e_enamex>")){
                        candidate = word.substr(word.find_first_of('>') + 1, word.find_first_of('<') - word.find_first_of('>') - 1);
                        if (!candidate.empty()){
                            words.emplace_back(new NamedEntityWord(candidate, type));
                        }
                        type = NamedEntityType::NONE;
                    } else {
                        candidate = word.substr(word.find_first_of('>') + 1);
                        if (!candidate.empty()){
                            words.emplace_back(new NamedEntityWord(candidate, type));
                        }
                    }
                } else {
                    if (Word::endsWith(word, "e_enamex>")){
                        candidate = word.substr(0, word.find_first_of('<'));
                        if (!candidate.empty()){
                            words.emplace_back(new NamedEntityWord(candidate, type));
                        }
                        type = NamedEntityType::NONE;
                    } else {
                        if (!word.empty()){
                            words.emplace_back(new NamedEntityWord(word, type));
                        }
                    }
                }
            }
        }
    }
}
