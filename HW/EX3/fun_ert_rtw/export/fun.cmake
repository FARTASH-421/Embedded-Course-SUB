include("${CMAKE_CURRENT_LIST_DIR}/funTargets.cmake")
set(FUN_OBJECTS_TOK_INC_DIRS_ALL
    ${MATLAB_ROOT}/extern/include
    ${MATLAB_ROOT}/simulink/include
    ${MATLAB_ROOT}/rtw/c/src
    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common
    ${MATLAB_ROOT}/rtw/c/ert)
foreach(TOKDIR_LOOP IN LISTS FUN_OBJECTS_TOK_INC_DIRS_ALL)
    if(IS_DIRECTORY ${TOKDIR_LOOP})
        list(APPEND FUN_OBJECTS_TOK_INC_DIRS ${TOKDIR_LOOP})
    endif()
endforeach()
target_include_directories(fun::fun_objects INTERFACE ${FUN_OBJECTS_TOK_INC_DIRS})
