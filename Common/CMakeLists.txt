project(counter-strike) 

FILE(GLOB_RECURSE myFiles *.cpp *.h)
message (STATUS "Cargué ${myFiles}")

add_library(common_classes
  ${myFiles}
)
