int main(int argc, char **argv)
{
    t_program prog;
    
    // 1. Parse scene file (create t_scene)
    parse_scene_file(argv[1], &prog.scene);
    
    // 2. Build renderable world (t_world, t_camera)
    build_world_from_scene(&prog.scene, &prog.world, &prog.camera);
    
    // 3. Allocate canvas memory
    prog.canvas = canvas_new(prog.camera.h_size, prog.camera.v_size);
    // → 87,500 pixels allocated
    
    // 4. Initialize rendering
    init_render(&prog);
    // → Sets up ray tracing engine with camera and world
    
    // 5. Render to canvas
    render_minirt(&prog);
    // → Ray tracing happens here, filling canvas.pixels
    
    // 6. Display to window
    mlx_put_image_to_window(...);
    // → Canvas pixels copied to MLX image buffer
    
    // 7. Event loop
    mlx_loop(prog.mlx.mlx);
}
(https://github.com/42Paris/minilibx-linux/actions/workflows/ci.yml/badge.svg)](https://github.com/42Paris/minilibx-linux/actions/workflows/ci.yml)