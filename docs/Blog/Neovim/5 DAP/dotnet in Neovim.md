**My Stack**

NEOVIM:
- lspconfig-nvim: let's me easily configure language servers so that I don't have to manually set everything up with the new API, mostly just defaults
- roslyn-nvim: provides sane defaults that aren't provided by lspconfig-nvim
- nvim-dap: provides support for integrating a debugger and ui with neovim
- nvim-dap-view: allows me to have a single (or more) window for watches, scopes, threads, REPL, disassembly, etc for debugging.
- Overseer-nvim: A task runner that supports vscode tasks as well as custom lua based tasks. Convenient for building projects
- blink.cmp: Completion plugin with support for LSPs, cmdline, signature help, and snippets. Makes the language server useful without having to do \<C-x\>\<C-o\> or whatever.
- luasnip (with friendly-snippets): provides snippets for most languages

SYSTEM PACKAGES:
- SDK/RUNTIME: To do any development, use the LSP, or DAP, you'll need an installation of .NET. You can do this a few ways. If you're on a distro that packages it (Arch, Ubuntu, and a few others do) you can just download your dotnet sdk/runtime package and you'll be set. Otherwise, head to microsoft, and download the manual install script called dotnet-install. It has --help flag, so it's pretty easy to use. You can install the SDK, Runtime, and some other stuff, and specify versions. If you download the binary instead of the install script, it'll automatically add dotnet to your path, but if you use the dotnet-install.sh script, you MUST add dotnet to your path [instructions](https://learn.microsoft.com/en-us/dotnet/core/tools/dotnet-install-script#set-environment-variables). 
- Language Server: You'll need to install the roslyn language server. Roslyn-nvim provides neat instructions on how to do this, but effectively you'll go get a nuget package that contains the language server, unzip it, and then you just have to point neovim to it. I followed the manual instructions but you could go with Mason if you're using it. My lsp-config is basically from chatgpt. It has a little bit mixed in that you won't find in the github docs. My lsp basically attachs on cs files and it looks in directorys with a csproj or sln. That snippet was from someone setting up their Godot config. The cmd is basically what you'd pass to your opts in your plugins install file, but it just passes arguments to the lsp for additional options.
- DAP: The final piece. This is gonna make you go. Going the microsoft way is a bit cursed, so I opted to use NetCoreDbg, your package manager may or may not have it. I have instructions on it below.

```lua
#[nvim/lua/config/lsp/lsp-config.lua]
local home = vim.fn.expand("~")
local target = home .. "/Repos/AltRepos/MicrosoftLanguageServer/content/LanguageServer/linux-x64"
vim.lsp.config("roslyn", {
    cmd = {
        "dotnet",
        target .. "/Microsoft.CodeAnalysis.LanguageServer.dll",
        "--logLevel=Information",
        "--extensionLogDirectory=" .. vim.fs.dirname(vim.lsp.get_log_path()),
        "--stdio",
    },
    root_dir = vim.fs.dirname(vim.fs.find({ "*.csproj", "*.sln" }, { upward = true,})[1]),
    filetypes = {'cs'},
    -- Add other options here
})

```

```lua
#[nvim/lua/config/dap/adapters/dotnet.lua]
local dap = require('dap')

dap.adapters.netcoredbg = {
  id = 'netcoredbg',
  type = 'executable',
  command = 'netcoredbg',
  args = {'--interpreter=vscode'}
}

dap.configurations.cs = {
  {
    type = 'coreclr',
    name = 'Launch - NetCoreDbg',
    request = 'launch',
    program = function()
      return vim.fn.input('Path to dll: ', vim.fn.getcwd() .. '/bin/Debug/net9.0/', 'file')
    end,
  },
}

dap.configurations.fs = {

}
```

For this one I'm using Samsung's NetCoreDbg. They have a slightly complicated set up. I'll probably make a whole post about .NET development in Linux. But here's the [link](https://github.com/Samsung/netcoredbg)

We can see a basic configuration, kind of the same as a basic .vscode/launch.json file.

The actual adapter is pretty simple. I can't remember where I got the adapter setup, if it was in a blog post or chatgpt, but for posterity, it's here.

id, type, and command are for nvim-dap. They just say what we're pointing to, the type it is, and what it's called (id). Args are for the debugger. So I just went with the vscode interpreter mode for the debugger, and didn't need to many other commands for now. I still haven't gotten deep into debugging C# yet.