# Blender -> Godot 3D Design Bible v1.0

Core rule: 1 Blender Unit = 1 meter, 1 Godot Unit = 1 meter, export scale = 1.0.

## World Scale

| Metric | Value |
|---|---:|
| Blender Unit | 1 m |
| Godot Unit | 1 m |
| Export Scale | 1.0 |
| Model Grid | 0.5 m |
| Large Modules | 2 / 4 / 8 / 16 m |

## Human Ref

| Metric | Value |
|---|---:|
| Height | 1.80 m |
| Eye Height | 1.68 m |
| Shoulder | 0.48 m |
| Arm Span | 1.80 m |
| Reach | 2.30 m |

## Controller

| Metric | Value |
|---|---:|
| Capsule H | 1.80 m |
| Capsule R | 0.30 m |
| Crouch H | 1.20 m |
| Step H | 0.25 m |
| Max Slope | 45 deg |
| Stand Jump | 1.30 m |
| Long Jump | 3.5-4.0 m |

## Architecture

| Metric | Value |
|---|---:|
| Interior Wall | 3.0 m |
| Exterior Wall | 3.5-4.0 m |
| Door | 1.0 x 2.2 m |
| Double Door | 2.0 x 2.2 m |
| Window Sill | 0.9 m |
| Hall Min | 2.0 m |
| Hall Comfy | 3.0 m |
| Cover | 0.9 m |

## Stairs / Ramps

| Metric | Value |
|---|---:|
| Rise | 0.18 m |
| Run | 0.30 m |
| Step Limit | 0.25 m |
| Collision | Ramp |
| Visual | Steps |

## Pivots

| Metric | Value |
|---|---:|
| Wall | Bottom center |
| Floor | Center |
| Pillar | Bottom center |
| Door | Hinge |
| Window | Bottom center |
| Pipe | Center |
| Prop | Bottom center |

## Hierarchy

| Metric | Value |
|---|---:|
| L0 | Primitives |
| L1 | Modules |
| L2 | Assemblies |
| L3 | Landmarks |
| Rule | Do not mutate lower-level modules for higher-level problems |

## Collision

| Metric | Value |
|---|---:|
| Stairs | Ramp |
| Rubble | Simple hull |
| Pipes | Capsules/boxes |
| Rocks | Convex hull |
| Buildings | Primitive volumes |

## Scale Categories

| Metric | Value |
|---|---:|
| 0.1 m | Props |
| 1 m | Furniture |
| 10 m | Rooms |
| 100 m | Buildings |
| 1 km | Districts |
| 10 km | Landmarks |

## Infrastructure

| Metric | Value |
|---|---:|
| Pipe | Straight / Bend / Tee / Valve |
| Aqueduct | Pier + Arch x N + Cap |
| Bridge | Abutment + Span x N + Railings |

## Collections

`Reference/`, `Primitives/`, `Architecture/`, `Infrastructure/`, `Nature/`, `Props/`, `Furniture/`, `Lighting/`, `Materials/`, `Characters/`, `Collision/`

## Core Materials

Concrete, Brick, Stone, Wood, Metal, Glass, Dirt, Grass, Sand, Water, Emissive

## Naming

```
wall_2x3
wall_corner_inner
floor_4x4
pillar_round
arch_large
beam_4m
pipe_straight
pipe_bend_90
pipe_t
stair_18cm
```

Rules: lowercase, snake_case, no spaces, metric dimensions where useful.

## Megastructures

- Scale through composition, not giant cubes.
- Door -> Room -> Building -> District -> Megastructure
- Large primitives: support columns, bridge spans, bulkheads, utility shafts, trusses, cable towers, pipe networks, foundation blocks.

## Design Philosophy

1. Gameplay metrics come first.
2. World scale is always metric.
3. Modules are reusable forever.
4. Build upward through composition.
5. Collision serves gameplay, not visuals.
6. Keep one Blender -> Godot pipeline.
7. Think in systems, not one-off assets.

## Reference Scene Checklist

- [ ] 1.80 m mannequin
- [ ] Character capsule
- [ ] Door
- [ ] Staircase
- [ ] Hallway
- [ ] Wall modules
- [ ] Desk & chair
- [ ] Floor grid
- [ ] Lighting reference
- [ ] Material spheres
- [ ] Export test object
