cmake_minimum_required(VERSION 3.13.0)

cmake_policy(SET CMP0048 NEW) # This policy sets the VERSION variable with the project() command

project(life-incubator VERSION 1.0.0 DESCRIPTION "Desktop client that displays the status of the life incubators connected wirelessly or through a network channel, and allows to change the configuration of the incubation" HOMEPAGE_URL "https://www.github.com/scifir/life-incubator-desktop-client" LANGUAGES "CXX")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER_VERSION 13.2)

include(extra/FindLinuxDistribution.cmake)

if (DEFINED LINUX_LIBRARY_DIR)
	set(Boost_LIBRARY_DIR ${LINUX_LIBRARY_DIR})
endif()

if (NOT DEFINED LINUX_LIBRARY_DIR AND PLATFORM MATCHES "linux")
	set(CMAKE_LIBRARY_PATH "/usr/lib/*;/usr/lib;/usr/lib64")
endif()

if (PLATFORM MATCHES "windows")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MT")
endif()

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)
option(BUILD_TESTING "Build test programs" OFF)
option(DEBUG_FLAGS "Add debug flags" OFF)
option(WARNING_FLAGS "Add warning flags" OFF)

if(DEBUG_FLAGS)
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Og")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /EHsc")
	endif()
	if(BUILD_TESTING AND (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang"))
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
		set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage -lgcov")
	endif()
endif()

if(WARNING_FLAGS)
	if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
	endif()
	if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Wall")
	endif()
endif()

if(DEFINED(${INCLUDE_PATH}))
	include_directories(${INCLUDE_PATH})
endif()
if(DEFINED(${LINK_PATH}))
	link_directories(${LINK_PATH})
endif()

set(Boost_NO_BOOST_CMAKE ON)
set(Boost_NO_SYSTEM_PATHS ON)
set(Boost_USE_DEBUG_LIBS        OFF)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.66.0 REQUIRED COMPONENTS system)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif()

if(!Boost_FOUND)
  message("Libraries of Boost not found, configure Boost_ variables properly and/or install Boost adequately. You can search the documentation of FindBoost, part of CMake, to learn the Boost_ variables to configure. Inside the README.md of scifir-units is also the explanation of how to configure Boost_ variables.")
endif()

find_package(ICU 70 COMPONENTS uc REQUIRED)

if(!ICU_FOUND)
	message("Library ICU not found, install it in your system first.")
endif()

aux_source_directory(ui SRC_LIST)
aux_source_directory(ui/windows SRC_LIST1)
aux_source_directory(core SRC_LIST2)
aux_source_directory(data SRC_LIST3)

if (PLATFORM MATCHES "linux")
	find_package(PkgConfig REQUIRED)
	pkg_search_module(GTK gtk-3.0)
	
	aux_source_directory(extra SRC_LIST4)
	
	include_directories(/usr/include/wx-3.2 /usr/include/gtk-3.0 /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include /usr/include/cairo /usr/include/pango-1.0 /usr/include/harfbuzz /usr/include/gdk-pixbuf-2.0 /usr/include/graphene-1.0 /usr/lib/x86_64-linux-gnu/graphene-1.0/include /usr/include/atk-1.0 ${GTK_INCLUDE_DIRS})
endif()

if (PLATFORM MATCHES "windows")
	#set(wxWidgets_DEBUG ON)
	#include_directories(C:\Programas\wxWidgets-3.3.0\include)
	#set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH} C:/Programas/wxWidgets-3.3.0 C:/Programas/wxWidgets-3.3.0/lib/vc_x64_dll")
	#set(wxWidgets_DIR "C:/Programas/wxWidgets-3.3.0/install/lib/cmake/wxWidgets")
	#set(CMAKE_PREFIX_PATH "C:/Programas/wxWidgets-3.3.0/install/lib/cmake/wxWidgets")
	#set(wxWidgets_USE_STATIC ON)
	#set(wxWidgets_INCLUDE_DIRS "C:/Programas/wxWidgets-3.3.0/include C:/Programas/wxWidgets-3.3.0/lib/vc_x64_dll/mswu")
	#set(wxWidgets_ROOT_DIR "C:/Programas/wxWidgets-3.3.0")
	#set(wxWidgets_LIB_DIR "C:/Programas/wxWidgets-3.3.0/lib/vc_x64_lib")
	#set(wxWidgets_CONFIGURATION mswu)
	#set(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a .dll)
#	include_directories(C:\Programas\vcpkg\installed\x64-windows\lib\mswu\wx $env{VCPKG_ROOT}/installed/$env{VCPKG_DEFAULT_TRIPLET}/include/wx $env{VCPKG_ROOT}/installed/$env{VCPKG_DEFAULT_TRIPLET}/include/wx/msw)
endif()

include_directories(.)
#include_directories(${PROJECT_NAME} PUBLIC ${wxWidgets_INCLUDE_DIRS})

# Add that for win32 only
#set(wxWidgets_CONFIGURATION mswu)
#set(wxWidgets_ROOT_DIR /usr/include/wx-3.2)
#set(wxWidgets_LIB_DIR /usr/lib/x86_64-linux-gnu)
find_package(wxWidgets REQUIRED COMPONENTS core net base adv stc aui html media gl)
#set(wxWidgets_USE_LIBS)
#find_package(wxWidgets REQUIRED COMPONENTS core base)
#include(${wxWidgets_USE_FILE})
#message(${wxWidgets_USE_FILE})

if (PLATFORM MATCHES "windows")
	add_executable(${PROJECT_NAME} WIN32 msvc/resource.rc ${SRC_LIST} ${SRC_LIST1} ${SRC_LIST2} ${SRC_LIST3} ${SRC_LIST4})
endif()

if (PLATFORM MATCHES "linux")
	add_executable(${PROJECT_NAME} ${SRC_LIST} ${SRC_LIST1} ${SRC_LIST2} ${SRC_LIST3} ${SRC_LIST4})
endif()

#include_directories("C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/include")
#include_directories("${VCPKG_ROOT}/installed/${VCPKG_DEFAULT_TRIPLET}/include")
#include_directories("C:/Programas/wxWidgets-3.3.0/lib/vc_x64_lib/msw")
#include_directories("C:/Programas/wxWidgets-3.3.0/include")
#include_directories("C:/Programas/wxWidgets-3.3.0/include/wx")
#include_directories("C:/Programas/wxWidgets-3.3.0/include/msvc")

#add_definitions(-DUNICODE -D_UNICODE)

target_link_libraries(${PROJECT_NAME} scifir-biology scifir-chemistry scifir-units Boost::system ${ICU_LIBRARIES} ${wxWidgets_LIBRARIES})

if (PLATFORM MATCHES "windows")
	#target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
endif()

if (PLATFORM MATCHES "linux")
	target_link_libraries(${PROJECT_NAME} ${GTK_LIBRARIES} gdk-3 gtk-3 vlc bluetooth)
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

#add_definitions(${wxWidgets_DEFINITIONS})

set(WIX_CANDLE_EXECUTABLE "candle") # or full path
set(WIX_LIGHT_EXECUTABLE "light")   # or full path

set(MYAPP_BINARY "${CMAKE_BINARY_DIR}/installer/MyApp.exe")
set(WXS_FILE "${CMAKE_CURRENT_SOURCE_DIR}/MyApp.wxs")
set(WIXOBJ_FILE "${CMAKE_CURRENT_BINARY_DIR}/MyApp.wixobj")
set(MSI_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/MyAppInstaller.msi")

add_custom_command(
    OUTPUT ${WIXOBJ_FILE}
    COMMAND ${WIX_CANDLE_EXECUTABLE} -o ${WIXOBJ_FILE} -dMyAppBinary=${MYAPP_BINARY} ${WXS_FILE}
    DEPENDS ${WXS_FILE} ${MYAPP_BINARY}
    COMMENT "Running WiX candle..."
)

add_custom_command(
    OUTPUT ${MSI_OUTPUT}
    COMMAND ${WIX_LIGHT_EXECUTABLE} -o ${MSI_OUTPUT} ${WIXOBJ_FILE}
    DEPENDS ${WIXOBJ_FILE}
    COMMENT "Running WiX light..."
)

add_custom_target(MyAppInstaller ALL
    DEPENDS ${MSI_OUTPUT}
)