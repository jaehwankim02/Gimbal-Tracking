// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef ROHANG25_TEST__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define ROHANG25_TEST__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_rohang25_test __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_rohang25_test __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_rohang25_test __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_rohang25_test __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_rohang25_test
    #define ROSIDL_GENERATOR_CPP_PUBLIC_rohang25_test ROSIDL_GENERATOR_CPP_EXPORT_rohang25_test
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_rohang25_test ROSIDL_GENERATOR_CPP_IMPORT_rohang25_test
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_rohang25_test __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_rohang25_test
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_rohang25_test __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_rohang25_test
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // ROHANG25_TEST__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
