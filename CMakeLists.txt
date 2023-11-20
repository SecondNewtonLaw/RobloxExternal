cmake_minimum_required(VERSION 3.26)
project(RobloxExternal)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME}
        main.cpp
        Console.cpp
        Console.hpp
        Utilities.cpp
        Utilities.hpp
        LogInterceptor.cpp
        LogInterceptor.hpp
        Roblox.hpp
        Roblox.cpp
        RobloxInstance.cpp
        RobloxInstance.hpp
)

if (!MSVC)
    message(SEND_ERROR "You may not compile this project without the MSVC toolchain!")
endif ()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/oxorany)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/cpr)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Dependencies/)
target_link_libraries(${PROJECT_NAME} PRIVATE
        oxorany # Obfuscation at compile-time
        # cpr   # Not required, Http was never used on this project due to it being left as a prototype.
)
