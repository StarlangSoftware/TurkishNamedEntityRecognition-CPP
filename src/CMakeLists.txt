cmake_minimum_required(VERSION 3.12)
project(NamedEntityRecognition)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-O3")

find_package(corpus REQUIRED)

add_library(NamedEntityRecognition Gazetteer.cpp Gazetteer.h NamedEntityType.h AutoNER.h NamedEntityWord.cpp NamedEntityWord.h NamedEntitySentence.cpp NamedEntitySentence.h NERCorpus.cpp NERCorpus.h SlotType.h Slot.cpp Slot.h)
target_link_libraries(NamedEntityRecognition corpus::corpus)
