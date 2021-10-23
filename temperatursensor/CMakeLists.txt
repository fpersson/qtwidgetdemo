add_library(libsensor
        src/temperaturesensor.cpp
        src/temperaturesensor.h
        )

target_include_directories(libsensor PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")