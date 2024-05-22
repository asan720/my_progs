#!/bin/bash
CITY="YourCity"
API_KEY="YourAPIKey"
weather=$(curl -s "http://api.openweathermap.org/data/2.5/weather?q=$CITY&appid=$API_KEY&units=metric")
temperature=$(echo $weather | jq ".main.temp")
condition=$(echo $weather | jq -r ".weather[0].description")
echo "Weather: $temperature°C, $condition"
