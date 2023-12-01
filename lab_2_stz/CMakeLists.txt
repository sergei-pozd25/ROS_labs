cmake_minimum_required(VERSION 3.5)

project(laba_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED core imgproc highgui)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(laba_2 laba_2.cpp)

include(GNUInstallDirs)
install(TARGETS laba_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(laba_2 ${OpenCV_LIBS})
