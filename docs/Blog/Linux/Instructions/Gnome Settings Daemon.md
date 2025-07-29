This is an excerpt from a forum post

For what it's worth, running i3 with "DE enhanced" goodness seems quite a bit easier than it used to be.

Myself, I use (and recommend) people start i3 through GDM (this is on a system with GNOME already installed running properly). From there, the only magic necessary should be to add this (or similar) into your `.i3/config`:

```exec /usr/libexec/gnome-settings-daemon```

Now laptop media keys (brightness, volume) should work, in addition to Gtk themes and other GNOME stuff. Your mileage may vary, and I do remember from previous approaches to the problem that individual subsystems would have to be `exec'd` individually, i.e. the power subsystem.

EDIT: I can now confirm that the power subsystem works without any extra effort once the `gnome-settings-daemon` is started. This is when logging in through GDM (Fedora 17).

I was having issues with dbus sessions and whatnot working. Doing this and executing the gnome-settings-deamon worked great. 

To set gdm as the display manager (login screen) on void linux, you just have to create a symlink. Be sure to unlink your display service first

```
sudo unlink /var/service/lightdm
```

```
sudo ln -s /etc/sv/gdm /var/service/
```

My next plan is try out Plasma + i3. That might end up also being a crispy experience.

https://faq.i3wm.org/question/279/how-do-you-use-i3-comfortably/?answer=342#post-id-342


