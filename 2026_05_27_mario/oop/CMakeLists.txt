cmake_minimum_required(VERSION 3.10)
project(MarioGame)

set(CMAKE_CXX_STANDARD 11)

add_executable(mario_game 
    game_object.cpp
    game.cpp
    main.cpp
)