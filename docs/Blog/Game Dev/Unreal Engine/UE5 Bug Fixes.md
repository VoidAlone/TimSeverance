### Details Panel not showing for CMC
Sometimes the details panel will disappear in UE5 editor, with the only option being to edit in C++. To fix this, you can reparent the Character class. Set it to the next class level up (Pawn?), and then reparent it back down.

### The following modules are missing or built with a different engine version
Sometimes the project will randomly break and it won't be able to compile because of engine version (???). It'll ask if you want to rebuild the modules. If you click yes, and it says try rebuilding from source manually (which you already are) delete the intermediate, Saved, Binaries, and potentially the .vs folders in your project, and then rebuild.