cmake_minimum_required(VERSION 3.16)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Fetch SQLiteCpp
# FetchContent_Declare(
#     SQLiteCpp
#     GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp.git
#     GIT_TAG 3.3.1
#     GIT_CONFIG "core.autocrlf=false")
# FetchContent_GetProperties(SQLiteCpp)
# 
# if(NOT SQLiteCpp_POPULATED)
#     FetchContent_Populate(SQLiteCpp)
#     add_subdirectory(${sqlitecpp_SOURCE_DIR} ${sqlitecpp_BINARY_DIR})
# endif()

file(GLOB SRCS CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/framework/*.cpp
    ${CMAKE_SOURCE_DIR}/src/gui/*.cpp
    ${CMAKE_SOURCE_DIR}/src/layer/*.cpp
    ${CMAKE_SOURCE_DIR}/src/utils/*.cpp
    ${CMAKE_SOURCE_DIR}/src/activity/*.cpp
)

add_executable(game ${SRCS})
# target_link_libraries(game PRIVATE sfml-graphics sfml-window sfml-system sfml-audio SQLiteCpp sqlite3)
target_link_libraries(game PRIVATE sfml-network sfml-graphics sfml-window sfml-system sfml-audio)
if (UNIX)
    target_link_libraries(game PRIVATE pthread dl)
endif()

target_compile_features(game PRIVATE cxx_std_17)

target_include_directories(game PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/framework
    ${CMAKE_SOURCE_DIR}/include/framework/profile
    ${CMAKE_SOURCE_DIR}/include/gui
    ${CMAKE_SOURCE_DIR}/include/layer
    ${CMAKE_SOURCE_DIR}/include/utils
    ${CMAKE_SOURCE_DIR}/include/activity
)

if(WIN32)
    add_custom_command(
        TARGET game
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:game>
        VERBATIM)
endif()

install(TARGETS game)

# cmake -S. -Bbuild -G "MinGW Makefiles"
# cmake --build build
# cmake --build build --verbose
