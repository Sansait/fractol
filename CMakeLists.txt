cmake_minimum_required(VERSION 3.10)
project(fractol C)

set(CMAKE_C_STANDARD 99)

add_executable(fractol
        srcs/main.c
        srcs/event.c
        srcs/mandelbrot.c
        srcs/display.c
        srcs/argument.c
        srcs/movement.c
        srcs/julia.c srcs/burning_ship.c)

target_link_libraries(fractol "/usr/local/lib/libmlx.a")
target_link_libraries(fractol "-framework AppKit")
target_link_libraries(fractol "-framework OpenGL")
target_link_libraries(fractol "~/dev/fractol/libft/libft.a")