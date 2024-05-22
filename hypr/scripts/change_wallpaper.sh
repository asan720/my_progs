#!/bin/bash

# Array of wallpapers
wallpapers=(
    "/home/asan/Downloads/Telegram Desktop/20240327_170456.jpg"
    "/home/asan/Downloads/Telegram Desktop/5O9onp1elh8.jpg"
)

# Get the number of wallpapers
num_wallpapers=${#wallpapers[@]}

# Get a random index
index=$(($RANDOM % $num_wallpapers))

# Change the wallpaper
hyprpaper -c "wallpaper=eDP-1,${wallpapers[$index]}"
