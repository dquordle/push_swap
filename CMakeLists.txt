cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap bonuses/push_swap_bonus.c bonuses/utils_bonus.c bonuses/actions_bonus.c bonuses/merge_sort_bonus.c)

target_link_libraries(push_swap /Users/dquordle/CLionProjects/push_swap/libftV3/libft.a)
target_link_libraries(push_swap /Users/dquordle/CLionProjects/push_swap/bonuses/libmlx.a)
target_link_libraries(push_swap "-framework OpenGL")
target_link_libraries(push_swap "-framework AppKit")