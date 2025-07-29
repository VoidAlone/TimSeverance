
### Pipeline to apply movement in game world

CMC = CharacterMovementComponent
MC = MovementComponent
SC = SceneComponent

CMC.PhysWalking() -> CMC.MoveAlongFloor() -> CMC.SlideAlongSurface() -> 

MC.SafeMoveUpdatedComponent() -> MC.MoveUpdatedComponent() -> MC.MoveUpdatedComponent() -> MC.MoveUpdatedComponentImpl() -> 

SC.MoveComponent() -> SC.MoveComponentImpl -> SC.InternalSetWorldLocationAndRotation() -> Sidesteps and sets the location with SC.SetRelativeLocation_Direct() -> SC.UpdateComponentToWorldWithParent() -> SC.PropagateTransformUpdate() -> UpdateChildTransforms

Note that slidealongsurface may or may not get called, but safemoveupdatedcomponent always does.

The scene component is where it gets weird. At a point, MC.MoveUpdatedComponentImpl (I'm assuming this is implementation) calls and returns UpdatedComponent->MoveComponent(.....)

From what I understand, the UpdatedComponent gets Set by whatever movement component you're using. The UpdatedComponent is a USceneComponent. 

The UpdatedComponent is the component we move and update. If this is null at startup and bAutoRegisterUpdatedComponent is true, the owning Actor's root component will automatically be set as our UpdatedComponent at startup. (From MovementComponent.h). In the context of a player, this is usually the capsule component

The USceneComponent has a transform and supports attachment, but has no rendering or collision capabilities. Useful as a 'dummy' component in the hierarchy to offset others. (From the SceneComponent.h file.)

This is all to say, that a scenecomponent has a method called MoveComponent. 

MoveComponent calls MoveComponentImpl which calls InternalSetWorldLocationAndRotation. 
"Internal helper, for use from MoveComponent().  Special codepath since the normal setters call MoveComponent." (From SceneComponent.h)

I believe SetWorldLocationAndRotation is what is ACTUALLY needed to update the transform of an object in the game world

That's the pipeline for applying input to a Character class in unreal. However, there is SetWorldLocationAndRotation that is available in the SceneComponent, that can be used for externally applying translations and rotations to the component of an actor. 

SC.SetWorldLocationAndRotation() -> SC.SetRelativeLocationAndRotation() -> SC.ConditionalUpdateComponentToWorld()

Once the movement changes are made, they're propagated to all child components, as well as its parent, and then the movement is broadcast to the game world. I didn't want to dive much deeper than this, but I believe that various house keeping things like navigation data is updated, and world bounds stuff too. 
