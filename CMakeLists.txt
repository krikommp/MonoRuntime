cmake_minimum_required(VERSION 3.25)
project(MonoRuntime)

set(CMAKE_CXX_STANDARD 17)

add_executable(MonoRuntime main.cpp)

if (NOT DEFINED MONO_HOME)
    set(MONO_HOME "C:/Program Files/Mono")
endif ()

target_compile_definitions(${PROJECT_NAME} PRIVATE MONO_HOME=\"${MONO_HOME}\")

target_include_directories(${PROJECT_NAME} PRIVATE "${MONO_HOME}/include/mono-2.0")

target_link_libraries(${PROJECT_NAME} PRIVATE "${MONO_HOME}/lib/mono-2.0-sgen.lib")

configure_file("${MONO_HOME}/bin/mono-2.0-sgen.dll" "${PROJECT_BINARY_DIR}/mono-2.0.dll" COPYONLY)

add_custom_command(
        TARGET ${PROJECT_NAME}
        PRE_BUILD
        COMMAND mcs ${CMAKE_SOURCE_DIR}/CSharp/Program.cs -t:library
)

target_compile_definitions(${PROJECT_NAME} PRIVATE MONO_DLL=\"${CMAKE_SOURCE_DIR}/CSharp/Program.dll\")