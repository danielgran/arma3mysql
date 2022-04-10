# Generated by Boost 1.78.0

# address-model=64

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
  _BOOST_SKIPPED("libboost_container.dylib" "64 bit, need 32")
  return()
endif()

# layout=tagged

# toolset=xgcc130

# link=shared

if(DEFINED Boost_USE_STATIC_LIBS)
  if(Boost_USE_STATIC_LIBS)
    _BOOST_SKIPPED("libboost_container.dylib" "shared, Boost_USE_STATIC_LIBS=${Boost_USE_STATIC_LIBS}")
    return()
  endif()
else()
  if(WIN32 AND NOT _BOOST_SINGLE_VARIANT)
    _BOOST_SKIPPED("libboost_container.dylib" "shared, default on Windows is static, set Boost_USE_STATIC_LIBS=OFF to override")
    return()
  endif()
endif()

# runtime-link=shared

if(Boost_USE_STATIC_RUNTIME)
  _BOOST_SKIPPED("libboost_container.dylib" "shared runtime, Boost_USE_STATIC_RUNTIME=${Boost_USE_STATIC_RUNTIME}")
  return()
endif()

# runtime-debugging=off

if(Boost_USE_DEBUG_RUNTIME)
  _BOOST_SKIPPED("libboost_container.dylib" "release runtime, Boost_USE_DEBUG_RUNTIME=${Boost_USE_DEBUG_RUNTIME}")
  return()
endif()

# threading=single

if(NOT DEFINED Boost_USE_MULTITHREADED)
  _BOOST_SKIPPED("libboost_container.dylib" "single-threaded, Boost_USE_MULTITHREADED is not set and defaults to ON, set to OFF to override")
  return()
endif()

if(Boost_USE_MULTITHREADED)
  _BOOST_SKIPPED("libboost_container.dylib" "single-threaded, Boost_USE_MULTITHREADED=${Boost_USE_MULTITHREADED}")
  return()
endif()

# variant=release

if(NOT "${Boost_USE_RELEASE_LIBS}" STREQUAL "" AND NOT Boost_USE_RELEASE_LIBS)
  _BOOST_SKIPPED("libboost_container.dylib" "release, Boost_USE_RELEASE_LIBS=${Boost_USE_RELEASE_LIBS}")
  return()
endif()

if(Boost_VERBOSE OR Boost_DEBUG)
  message(STATUS "  [x] libboost_container.dylib")
endif()

# Create imported target Boost::container

if(NOT TARGET Boost::container)
  add_library(Boost::container SHARED IMPORTED)

  set_target_properties(Boost::container PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${_BOOST_INCLUDEDIR}"
    INTERFACE_COMPILE_DEFINITIONS "BOOST_CONTAINER_NO_LIB"
  )
endif()

# Target file name: libboost_container.dylib

get_target_property(__boost_imploc Boost::container IMPORTED_LOCATION_RELEASE)
if(__boost_imploc)
  message(SEND_ERROR "Target Boost::container already has an imported location '${__boost_imploc}', which is being overwritten with '${_BOOST_LIBDIR}/libboost_container.dylib'")
endif()
unset(__boost_imploc)

set_property(TARGET Boost::container APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)

set_target_properties(Boost::container PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE CXX
  IMPORTED_LOCATION_RELEASE "${_BOOST_LIBDIR}/libboost_container.dylib"
  )

set_target_properties(Boost::container PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
  )

set_property(TARGET Boost::container APPEND
  PROPERTY INTERFACE_COMPILE_DEFINITIONS "BOOST_CONTAINER_DYN_LINK"
  )

list(APPEND _BOOST_CONTAINER_DEPS headers)
