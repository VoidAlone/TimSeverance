## Problem
While working on the helicopter I finally got it to [[Rotation | rotate]], but found I could only pitch and roll from -90 to 90 degrees.  For flight, we generally want the ability to rotate a full 360 degrees in any direction.

## Solution (It's not [[Gimbal Lock]])
By default, the player camera is managed by the camera manager, which is managed by the controller (as far as I understand anyways)

So what you want to do is create a new camera manager. You may also need to create a new controller and set it as your default controller. Anyway, I chose the PlayerCameraManager class but I haven't experimented with its subclasses yet.

![[Pasted image 20220621185220.png]]

In your new PlayerCameraManager you can set your min and max settings for view pitch, roll, and yaw.  To get a full rotation, set the min to 0 and the max to ~360.

![[Pasted image 20220621184927.png]]

Finally, in your Controller class, set your Player Camera Manager Class to the new camera manager that you created.

![[Pasted image 20220621184731.png]]

#UnrealEngine #Blueprints