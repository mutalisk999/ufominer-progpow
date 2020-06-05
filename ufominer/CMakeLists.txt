cmake_policy(SET CMP0015 NEW)

aux_source_directory(. SRC_LIST)

include_directories(BEFORE ..)

set(EXECUTABLE ufominer)

file(GLOB HEADERS "*.h")

# add_executable(${EXECUTABLE} ${SRC_LIST} ${HEADERS})
add_executable(${EXECUTABLE} main.cpp ${HEADERS})

if(MSVC)
	target_sources(${EXECUTABLE} PRIVATE ufominer.rc)
endif()

hunter_add_package(CLI11)
find_package(CLI11 CONFIG REQUIRED)

target_link_libraries(ufominer PRIVATE ethcore poolprotocols devcore ufominer-buildinfo CLI11::CLI11 Boost::system Boost::thread)

add_executable(progpow_test1 progpow_test1.cpp)
target_link_libraries(progpow_test1 PRIVATE ethcore poolprotocols devcore ufominer-buildinfo CLI11::CLI11 Boost::system Boost::thread)

add_executable(progpow_test2 progpow_test2.cpp)
target_link_libraries(progpow_test2 PRIVATE ethcore poolprotocols devcore ufominer-buildinfo CLI11::CLI11 Boost::system Boost::thread)


if(DBUS)
	find_package(PkgConfig)
	set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/usr/lib/x86_64-linux-gnu/pkgconfig" )
	pkg_check_modules(DBUS dbus-1)
	include_directories(${DBUS_INCLUDE_DIRS})
	link_directories(${DBUS_LIBRARY_DIRS})
	target_link_libraries(ufominer PRIVATE ${DBUS_LIBRARIES})
endif()

if(API)
	target_link_libraries(ufominer PRIVATE apicore)
endif()

include(GNUInstallDirs)

install(TARGETS ufominer DESTINATION ${CMAKE_INSTALL_BINDIR})

if(MSVC)
    install(FILES $<TARGET_PDB_FILE:ufominer> DESTINATION ${CMAKE_INSTALL_BINDIR} OPTIONAL)
endif()
