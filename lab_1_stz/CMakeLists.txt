cmake_minimum_required(VERSION 3.5)

project(laba_1_stz LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED core imgproc highgui)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(laba_1_stz laba_1_stz.cpp)

include(GNUInstallDirs)
install(TARGETS laba_1_stz
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

target_link_libraries(laba_1_stz ${OpenCV_LIBS})
