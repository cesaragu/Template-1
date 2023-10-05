#  cmake .. -G"Unix Makefiles"

# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.26)

# Set the project's name and version
project(CTemplate VERSION 1.0.0 LANGUAGES C CXX)

# Set the required C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the required CPP standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(ENABLE_TESTING "Enable a Unit Testing build." ON)

# Create target variables
set(APP_LIBRARY_NAME "app_lib")
set(DRIVERS_LIBRARY_NAME "drivers_lib")
set(MOCKS_LIBRARY_NAME "mocks_lib")
set(EXECUTABLE_NAME "main")
set(EXECUTABLE_TEST_NAME "run_tests")

# Subdirectories
set(APP_DIR "app/src")
set(DRIVER_DIR "drivers/src")
set(MOCK_DIR "mocks/src")
set(TEST_DIR "tests")
set(INTERFACES_DIR "interfaces")
set(UTIL_DIR "util")

# Source files
set(APP_SOURCES 
    ${APP_DIR}/LedController.c
)
set(DRIVERS_SOURCES 
    ${DRIVER_DIR}/LedDriver.c
    ${DRIVER_DIR}/TLC5973.c
)
set(MOCK_SOURCES 
    ${MOCK_DIR}/LedMockDevice.c
)

# App library
add_library(${APP_LIBRARY_NAME} STATIC ${APP_SOURCES})
target_include_directories(${APP_LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/app/inc)

# Driver library
add_library(${DRIVERS_LIBRARY_NAME} STATIC ${DRIVERS_SOURCES})
target_include_directories(${DRIVERS_LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/drivers/inc)
target_include_directories(${DRIVERS_LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/${INTERFACES_DIR})
target_include_directories(${DRIVERS_LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/${UTIL_DIR})

# Unit Testing
if(ENABLE_TESTING)
    enable_testing()

    # External libraries
    include(FetchContent)
    FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
        GIT_SHALLOW TRUE)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(gtest)

    # Subdirectories
    set(APP_TEST_DIR "tests/app")
    set(DRIVERS_TEST_DIR "tests/drivers")
    
    # Source files
    set(TEST_SOURCES 
        ${TEST_DIR}/AllTests.cpp
    )

    set(APP_TEST_SOURCES 
        ${APP_TEST_DIR}/LedController_Test.cpp
    )

    set(DRIVERS_TEST_SOURCES 
        ${DRIVERS_TEST_DIR}/LedDriver_Test.cpp
    )

    add_executable(${EXECUTABLE_TEST_NAME} 
        ${TEST_SOURCES} 
        ${APP_TEST_SOURCES} 
        ${DRIVERS_TEST_SOURCES}
    ) 

    # Mock library
    add_library(${MOCKS_LIBRARY_NAME} STATIC ${MOCK_SOURCES})
    target_include_directories(${MOCKS_LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/mocks/inc)

    # Test Application
    target_link_libraries(${EXECUTABLE_TEST_NAME} PUBLIC ${APP_LIBRARY_NAME})
    target_link_libraries(${EXECUTABLE_TEST_NAME} PUBLIC ${DRIVERS_LIBRARY_NAME})
    target_link_libraries(${EXECUTABLE_TEST_NAME} PUBLIC ${MOCKS_LIBRARY_NAME})
    target_link_libraries(${EXECUTABLE_TEST_NAME} PUBLIC gtest gtest_main)

else()
    # Main Application
    add_executable(${EXECUTABLE_NAME} ${APP_DIR}/main.c)
    target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${APP_LIBRARY_NAME})
    target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${DRIVERS_LIBRARY_NAME})

endif()