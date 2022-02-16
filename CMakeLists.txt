cmake_minimum_required(VERSION 3.19)
project(Pong_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories("Pong Game")

add_executable(Pong_Game
        "Pong Game/FinishedMessage.cpp"
        "Pong Game/FinishedMessage.h"
        "Pong Game/GameGuide.cpp"
        "Pong Game/GameGuide.h"
        "Pong Game/Menu.cpp"
        "Pong Game/Menu.h"
        "Pong Game/Options.cpp"
        "Pong Game/Options.h"
        "Pong Game/PauseMenu.cpp"
        "Pong Game/PauseMenu.h"
        "Pong Game/Source.cpp"
        "Pong Game/TextBox.cpp"
        "Pong Game/TextBox.h"
        "Pong Game/txtbox.cpp"
        "Pong Game/txtbox.h")
