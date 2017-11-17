file(GLOB qtest_SRC "src/*.h" "src/*.c")

add_library(qtest ${qtest_SRC})

# Define headers for the library
target_include_directories(
    qtest PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src
)

# set install locations
install(
    TARGETS qtest 
    EXPORT MyLibraryConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Tests
add_executable(test_qtest test/test.c)
target_link_libraries(test_qtest qtest)
add_test(test_qtest test_qtest)
