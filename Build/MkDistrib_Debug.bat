CLS
MKDIR WinGUI_Distrib
COPY /B WinGUI_Bin\Debug\KeePass.exe /B WinGUI_Distrib\KeePass.exe

REM DEL ..\Ext\WinGUI_API\KeePass.lib
REM COPY /B WinGUI_Bin\Debug\KeePass.lib /B ..\Ext\WinGUI_API\KeePass.lib
REM DEL ..\Ext\WinGUI_API\KeePass.exp
REM COPY /B WinGUI_Bin\Debug\KeePass.exp /B ..\Ext\WinGUI_API\KeePass.exp

DEL WinGUI_Distrib\KeePass.chm
COPY /B ..\..\..\Homepage_KeePass\Build_Chm_v1\KeePass.chm /B WinGUI_Distrib\KeePass.chm

DEL WinGUI_Distrib\License.txt
COPY /B ..\Docs\License.txt /B WinGUI_Distrib\License.txt

DEL WinGUI_Distrib\KeePass.ini
COPY /B ..\Ext\KeePass.ini /B WinGUI_Distrib\KeePass.ini
