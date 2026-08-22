*This project has been created as part of the 42 curriculum by fbui-min.*

# miniRT

A small ray tracer written in C using MLX42. The project renders simple 3D scenes from a textual `.rt` configuration file and displays the result in a graphical window.

## Description

The goal of miniRT is to build a basic ray-tracing renderer from first principles. For every pixel, the program creates a camera ray, calculates intersections with scene objects, determines the visible surface, computes lighting, and writes the resulting color to an MLX42 image.

The mandatory renderer supports:

- Ambient lighting.
- One point light.
- A movable camera with configurable field of view.
- Spheres.
- Planes.
- Cylinders with configurable diameter and height.
- Object translations and rotations.
- Diffuse lighting and hard shadows.
- Multiple objects of the same type.
- Clean exit through `ESC` and the window close button.

The implementation uses homogeneous coordinates: points use `w = 1` and vectors use `w = 0`. This distinguishes positions from directions during transformations and lighting calculations.

## Requirements

- A C compiler supporting the project Makefile.
- `make`.
- Math library support.
- MLX42 and its required dependencies.
- A Linux environment supported by the project setup.

## Installation

Clone the repository and enter the project directory:

```bash
git clone <repository-url>
cd miniRT
```

Build the mandatory target:

```bash
make
```

The executable is named:

```text
miniRT
```

Additional Makefile commands:

```bash
make clean
make fclean
make re
```

`make clean` removes object files. `make fclean` removes object files and the executable. `make re` performs a clean rebuild.

## Usage

Run the program with exactly one scene file argument:

```bash
./miniRT scenes/sphere.rt
```

The scene filename must end with `.rt`. A valid scene must contain exactly one ambient-light declaration, one camera declaration, one light declaration, and at least one object.

Press `ESC` or click the window close button to exit cleanly.

## Scene format

Elements may appear in any order. Values can be separated by one or more spaces.

### Ambient lighting

```text
A ratio R,G,B
```

- `ratio`: ambient-light ratio in the range `[0.0, 1.0]`.
- `R,G,B`: color components in the range `[0, 255]`.

Example:

```text
A 0.10 255,255,255
```

### Camera

```text
C x,y,z dx,dy,dz FOV
```

- `x,y,z`: camera position.
- `dx,dy,dz`: normalized camera orientation vector.
- `FOV`: horizontal field of view in degrees, in the range `(0, 180)`.

Example:

```text
C 0,0,-20 0,0,1 60
```

### Light

```text
L x,y,z brightness R,G,B
```

- `x,y,z`: point-light position.
- `brightness`: light ratio in the range `[0.0, 1.0]`.
- `R,G,B`: light color in the range `[0, 255]`.

Example:

```text
L -6,8,-10 0.9 255,255,255
```

### Sphere

```text
sp x,y,z diameter R,G,B
```

Example:

```text
sp 0,0,4 5 220,50,50
```

### Plane

```text
pl x,y,z nx,ny,nz R,G,B
```

- `x,y,z`: a point on the plane.
- `nx,ny,nz`: normalized plane normal.
- `R,G,B`: plane color.

Example:

```text
pl 0,-3,0 0,1,0 80,80,80
```

### Cylinder

```text
cy x,y,z ax,ay,az diameter height R,G,B
```

- `x,y,z`: cylinder center.
- `ax,ay,az`: normalized cylinder axis.
- `diameter`: cylinder diameter.
- `height`: cylinder height.
- `R,G,B`: cylinder color.

Example:

```text
cy 0,0,5 0,1,0 4 8 50,180,80
```

## Example scene

```rt
A 0.08 255,255,255
C 0,2,-18 0,-0.10,1 60
L -8,10,-8 0.9 255,255,255

pl 0,-3,0 0,1,0 70,70,70
sp -2,0,4 4 220,50,50
cy 3,0,6 0,1,0 3 8 50,180,80
```

## Validation scenes

The repository includes scene files for testing:

- Basic sphere, plane, and cylinder rendering.
- Multiple spheres and cylinders.
- Object translations and rotations.
- Cameras positioned on the X, Y, and Z axes.
- Arbitrary camera positions.
- Side lighting.
- Object shadows.
- Complex intersecting scenes.

Invalid scene files should be rejected with an error and a non-zero exit status.

## Technical choices

### Ray generation

The camera uses a view transformation to convert rays from camera space into world space. The camera orientation is normalized before constructing the camera basis.

When the camera points almost exactly along the Y axis, the normal world-up vector `(0, 1, 0)` is parallel to the camera direction. In that case, the renderer uses `(0, 0, 1)` as a fallback reference-up vector so the cross product remains valid.

### Object transformations

Objects are intersected in object space by transforming the incoming ray with the inverse object transformation. The resulting normal is transformed back using the inverse-transpose matrix and normalized.

Cylinder dimensions are represented by scaling the default object-space cylinder. A MiniRT diameter is converted to a radius before applying the transformation.

### Lighting

The renderer combines ambient and diffuse illumination. It calculates the light direction from the surface point to the point light, tests whether another object blocks that path, and applies hard shadows where appropriate.

## Testing

Build twice to check that the second build does not unnecessarily relink:

```bash
make
make
```

Run a valid scene:

```bash
./miniRT scenes/basic.rt
```

Test invalid input:

```bash
./miniRT scenes/invalid_rgb.rt
echo $?
./miniRT scenes/basic.txt
echo $?
```

The invalid cases should print an error and exit without opening a rendering window.

## Resources

- The official 42 `miniRT` subject, especially the mandatory-part scene format and requirements.
- Jamis Buck, *The Ray Tracer Challenge*. This book was used as the main guide for rays, tuples, matrices, transformations, intersections, normals, Phong lighting, camera transforms, and shadows.
- MLX42 documentation for window creation, image management, hooks, event loops, and cleanup.
- The C standard library and math-library documentation for file handling, memory management, parsing support, and mathematical functions.

### AI usage

AI tools were used as a learning and review aid during development. They helped explain ray-tracing mathematics, homogeneous coordinates, camera-basis edge cases, parser validation, lighting behavior, shadow tests, scene-file design, debugging strategies, and README organization.

All generated suggestions were reviewed, adapted to this codebase, compiled, and tested by the project authors. AI was not treated as a replacement for understanding the implementation; the author remains responsible for the submitted code.

## Author

Created as part of the 42 curriculum by `fbui-min`.


grep -Rnw . -e "world_add_object"
grep -Rnw --include="*.c" --include="*.h" . -e "world_add_object"

git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build
cmake --build build -j4

(https://github.com/42Paris/minilibx-linux/actions/workflows/ci.yml/badge.svg)](https://github.com/42Paris/minilibx-linux/actions/workflows/ci.yml)

https://github.com/codam-coding-college/MLX42

A 3D object has three local directions:
X → left/right
Y → up/down
Z → forward/back
A rotation tells you where all three local axes end up.

That's called an orthonormal basis:
orthogonal = perpendicular
normal = length 1
Magnitude checks that the direction isn't zero; normalization removes its length so it can be used as a clean unit axis.