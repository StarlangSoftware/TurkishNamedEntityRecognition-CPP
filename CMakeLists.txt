cmake_minimum_required(VERSION 3.12)
project(NamedEntityRecognition)

set(CMAKE_CXX_STANDARD 20)
include_directories(include)
link_directories(library)

add_library(NamedEntityRecognition Gazetteer.cpp Gazetteer.h NamedEntityType.h AutoNER.h NamedEntityWord.cpp NamedEntityWord.h NamedEntitySentence.cpp NamedEntitySentence.h NERCorpus.cpp NERCorpus.h SlotType.h Slot.cpp Slot.h)
target_link_libraries(NamedEntityRecognition Corpus Dictionary)
add_executable(Test Gazetteer.cpp Gazetteer.h NamedEntityType.h AutoNER.h NamedEntityWord.cpp NamedEntityWord.h NamedEntitySentence.cpp NamedEntitySentence.h NERCorpus.cpp NERCorpus.h Test/GazetteerTest.cpp Test/NERCorpusTest.cpp Test/NamedEntityTypeTest.cpp SlotType.h Slot.cpp Slot.h Test/SlotTest.cpp)
target_link_libraries(Test Corpus Dictionary)
