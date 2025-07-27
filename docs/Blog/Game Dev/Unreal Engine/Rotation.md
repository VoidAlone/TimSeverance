## Problem

While attempting to create a battlefield style helicopter I ran into an issue with rotation. I first wanted to use the Character class because it has a lot of built in functionality like conditions for flying. 

In UE there are several methods that can be used to manipulate transformative properties, like rotation and location, of game objects. I had previously used a function called MoveUpdatedComponent in a Quake based movement blueprint to move my character after calculating player velocity. 

Flying objects typically rotate on the x, y, and z axis, also known as roll, pitch, and yaw. After getting input values and applying them on these axes and then passing them to the MoveUpdatedComponent, it wasn't moving.  

## Solution
#### Rotate Pawn
I tried several other movement methods, and couldn't get it.  As an alternative, I decided to experiment with a basic Pawn class.  In this class I used a function called Add Local Rotation

![[Pasted image 20220613114410.png]]

This allows the Pawn to rotate in a standard way that you would expect from jets or helicopters.  I was still confused as to why it wasn't working for the Character class though.  I found this video

#### Rotate Character
<div class=vidscale>
<iframe width="700" height="400" src="https://www.youtube.com/embed/vszgkMwahDA" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
</div>
It turns out that as far as the Character class goes, the controller is in charge of rotation (with certain settings enabled) which means that the rotation pin on the MoveUpdatedComponent will not actually rotate the character.  Instead, SetControlRotation should be used.

![[Pasted image 20220613114601.png]]

This allows the Character to rotate in the same way. The only stipulation is that while we get the control rotation, we have to add the change in rotation (similar to the add local rotation function) and then set the control rotation.

I'm sure there are several other methods to rotate the object that the player controls, like Add Controller Input.  These were just two alternatives that I found interesting that can offer more control.

## Summary

Three main ways to rotate a player

Character class - Set Control Rotation, Add Controller Input

Pawn class - Add Local Rotation

#UnrealEngine #Blueprints
