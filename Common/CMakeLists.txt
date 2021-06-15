project(counter-strike) 

FILE(GLOB myFiles "*.cpp")
message (STATUS "Cargué ${myFiles}")

add_library(common_classes
  ${myFiles}
)
