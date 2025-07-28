**My Stack**

NEOVIM:
- lspconfig-nvim: let's me easily configure language servers so that I don't have to manually set everything up with the new API
- nvim-dap: provides support for integrating a debugger and ui with neovim
- nvim-dap-view: allows me to have a single (or more) window for watches, scopes, threads, REPL, disassembly, etc for debugging.
- Overseer-nvim: A task runner that supports vscode tasks as well as custom lua based tasks. Convenient for building projects
- blink.cmp: Completion plugin with support for LSPs, cmdline, signature help, and snippets. Makes the language server useful without having to do \<C-x\>\<C-o\> or whatever.
- luasnip (with friendly-snippets): provides snippets for most languages, but very convenient for c++.

PACKAGES:
- ccls: Language server. I don't mess with clang, so I don't use a clang language server. Beyond that, I'm not completely familiar with the benefits of ccls.
- GCC: GNU Compiler Collection. I use g++, gdb, and GCC supports rust, ada, fortran, etc. Nice one stop shop. 

### Set up

LSP:

lspconfig is as simple as enabling ccls. If your language server is on the path, it's already exposed to neovim. There are other ways to expose it if it's not, but in my case, I installed ccls through my package manager and vim was able to find it. To confirm, you can open the command-line and type \<echo executable('ccls')\> and hit enter. If it gives a 1, then neovim can see it. You're good to go. You now have a language server for c++. I find it to be quite snappy. blink.cmp will automatically offer completion for ccls.

DAP:

This part is a bit messier but not too bad. If you're using .vscode/launch.json and .vscode/tasks.json files, this is the most "out of the box" experience imo. nvim-dap and overseer detects both of these.

To set up debugging, install nvim-dap, follow the instructions and set up the keybinds. Add nvim-dap-view and set your commands up for launch, step into, step over, etc. I set mine so that they'd be grouped together in which-key using whichkey.add({...})

Once you have the plugins installed following their various minimal instructions, you need to set up adapters for a given language. In my config directory under DAP, I have config files for my dap plugins, and then an adapters folder. Here's my adapter set up for gdb with support for at least c++ so far.

```lua
local dap = require('dap')

dap.adapters.gdb = {
    id = 'gdb',
    type = 'executable',
    command = 'gdb',
    args = {'--interpreter=dap', '--eval-command', 'set print pretty on',},
}

local function gdb_general_config(name)
    return{
        name = name,
        type = 'gdb',
        request = 'launch',
        program = function()
            local path = vim.fn.input({
                prompt = 'Path to executable: ',
                default = vim.fn.getcwd() .. '/',
                completion = 'file',
            })
            return path
        end,
        cwd = '${workspaceFolder}',
        stopAtBeginningOfMainSubprogram = false,
        setupCommands = {
            text = '-enable-pretty-printing',
            ignoreFailures = true
        }
    }
end

dap.configurations.c = {
    gdb_general_config('Launch C (GDB)')
}

dap.configurations.cpp = {
    gdb_general_config('Launch C++ (GDB)')
}

dap.configurations.rust = {
    gdb_general_config('Launch Rust (GDB)')
}

dap.configurations.ada = {
    gdb_general_config('Launch Ada (GDB)')
}
```

Since I'm using gcc which supports multiple languages, I can use gdb for a number of languages. This 100% works so far on C++. 

Then, you need to set up a configuration for building a c++ project, here's my overseer config. Follow overseer's instructions, and in lua>overseer>templates>user>... you can do something like cpp_build.lua. Here's my miminal task configuration

```lua
-- /home/stevearc/.config/nvim/lua/overseer/template/user/cpp_build.lua
return {
  name = "g++ build",
  builder = function()
    -- Full path to current file (see :help expand())
    local file = vim.fn.expand("%:p")
    return {
      cmd = { "g++" },
      args = { file , '-g'},
      components = { { "on_output_quickfix", open = true }, "default" },
    }
  end,
  condition = {
    filetype = { "cpp" },
  },
}
```

This is slightly different from the example given on their github just in that I include a '-g' flag, otherwise you can't set breakpoints which defeats the whole point of a debugger in the first place.

### Conclusion

Well that's about it. I'll add more details for configuring each plugin, perhaps with my code. But for the most part, setting up debuggers and lsp in neovim is pretty straight forward in 2025, and I can only imagine it getting better (hopefully). 