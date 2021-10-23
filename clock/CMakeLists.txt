add_library(libclock
        src/clock.cpp
        src/clock.h
        )

target_include_directories(libclock PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")