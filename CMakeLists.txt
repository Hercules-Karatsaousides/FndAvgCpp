cmake_minimum_required(VERSION 4.0)
project(FndAvgCpp)

set(CMAKE_CXX_STANDARD 20)

# Include Windows resource file to embed the icon into the executable
add_executable(FndAvgCpp main.cpp app.rc)
# Ensure the output executable name is exactly FndAvgCpp.exe on Windows
set_target_properties(FndAvgCpp PROPERTIES OUTPUT_NAME "FndAvgCpp")
