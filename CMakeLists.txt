cmake_minimum_required(VERSION 3.16)
project(AthleteAnalyzer)

set(CMAKE_CXX_STANDARD 17)

add_executable(athlete_analyzer
    main.cpp
    core/golf_analyzer.cpp
)

target_include_directories(athlete_analyzer PRIVATE core)

