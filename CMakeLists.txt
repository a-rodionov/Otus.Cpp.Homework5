cmake_minimum_required(VERSION 3.2)

# Определение PATCH_VERSION для локальной сборки и сборки на travis
set(PATCH_VERSION 1)
if($ENV{TRAVIS_BUILD_NUMBER})
  set(PATCH_VERSION $ENV{TRAVIS_BUILD_NUMBER})
endif()

project(homework5 VERSION 1.0.${PATCH_VERSION})

# Создание целей
add_executable(application main.cpp Application.cpp ApplicationState.cpp EmptyWorkspace.cpp DocumentWorkspace.cpp)

# Настройка целей

# для всех целей
set_target_properties (application PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)
