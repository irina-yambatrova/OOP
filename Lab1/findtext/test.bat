echo off 

echo test1
findtext.exe "notfoundtext.txt" "sad"> 1.txt 
IF NOT ERRORLEVEL 1 GOTO testFailed 
fc /b 1.txt standard/1.txt
IF ERRORLEVEL 1 GOTO testFailed 

echo test2
findtext.exe > 2.txt 
IF  NOT ERRORLEVEL 1 GOTO testFailed 
fc /b 2.txt standard/2.txt 
IF ERRORLEVEL 1 GOTO testFailed 

echo test3 
findtext.exe "input.txt" "pretty" > 3.txt 
IF ERRORLEVEL 1 GOTO testFailed 
fc /b 3.txt standard/3.txt 
IF ERRORLEVEL 1 GOTO testFailed 

echo OK 
pause 
exit /B 

:testFailed 
echo Testing failed 
pause 
exit /B