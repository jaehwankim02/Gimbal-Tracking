# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_rohang25_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED rohang25_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(rohang25_FOUND FALSE)
  elseif(NOT rohang25_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(rohang25_FOUND FALSE)
  endif()
  return()
endif()
set(_rohang25_CONFIG_INCLUDED TRUE)

# output package information
if(NOT rohang25_FIND_QUIETLY)
  message(STATUS "Found rohang25: 0.1.0 (${rohang25_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'rohang25' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${rohang25_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(rohang25_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${rohang25_DIR}/${_extra}")
endforeach()
