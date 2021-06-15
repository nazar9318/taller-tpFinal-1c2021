project(counter-strike) 

FILE(GLOB myFiles "*.cpp")
message (STATUS "Cargué ${myFiles}")

add_library(server_classes
  ${myFiles}
)
