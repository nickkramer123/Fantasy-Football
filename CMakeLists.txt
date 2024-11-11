cmake_minimum_required(VERSION 3.8)
project(FantasyDraft)

set(CMAKE_CXX_STANDARD 17)

add_executable(FantasyDraft
        main.cpp
        draft.cpp
        players.h
        draft.h
        players.cpp
        quarterback.cpp
        quarterback.h
        runningback.cpp
        runningback.h
        widereciever.cpp
        widereciever.h)

add_executable(Testing
        testing.cpp
        draft.cpp
        players.h
        draft.h
        players.cpp
        quarterback.cpp
        quarterback.h
        runningback.cpp
        runningback.h
        widereciever.cpp
        widereciever.h)