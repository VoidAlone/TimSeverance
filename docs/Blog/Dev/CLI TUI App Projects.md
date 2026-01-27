### ncweather? btwttr?

I think it'd be a lot of fun to develop an CLI TUI for weather. Something very aesthetic and weathery feeling, and maybe even use something like NotCurses to display low-res doppler radar for local weather in the terminal.

### btRandR

This one I'm working on now. Most of the options I've seen for applying monitor/display configurations are garbage. 

xrandr as far as I understand is the main way to adjust display settings. The problem is that it's cli / text based configs for an explicitly visual experience. Memorizing commands for how you want your monitor to appear sucks ass and is honestly just counter intuitive to the entire visual experience

Other apps like lxrandr, arandr, and so on are very limited. Especially when it comes to scaling and dpi configuration.

My plan is to make a TUI so that it finds a happy middle ground between being something that's fast, lightweight, and something that can illustrate your display options. A TUI could work nicely for maybe showing screen layouts, while still having text based selections for scaling, layout, dpi etc probably in the form of menus for each setting category.