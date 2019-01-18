cmake_minimum_required(VERSION 3.12)
project(NamedEntityRecognition)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
link_directories(library)

add_library(NamedEntityRecognition Gazetteer.cpp Gazetteer.h NamedEntityType.h AutoNER.h NamedEntityWord.cpp NamedEntityWord.h NamedEntitySentence.cpp NamedEntitySentence.h NERCorpus.cpp NERCorpus.h)
target_link_libraries(NamedEntityRecognition Corpus Dictionary)
add_executable(TestGazetteer Gazetteer.cpp Gazetteer.h NamedEntityType.h AutoNER.h TestGazetteer.cpp NamedEntityWord.cpp NamedEntityWord.h NamedEntitySentence.cpp NamedEntitySentence.h NERCorpus.cpp NERCorpus.h)
target_link_libraries(TestGazetteer Corpus Dictionary)
