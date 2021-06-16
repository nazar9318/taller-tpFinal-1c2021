project(counter-strike) 

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()



FILE(GLOB myFiles *.cpp 
				  */*.cpp)


HEADER_DIRECTORIES(header_dir_list)

list(LENGTH header_dir_list header_dir_list_count)
message(STATUS "[INFO] Found ${header_dir_list_count} header directories.")
message(STATUS "[INFO] Found ${header_dir_list} header directories.")


include_directories(header_dir_list)



message (STATUS "Cargué ${myFiles}")

add_library(client_classes
  ${myFiles}
  ${header_dir_list}
)

target_include_directories(
    client_classes
    PUBLIC
    ${header_dir_list} # Recursive
)
