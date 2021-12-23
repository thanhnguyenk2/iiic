set MATLAB=E:\Matlab

cd .

if "%1"=="" ("E:\Matlab\bin\win64\gmake"  -f PID_SingleTank.mk all) else ("E:\Matlab\bin\win64\gmake"  -f PID_SingleTank.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
