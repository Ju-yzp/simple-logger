cmake_minimum_required(VERSION 3.12)
project(simple_logger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set(MUJOCO_FOLDER /usr/local/lib/cmake)
# find_package(mujoco REQUIRED PATHS ${MUJOCO_FOLDER} NO_DEFAULT_PATH)
# find_package (Eigen3 3.3 REQUIRED)

add_executable(${PROJECT_NAME} test/test_logger.cpp src/logger.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
                          include)

# target_link_libraries (${PROJECT_NAME} PUBLIC)

install(TARGETS ${PROJECT_NAME}
        DESTINATION lib)