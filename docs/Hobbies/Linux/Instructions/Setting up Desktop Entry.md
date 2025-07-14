https://forum.endeavouros.com/t/how-to-make-executables-appear-in-rofi/36393

Go to ~/.local/share/applications for local

Normal desktop files can be found at /usr/share/applications

Create a file called \<name\>.desktop

Add the following:
```ini
[Desktop Entry]
Encoding=UTF-8
Version=1.0
Type=Application
Terminal=false
#Exec=/path/to/executable
Exec=sh -c "/path/to/executable"
Name=Name of Application
Icon=/path/to/icon
```


