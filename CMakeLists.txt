# CMake 최소 요구 버전 설정
cmake_minimum_required(VERSION 3.30.5)

# 프로젝트 이름 설정 (C와 C++ 언어 사용)
project(Algorithm_Practice C CXX)

# 프로젝트 전체에 적용될 C++ 표준을 맨 위에 설정합니다.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 모든 하위 폴더에서 .cpp와 .c 파일을 재귀적으로 검색합니다.
# CONFIGURE_DEPENDS 옵션으로 파일 추가/삭제 시 빌드할 때 재구성하도록 합니다.
file(GLOB_RECURSE ALL_SOURCES CONFIGURE_DEPENDS
        "1.Algorithm/*.cpp" "1.Algorithm/*.c"
        "2.Academy/*.cpp" "2.Academy/*.c"
        "3.HUFS/*.cpp" "3.HUFS/*.c"
        "*.cpp" "*.c"
)

# 찾은 각 소스 파일에 대해 반복합니다.
foreach (SOURCE_FILE ${ALL_SOURCES})
    # 1. IDE에 표시될, 사람이 읽기 좋은 이름을 만듭니다 (원본 상대 경로 사용).
    file(RELATIVE_PATH DISPLAY_NAME ${CMAKE_SOURCE_DIR} ${SOURCE_FILE})

    # 2. 파일 경로를 기반으로 절대 중복되지 않는 고유한 MD5 해시 값을 생성합니다.
    #    이것이 CMake가 내부적으로 사용할 안전하고 유일한 이름이 됩니다.
    string(MD5 SANITIZED_NAME ${DISPLAY_NAME})

    # 3. 해시 값으로 실행 파일 타겟을 추가합니다. (이름 앞에 'T_'를 붙여 더 명확하게 함)
    add_executable(T_${SANITIZED_NAME} ${SOURCE_FILE})

    # 4. 파일 확장자가 .cpp인 경우에만 C++20 표준 기능을 적용합니다.
    if (SOURCE_FILE MATCHES "\\.cpp$")
        target_compile_features(T_${SANITIZED_NAME} PRIVATE cxx_std_20)
    endif ()

    # 5. IDE에는 여전히 읽기 좋은 원래 파일 경로를 표시하도록 설정합니다.
    set_property(TARGET T_${SANITIZED_NAME} PROPERTY PROJECT_LABEL "${DISPLAY_NAME}")
endforeach ()