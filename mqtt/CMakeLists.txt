add_library(libmqtt
        src/mqtt.cpp
        src/mqtt.h
        )

target_include_directories(libmqtt PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")