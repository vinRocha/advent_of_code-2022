add_library(file_list FileList.cpp)
target_include_directories(file_list PUBLIC
                          "${PROJECT_SOURCE_DIR}/lib/include")

add_library(file_state file_state.cpp)
target_include_directories(file_state PUBLIC
                          "${PROJECT_SOURCE_DIR}/lib/include")