@echo off
IF EXIST "script/win-convertor" (
    xcopy "script/win-convertor" "build\win-convertor\" /E /I
    echo win-convertor moved in build.
) ELSE (
    echo win-convertor no found.
)

