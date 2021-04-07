cmake_minimum_required(VERSION 3.17)
project(push_swap C)

set(CMAKE_C_STANDARD 99)

add_executable(push_swap srcs/checker.c srcs/push_swap.c srcs/utils.c srcs/actions.c srcs/merge_sort.c)

target_link_libraries(push_swap /Users/dquordle/CLionProjects/push_swap/libftV3/libft.a)