project(progetto_chrono)

add_subdirectory(googletest-main)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})


set(SOURCE_FILES runAllTests.cpp
        Chrono_test.cpp
        ../App.cpp
        ../App.h
        ../Frame.cpp
        ../Frame.h
        ../DateTime.cpp
        ../DateTime.h
        ../Timer.cpp
        ../Timer.h
        ../Chrono.cpp
        ../Chrono.h
        ../Timer_Chrono_panel.cpp
        ../Timer_Chrono_panel.h)

add_executable(Google_Tests_run ${SOURCE_FILES})

target_link_libraries(Google_Tests_run gtest gtest_main)
target_link_libraries(Google_Tests_run ${wxWidgets_LIBRARIES})