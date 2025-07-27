
### FPS Template

The FPS Template consists of a Character, a Weapon Pickup, a Weapon Component, and a Projectile.

#### Projectile

Just responsible for impulse logic for pushback, and qualities related to the "bullet" itself. 

#### Weapon Component

Weapon Component in their example inherits from the SkeletalMeshComponent. This means that the Weapon is both a Weapon and a SkeletalMeshComp as well.

It has two responsibilities:

1) Spawns a skeletal mesh (the gun asset) and attaches it to the Character Skeletal Mesh hand Socket

2) Spawns a projectile to shoot.

#### Weapon Pickup

This is responsible for logic related to picking up weapons on the ground.

It also has logic for dynamically adding a component to the character at runtime, and then binding the Weapon Component to it.

### My Implementation

#### Projectile

Create a baseclass for many types of projectiles. This could be shotgun spreads, sniper bullets, swords, etc.

Compose (or not) with particles for effects

BaseClass will have components for Collider, Mesh, Physics, Particles (Might be from a Spawner)

#### Weapon Component

Create a baseclass for Weapon Components. Rather than inheriting, compose the Weapon with a SkeletalMeshComponent.

Have behavior for spawning projectiles (shooting)

#### Weapon Data

Weapon Table that different weapons/parts refer to

- Reload Speed
- Fire Rate
- Draw Time
- Blast Radius
- Mag Size
- Range
- Fire Mode
- Impact
- Handling
- Stability
- Aim Assist
- Recoil
- Mag Size
- Rarity
- Element

#### Skeletal Mesh Component

Create a class for spawning the skeletal mesh and joining to the socket of the PlayerCharacter reference (passed by the invoker even)

#### Pickup

Have a base Pickup class so that we can extend this behavior to things beyond Weapons.

Subclass can be weapon pickup which isn't responsible for directly instantiating a weapon, but for storing data about the weapon.

Subclass can also be for items like armor or consumables.

Subclass for RNG item? That way we can have designated drops for weapons and armor and such, but also have a loot system.

#### Item Spawner

The pickup class previously was responsible for the combined logic of "picking up" and "spawning".

Item spawner will now refer to data stored either in the gamemode or on the Character (probably easiest). It'll have a reference to items, their type, and be able to initialize and assign weapons, items, and armor.

## Weapon Ideas

### Guns

#### Gravity Weapons

##### Repulsor

Description: Gravity Weapon that pushes objects and players away

ToDo:
- Add despawn (distance based) 
- Add walls should despawn it
- Less strength over time
- Shouldn't shove objects through wall
- Cone should be bigger 

###### Velocity Bugs
- Velocity is being imparted on the character. When jumping, velocity is applied upwards, when falling, velocity is applied downward
- Added destruction logic so that if an object is not simulating physics, the projectile will destroy on hit. When looking straight down, the projectile hits the player which causes it to despawn and only apply upward velocity? This is giving rocket jump functionality


##### Vortex

##### Traveler

#### Standard

SMG

- Vector
- MP7
- Mac 11

Rifle

DMR

Sniper

#### Charge Weapons

Fusion Rifle

Linear Fusion

#### Energy Weapons

Bee Gun

Plasma Gun

Volt Gun

Gauss Beam

#### Explosive Weapons

Grenade Launcher

RPG