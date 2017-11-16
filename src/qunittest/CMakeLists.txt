add_library(
    qunittest
    src/example.c
)

# Define headers for the library
target_include_directories(
    qunittest PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    PRIVATE src
)

# set install locations
install(TARGETS qunittest EXPORT MyLibraryConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Tests
add_executable(
    testqunittest
    test/test.c
)

target_link_libraries(
    testqunittest
    qunittest
)

add_test(testqunittest testqunittest)
