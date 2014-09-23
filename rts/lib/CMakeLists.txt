
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/rts)

ADD_SUBDIRECTORY(lua)
ADD_SUBDIRECTORY(luasocket)
ADD_SUBDIRECTORY(7z)
ADD_SUBDIRECTORY(minizip)
ADD_SUBDIRECTORY(streflop)
ADD_SUBDIRECTORY(headlessStubs)

foreach(var BUILD_SHARED_LIBS ASSIMP_BUILD_ASSIMP_TOOLS ASSIMP_BUILD_TESTS)
	set("${var}" OFF CACHE STRING "forced off by spring build env" FORCE)
endforeach()

foreach(var ASSIMP_BUILD_STATIC_LIB ASSIMP_NO_EXPORT)
	message(STATUS "Forcing assimp option "${var}" to on")
	set("${var}" ON CACHE STRING "forced on by spring build env" FORCE)
endforeach()

ADD_SUBDIRECTORY(assimp)

if    (NOT HEADLESS_SYSTEM)

	if    (USE_LIBSQUISH)
		ADD_SUBDIRECTORY(rg-etc1)
		ADD_SUBDIRECTORY(squish)
	endif (USE_LIBSQUISH)
endif (NOT HEADLESS_SYSTEM)

