#!/bin/bash

# Получаем текущую раскладку клавиатуры
layout=$(swaymsg -t get_inputs | jq -r '.[] | select(.type == "keyboard") | .xkb_active_layout_name')

# Если раскладка пустая, задаем значение по умолчанию
if [ -z "$layout" ]; then
    layout="Unknown"
fi

# Форматируем вывод
echo -e "{\"text\":\"$layout\", \"tooltip\":\"Current keyboard layout: $layout\", \"class\":\"keyboard-layout\"}"

