# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

# [1.3.1-snapshot]

## [1.3.0]
### Added
- New `qtest_doubles_within_range` function to check if doubles are within a specified range
  of each other rather than within a specified percentage which can be an issue if the input
  range is not known.
  
## [1.2.0]
### Added
- New `create_qunittest` and `add_existing_qunittest` function to public API to allow unit test
  objects to be created separately from the test suite environment, allowing for more effective
  refactoring of test code in projects.
- Added function to create test case checking if double values are approximately equal, for a 
  given tolerance.

## [1.1.0]
### Added
- `print_qtestsuite` function wraps `fprint_qtestsuite` with `stdout` as the output stream
   to avoid the need to include `<stdio.h>` in a test program if not streaming to other `FILE`
   destinations.

### Fixed
- `getchar` call removed from end of qtest test program to allow it to be run by ctest/without
  interaction.

## [1.0.2]
### Fixed
- Redefined use of `strdup` command to `_strdup` when macro `_MSC_VER` is defined (ie. when
  build on Windows).

## [1.0.1] - 2017-11-19
### Added
- Readme has now been added with basic information on how to build the library.

### Changed
- Implementation of testcase and unittest label now duplicates label passed to it on creation
  so that the original string can go out of scope without affecting the tests. This is useful
  for creation of testcases or units in loops.
