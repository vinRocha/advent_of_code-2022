add_executable(2022-day1-01 01/c01/adv_2022_01_01.cpp)
target_link_libraries(2022-day1-01 PUBLIC file_state)
target_include_directories(2022-day1-01 PUBLIC
                          "${PROJECT_SOURCE_DIR}/lib/include")
add_executable(2022-day1-02 01/c02/adv_2022_01_02.cpp)
target_link_libraries(2022-day1-02 PUBLIC file_state)
target_include_directories(2022-day1-02 PUBLIC
                          "${PROJECT_SOURCE_DIR}/lib/include")

add_executable(2022-day2-01 02/c01/adv_2022_02_01.cpp)
target_link_libraries(2022-day2-01 PUBLIC file_state)
target_include_directories(2022-day2-01 PUBLIC
                          "${PROJECT_SOURCE_DIR}/lib/include")
add_executable(2022-day2-02 02/c02/adv_2022_02_02.cpp)
target_link_libraries(2022-day2-02 PUBLIC file_state)
target_include_directories(2022-day2-02 PUBLIC
                          "${PROJECT_SOURCE_DIR}/lib/include")

add_executable(2022-day3-01 03/c01/adv_2022_03_01.cpp)
add_executable(2022-day3-02 03/c02/adv_2022_03_02.cpp)

add_executable(2022-day4-01 04/c01/adv_2022_04_01.cpp)
add_executable(2022-day4-02 04/c02/adv_2022_04_02.cpp)

add_executable(2022-day5-01 05/c01/adv_2022_05_01.cpp)
add_executable(2022-day5-02 05/c02/adv_2022_05_02.cpp)

add_executable(2022-day6-01 06/c01/adv_2022_06_01.cpp)
add_executable(2022-day6-02 06/c02/adv_2022_06_02.cpp)

add_executable(2022-day7-01 07/c01/adv_2022_07_01.cpp)
target_link_libraries(2022-day7-01 PUBLIC file_list)
target_include_directories(2022-day7-01 PUBLIC
                          "${PROJECT_SOURCE_DIR}/lib/include")
                          
add_executable(2022-day7-02 07/c02/adv_2022_07_02.cpp)
target_link_libraries(2022-day7-02 PUBLIC file_list)
target_include_directories(2022-day7-02 PUBLIC
                          "${PROJECT_SOURCE_DIR}/lib/include")

add_executable(2022-day8-01 08/c01/adv_2022_08_01.cpp)

