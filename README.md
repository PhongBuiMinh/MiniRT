src/
├── main.c
│
├── render/
│   ├── render.c
│   ├── canvas.c
│   ├── color.c
│   └── light.c
│
├── world/
│   ├── world.c
│   ├── objects.c
│   └── hit.c
│
├── tracing/
│   ├── rays.c
│   ├── intersect.c
│   ├── intersect_helper.c
│   ├── intersect_manipulation.c
│   └── normal_at.c
│
├── math/
│   ├── tuples.c
│   ├── matrices.c
│   ├── transformations.c
│   ├── geometry.c
│   └── helper_math.c

grep -Rnw . -e "world_add_object"
grep -Rnw --include="*.c" --include="*.h" . -e "world_add_object"

git clone https://github.com/codam-coding-college/MLX42.git
cd MLX42
cmake -B build
cmake --build build -j4

(https://github.com/42Paris/minilibx-linux/actions/workflows/ci.yml/badge.svg)](https://github.com/42Paris/minilibx-linux/actions/workflows/ci.yml)

https://github.com/codam-coding-college/MLX42