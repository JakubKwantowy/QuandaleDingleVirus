set objFS = CreateObject("Scripting.FileSystemObject")
path = Left(Wscript.ScriptFullName, len(Wscript.ScriptFullName) - len(Wscript.ScriptName))
set file = objFS.OpenTextFile(path & "spread.vbs", 1)
content = file.ReadAll
file.Close
output = ""
for i = 1 to len(content)
	output = output & asc(mid(content,i,1))
	if i < len(content) then output = output & ";"
next
msgbox output
set file = objFS.OpenTextFile(path & "spread.vbs.txt", 2, True)
file.Write output
file.Close
