add_library(libsysinfo
        src/sysinfo.cpp
        src/sysinfo.h
)

target_include_directories(libsysinfo PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")