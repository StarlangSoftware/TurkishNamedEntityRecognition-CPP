cmake_minimum_required(VERSION 3.12)
project(NamedEntityRecognition)
set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(NamedEntityRecognition src/Gazetteer.cpp src/Gazetteer.h src/NamedEntityType.h src/AutoNER.h src/NamedEntityWord.cpp src/NamedEntityWord.h src/NamedEntitySentence.cpp src/NamedEntitySentence.h src/NERCorpus.cpp src/NERCorpus.h src/SlotType.h src/Slot.cpp src/Slot.h)
target_link_libraries(NamedEntityRecognition ${CONAN_LIBS})
add_executable(Test src/Gazetteer.cpp src/Gazetteer.h src/NamedEntityType.h src/AutoNER.h src/NamedEntityWord.cpp src/NamedEntityWord.h src/NamedEntitySentence.cpp src/NamedEntitySentence.h src/NERCorpus.cpp src/NERCorpus.h Test/GazetteerTest.cpp Test/NERCorpusTest.cpp Test/NamedEntityTypeTest.cpp src/SlotType.h src/Slot.cpp src/Slot.h Test/SlotTest.cpp)
target_link_libraries(Test ${CONAN_LIBS})
