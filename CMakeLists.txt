
cmake_minimum_required( VERSION 2.6 )
project( xrootd-snag )

set( CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

find_package( Xrootd REQUIRED )

if( CMAKE_COMPILER_IS_GNUCXX )
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror" )
endif()

if( CMAKE_COMPILER_IS_GNUCC )
  set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror" )
endif()

SET( CMAKE_SHARED_LINKER_FLAGS "-Wl,--no-undefined")
SET( CMAKE_MODULE_LINKER_FLAGS "-Wl,--no-undefined")
SET( CMAKE_EXE_LINKER_FLAGS "-Wl,--no-undefined")

include_directories( "${PROJECT_SOURCE_DIR}" "${XROOTD_INCLUDES}" )

add_library(XrdSnag MODULE src/XrdSnagFile.cc src/XrdSnagFileSystem.cc src/XrdSnagConfig.cc)
target_link_libraries(XrdSnag ${XROOTD_UTILS})

if (NOT DEFINED LIB_INSTALL_DIR)
  SET(LIB_INSTALL_DIR "lib")
endif()

install(
  TARGETS XrdSnag
  LIBRARY DESTINATION ${LIB_INSTALL_DIR} )

set_target_properties(
  XrdSnag
  PROPERTIES
  VERSION   "0.0.1"
  SOVERSION "0"
  LINK_INTERFACE_LIBRARIES "" )

