#!/bin/bash
player_status=$(playerctl status)
if [ "$player_status" = "Playing" ]; then
    echo " Pause"
else
    echo " Play"
fi