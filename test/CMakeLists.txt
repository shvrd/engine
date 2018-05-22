set(REPO ../.repo)

project(EngineTest)

include(CTest)
enable_testing()

#set(gtest_disable_pthreads on) #needed in MinGW
include(${REPO}/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        UPDATE_DISCONNECTED 1
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR} EXCLUDE_FROM_ALL)
include_directories(${googletest_SOURCE_DIR} ../src)

set(test_SRCS gtestTest.cpp TestingGameState.h GameContainerTest.cpp)
add_executable(runUnitTests gtest.cpp ${test_SRCS})
target_link_libraries(runUnitTests gtest gmock shvrdengine spdlog::spdlog ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} ${PNG_LIBRARIES} ${OPENGL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${GLEW_LIBRARIES} ${GLM_LIBRARIES} ${SDL2MIXER_LIBRARIES} ${Boost_LIBRARIES} ${OPENAL_LIBRARY})