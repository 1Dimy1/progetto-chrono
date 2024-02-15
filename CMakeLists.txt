cmake_minimum_required(VERSION 3.27)
project(progetto_chrono)

set(CMAKE_CXX_STANDARD 14)

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_subdirectory(test)

set(SOURCE_FILES main.cpp
        App.cpp
        App.h
        Frame.cpp
        Frame.h
        DateTime.cpp
        DateTime.h
        Timer.cpp
        Timer.h
        Chrono.cpp
        Chrono.h
        Timer_Chrono_panel.cpp
        Timer_Chrono_panel.h
)
add_executable(FirstC ${SOURCE_FILES})

target_link_libraries(FirstC ${wxWidgets_LIBRARIES})