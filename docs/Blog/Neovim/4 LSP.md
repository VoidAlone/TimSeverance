LSP (Language Server Protocol) is a protocol developed by Microsoft. It's a protocol that brings a unfieid approach to LSP implementation across all text editors. 

Traditionally, editors had no unified way of interfacing with a language server, because there was no unified way for language developers to implement a language server in the first place. My assumption is that this played a part in why there were so many language specific editors over the years. 

Now that we have the LSP, language servers can be written in a unified way, and editor developers can use the protocol to allow you to hook any language server into your editor. It's a beautiful thing. Traditionally, people used to say things like "well, a text editor is just a text editor, it's not supposed to be a full IDE." Statements like that are almost extinct now because of how much functionality you can get out of even barebones editors like neovim.

###

This year marked Neovim 0.11 which came with a huge change to the LSP API. It's very simple to set up lsps now.

The current paradigm is the set up an lsp directory in your nvim root directory. I don't even do that, I keep it super simple with lsp-config

### Install lspconfig

Lsp-config actually doesn't do much besides provide defaults for your lsp. You pretty much need to install lsps in the new neovim way.
### Install Language Servers
### Set up autocomplete
### Snippets