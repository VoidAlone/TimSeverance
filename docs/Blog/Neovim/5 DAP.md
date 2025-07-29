This is where shit gets real. This is the part where most people flake out. Setting up an lsp is a cakewalk, but DAP is where I tend to find less resources, and when I go to discord servers and ask questions, most people come up dry with answers.

DAP is sort of the final boss of neovim in my opinion. Maybe there's more, but this is the most trick thing I've run into so far.

Part of that is that I find a LOT of devs don't use debuggers, mostly because most devs are bad. People who do use debuggers tend to go with a fully featured IDE like JetBrains or Visual Studio if you have to or something along those lines. Outside of those scenarios, I have an ungodly amount of students who crutch print statements even in their 3rd and 4th years. Don't get me wrong, prints are fine, but only for really quick scenarios, and in limited quantities.

### Background

DAP (Debug Adapter Protocol) is yet another microsoft technology. I hate microsoft, except for the times when they make really cool stuff like LSP, DAP, VSCode, .NET, etc... Okay I just hate their executives, telemetry, and windows. Besides that, they have some really cool people making some really cool stuff when they don't have dragons breathing down their necks. DAP does the same thing LSP does, in that it brings a unified way to add debuggin capabilities to any text editor. This is MASSIVE. Debugging was virtually non-existent in neovim from what I can tell just a few years ago. Now that we have DAP though, it's way more straight forward to set up debuggers for neovim. I imagine we'll get a big API change to neovim regarding dap in the same way that we got one for LSP. 

### Preface

I do not use Mason. It obfuscates the process a bit more than I like, and muddles things up. The biggest thing it brings to the table is a unified way to install your language servers, debuggers, and linters. However, I prefer to just install the packages I need via my package manager (XBPS). 

### Plugins

I use the following plugins:

nvim-dap
nvim-dap-view / nvim-dap-ui
nvim-dap-python
overseer

### DAP

To get this thing going, you need to install nvim-dap. You can find the proper instructions for installation in the github repo depending on your package manager. 

### UI

I prefer using nvim-dap-view because it provides a simpler interface for debugging. nvim-dap-ui is a more traditional vscode-like interface with multiple windows. I find that for neovim, that encourages mouse use, and so I prefer to stay away from it, even though it does look really good, and has slightly more convenience.

nvim-dap-view is nice because it opens a single window which is really easy to navigate to using \<C-w\>. If you use smartsplits plugin, it can make nvim-dap-ui a bit better to navigate with your keyboard. I'm going to be looking into that soon.

### Adapters

How to set up adapters for each language

### Overseer

This is the final boss. For languages like C++ that require a more complex toolchain for building, it's essential to have a set up for building, running, and debugging.  

I'm using overseer for this. Overseer allows you to use native vscode style .vscode/tasks.json files for your prelaunch tasks (ie, building). You can drop a .vscode folder with a tasks.json into your project, and it will automatically see it and be able to run it. It doesn't support all of the fields for a tasks.json file, but for simple tasks so far, it does the trick (cppbuild doesn't work, you have to use "shell" for the "type" field)

Overseer also provides a way for you to set up templates. This is a bit better than always manually setting up tasks.json yourself. I'm looking into setting up snippets for tasks.json as well, but that's a bit more involved.

Once you have overseer, another huge benefit is that if you have a launch.json file in your .vscode, it can read the prelaunch task and automatically run the task when you run nvim-dap continue.

