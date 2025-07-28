
The Character Movement Component is the main component responsible for moving a "player" within a game world. It comes with a lot of adjustable parameters out of the box, and its default implementation is multiplayer ready. However, if you want to extend this component, and create your own movement systems, it is one of the worst documented tools in Unreal Engine. It is massive, under-documented, and rigid. 

The CMC has processes for calculating movement and updating those moves across a network, and across the engine. Most everything in the CMC doesn't need to be tampered with, but a few items need to be extended. 

### Movement Process

### Networking

In order to replicate your movement process across the client, you must extend the FSavedMove class.

#### Class FSavedMove_... Methods

##### Required

Clear
- Clear saved move properties, so it can be re-used.

SetMoveFor
- Called to set up this saved move (when initially created) to make a predictive correction.

PrepMoveFor
- Called before ClientUpdatePosition uses this SavedMove to make a predictive correction

CanCombineWith
- Returns true if this move can be combined with NewMove for replication without changing any behavior

GetCompressedFlags
- Returns a byte containing encoded special movement information (jumping, crouching, etc.)
##### Non Required

SetInitialPosition
- Set the properties describing the position, etc. of the moved pawn at the start of the move.

IsImportantMove
- Returns true if this move is an "important" move that should be sent again if not acked by the server

GetRevertedLocation
- Returns starting position if we were to revert the move, either absolute StartLocation, or StartRelativeLocation offset from MovementBase's current location (since we want to try to move forward at this time).

PostUpdate
- Set the properties describing the final position, etc. of the moved pawn

CombineWith
- Combine this move with an older move and update relevant state.

IsMatchingStartControlRotation
- Compare current control rotation with stored starting data

GetPackedAngles
- Packs control rotation for network transport

AddStructReferenceObjects
- Allows references to be considered during GC


#### Class FNetworkPredictionData_Client_... Methods

AllocateNewMove()