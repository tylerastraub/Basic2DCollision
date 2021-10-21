cmake_minimum_required(VERSION 3.0.0)
project(SecretProject VERSION 0.1.0)

set(SDL2_INCLUDE_DIR "C:/Program Files/mingw-w64/mingw64/include/SDL2")
set(SDL2_LIBRARY_DIR "C:/Program Files/mingw-w64/mingw64/lib")
set(SDL2_IMAGE_INCLUDE_DIR "C:/SDL_Image/include/SDL2")
set(SDL2_IMAGE_LIBRARY_DIR "C:/SDL_Image/lib")

set(SOURCE_INCLUDES
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/States
    ${PROJECT_SOURCE_DIR}/src/ResourceHandler
    ${PROJECT_SOURCE_DIR}/src/Entities
    ${PROJECT_SOURCE_DIR}/src/Level
    )
set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/game.cpp
    ${PROJECT_SOURCE_DIR}/src/States/State.cpp
    ${PROJECT_SOURCE_DIR}/src/States/DummyState.cpp
    ${PROJECT_SOURCE_DIR}/src/ResourceHandler/ResourceHandler.h
    ${PROJECT_SOURCE_DIR}/src/Entities/Player.cpp
    ${PROJECT_SOURCE_DIR}/src/Entities/Entity.cpp
    ${PROJECT_SOURCE_DIR}/src/Level/Level.cpp
    ${PROJECT_SOURCE_DIR}/src/CollisionDetector.cpp
    )

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SOURCE_INCLUDES})

add_executable(SecretProject ${SOURCES})
# remove -mconsole for release builds
target_link_libraries(SecretProject -lmingw32 ${SDL2_LIBRARY_DIR}/libSDL2main.a ${SDL2_LIBRARY_DIR}/libSDL2.dll.a ${SDL2_IMAGE_LIBRARY_DIR}/libSDL2_image.dll.a -mwindows -mconsole)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
