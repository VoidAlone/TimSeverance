KDE uses Kwin as its compositor which is responsible for desktop window, desktop effects, etc.

It's possible to get a lot of the out-of-the-box functionality that comes with a full blown desktop while still getting the efficiency and keyboard-centric navigation that comes with a tiling window manager. Some argue that i3 is meant to be minimalist, I argue that it's meant to provide keyboard-centric navigation and tiling window management. Minimalism is a secondary property of i3wm and you're free to bloat it as much or as little as you want in a config. 

[Here's a reference from arch on how to do it, but I'll explain it](https://wiki.archlinux.org/title/KDE#Use_a_different_window_manager)

[And another explanation from someone else with sane configs](https://github.com/heckelson/i3-and-kde-plasma)

I'm on void linux which does not use systemd, and instead uses runit. That means that we don't use any kind of systemctl commands. Either way this is good because the alternative is to set up an xsessions Desktop Entry that's system wide.

You must do a few things

- Create a Desktop Entry and paste the code: 
	
	/usr/share/xsessions/plasma-i3.desktop
	
	[Desktop Entry]
	Type=XSession
	Exec=env KDEWM=/usr/bin/i3 /usr/bin/startplasma-x11
	DesktopNames=KDE
	Name=Plasma with i3
	Comment=Plasma with i3
- In my case, I don't have to mask the service. The KDEWM flag is used to start it instead. Either way, you can use systemctl mask or just do a symlink to /dev/null for the plasma-kwin.service file.
- Add sensible KDE settings to your ~/.config/i3/config file. I actually have a switcher script that allows me to have an i3 config for vanilla i3 or plasma+i3, and then depending on which one is running, it symlinks the proper configuration to config and reloads i3. 

```
#!/bin/bash

# Define paths to your config files
DEFAULT="$HOME/.config/i3/config.default"
CONFIG2="$HOME/.config/i3/config.plasma-i3"
CURRENT_CONFIG="$HOME/.config/i3/config"

# Detect the desktop environment (example with XDG_CURRENT_DESKTOP)
DESKTOP_ENV=$(echo $DESKTOP_SESSION)

if [[ "$DESKTOP_ENV" == "plasma-i3" ]]; then
	ln -sf "$CONFIG2" "$CURRENT_CONFIG"
	echo "Using plasma-i3 configuration."
else
	ln -sf "$DEFAULT" "$CURRENT_CONFIG"
	echo "Using default i3 configuration."
fi

# Restart i3 to apply changes
i3-msg reload
```
  
  then in your .xinitrc
  
```
# Check if i3wm is running then switch
if pgrep -x "i3" > /dev/null; then
    bash ~/.config/i3/profile_switcher.sh &
fi
```