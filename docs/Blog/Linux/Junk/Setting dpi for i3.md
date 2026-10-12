in ~/.Xresources:

```
*dpi: 120
Xft.dpi: 120
```

100% scaling is normally 96dpi, of course this will actually vary with monitors, but this is sort of a "standard." My monitor is 108x107 which can be found by doing

```
$ xrandr -query | grep dpi
```

or 

```
$ xdpyinfo | grep resolution
```

If 96dpi is "100%" then you can calculate the scaling by ratio

96+96 = 192, ie 200%

So if you want to find out the correct scaling for your monitor simply take your dpi (either 96 as standard, or the actual resolution of your screen) and then multiply it by 1.25 to get 125% scaling and so on.

If you don't have an Xresources file in your home directory, simply

```
$ touch .Xresources
```

and then add the config to it.