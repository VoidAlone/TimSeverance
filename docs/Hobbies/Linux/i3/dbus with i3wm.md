I ran into an issue where apps, mostly flatpaks, weren't running because they couldn't connect to dbus. To fix this, it's really simple, but hard to find the answer. I am not using startx. I'm using sddm currently, sometimes I use gdm, sometimes lightdm. In either scenario, most help online says to launch i3wm with dbus using your .xinitrc. This doesn't work.

In ~/.xsession add the following line anywhere in your file

```
exec dbus-run-session -- i3
```

You can probably also set your desktop entry to use this as well, but I found this to work and be a bit more simple than tracking down your desktop entries, cause I always forget where those are exactly.