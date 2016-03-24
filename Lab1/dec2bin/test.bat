echo off

echo test good input data 
dec2bin.exe 1 > 1.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b 1.txt standard/1.txt
IF ERRORLEVEL 1 GOTO testFailed


echo test good input data 
dec2bin.exe 23 > 23.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b 23.txt standard/23.txt
IF ERRORLEVEL 1 GOTO testFailed

echo test good input data 
dec2bin.exe 100000000 > 100000000.txt
IF ERRORLEVEL 1 GOTO testFailed
fc /b 100000000.txt standard/100000000.txt
IF ERRORLEVEL 1 GOTO testFailed

echo test without arguments
dec2bin.exe
IF NOT ERRORLEVEL 1 goto testFailed

echo test wrong data
dec2bin.exe -1
IF NOT ERRORLEVEL 1 goto testFailed



echo OK
pause
exit /B

:testFailed
echo Testing failed
pause
exit /B

 