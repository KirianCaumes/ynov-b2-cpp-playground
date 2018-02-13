cmake_minimum_required(VERSION 3.9)
project(RPG)

set(CMAKE_CXX_STANDARD 11)

add_executable(RPG main.cpp Shop.h Weapon.cpp Weapon.h WeaponType.cpp WeaponType.h Player.cpp Player.h)