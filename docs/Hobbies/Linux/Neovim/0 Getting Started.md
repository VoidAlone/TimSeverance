Holy hell I love Neovim. Like, I feel like I've had a spiritual experience learning about it. Those two years I spent in Brazil telling people about the Book of Mormon, I really should have spent telling them about Neovim. To make up for it, I will now tell you how you can set up neovim and hopefully bridge the gap where all those shitty blog plots fail.

### Distros

I got started using kickstart and lazyvim. Kickstart is really cool and incredibly simple, but even that was a bit too much for me. TJ Devries who wrote it is the GOAT, but I'm the kind of person that really has to start from scratch and get my hands dirty. I ended up watching a lot of his videos instead of using his config file. Kickstart isn't a distro per se, it's just a configuration file with some simple plugins to start. It's meant to be a more gentle entry point to neovim, and help you get acquainted with setting up keymaps, plugins, etc.

Lazyvim is really good too, but I was immediately overwhelmed by everything it offers. I'm new, so I didn't have any context for what anything was. 

Now, distros are great, but for me, the main point of neovim is twofold: 1) learn vim motions for rapid development and navigation 2) full customization.

The problem with distros, is that it encourages you to use your mouse to start. A lot of these distros end up giving you a layout that resembles vscode, which I'm trying to move away from. Since I didn't want to use my mouse, I didn't know how to use the keys, and therefore, didn't understand how to use the distros to start. The other problem was that because the distros come with everything out of the box, I'm not really customizing my editing experience anymore than I would be with vscode. 

Again, I wanted to learn from scratch. That's also partially the reason my first linux distro was and is Void. 
### Making your own

So far, there are a few key points that you need to be aware of when setting up neovim. I'm no expert, I don't have insane keymaps, macros, or autocommands set up yet, but I'm fairly comfortable with what you need to get moving.

Here's a list of things you need be aware of:

1) Keymaps / Motions
2) Navigation / Workflow
3) Plugins
4) LSP
5) DAP

I'll write a page for each of these items and link them.

### Organization

Here's an outline of my filetree. 

.
└── lua
    ├── config
    ├── core
    ├── overseer
    └── plugins