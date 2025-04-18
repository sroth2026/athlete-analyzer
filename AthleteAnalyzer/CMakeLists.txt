cmake_minimum_required(VERSION 3.16)

project(AthleteAnalyzer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt 6 Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets LinguistTools)

# Translation files (you can remove these lines if unused)
set(TS_FILES AthleteAnalyzer_en_AS.ts)

# All your sources, headers, and .ui files go here
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    core/golf_analyzer.cpp
    core/golf_analyzer.hpp
    core/csv_parser.hpp
    ${TS_FILES}
)

# Create the Qt executable
qt_add_executable(AthleteAnalyzer
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

# Link Qt libraries
target_link_libraries(AthleteAnalyzer PRIVATE Qt6::Widgets)

# Include core directory for headers
target_include_directories(AthleteAnalyzer PRIVATE core)

# macOS bundle properties
set_target_properties(AthleteAnalyzer PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_BUNDLE_NAME "AthleteAnalyzer"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.AthleteAnalyzer"
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    WIN32_EXECUTABLE TRUE
)

# Optional translation support (can be removed if not used)
qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
qt_finalize_executable(AthleteAnalyzer)

# Install target (for packaging)
install(TARGETS AthleteAnalyzer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
