# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

## [1.0.0-snapshot] - 2017-11-19
### Changed
- Implementation of testcase and unittest label now duplicates label passed to it on creation
  so that the original string can go out of scope without affecting the tests. This is useful
  for creation of testcases or units in loops.
