Mover 2.0 is a new solution for moving player characters through the world. It's still considered experimental in this new UE 5.4 release, but you can activate it via the plugins Edit>Plugins and then selecting Mover, Mover Examples, and MoverTests.

Mover is allegedly a more flexible, and modular alternative to the CharacterMovementComponent. 

### Mover Character

The plugin comes with two main character bases. MoverExamplesCharacter is a C++ class that extends the Pawn class and implements the IMoverInputProducerInterface interface; it seems most analogous to the Character C++ class. MoverTestPawn is a blueprint class that seems analogous to the FPS or TPS blueprint character that comes with the tutorials, ie it has a mannequin and a few things already implemented. It should be noted that the MoverExamplesCharacter seems to imply a pattern for making a mover based character, not necessarily a single class you should always use. It's a fairly small class that looks to be an example of how you would write your own character. 

### Mover Component

The big strengths of this plugin become apparent when looking at the CharacterMoverComponent (CMC2) vs CharacterMovementComponent (CMC1) that we've become familiar with. CMC2 is also a very small class compared to its predecessor, featuring only 4 stock virtual functions which end up totaling about 63 lines of code including empty lines in the CharacterMoverComponent.cpp file. The reason for its small size seems to stem from its modularity, compared to the CMC1 which was over 10k lines of code, very rigid, and very difficult to understand.

CMC2 inherits from MoverComponent which is a bit longer, but less than 1400 lines of code in the cpp file. What makes it different from CMC1 is that MovementModes are now defined externally from the actual component, which allows for more flexible extension. By default the CMC2 adds Walking, Flying, and Falling modes to a Map declared in the MoverComponent called MovementModes. The map has a name for key, and then the mode reference as value.

### Movement Modes

#### Common Legacy Movement Settings
### Movement Utils

#### FGroundMoveParams
