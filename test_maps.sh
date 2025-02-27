#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

echo "Testing valid maps..."
for map in maps/valid/*.ber; do
    echo -n "Testing $map: "
    ./so_long "$map"
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}KO${NC}"
    fi
done

echo -e "\nTesting invalid maps..."
for map in maps/invalid/*.ber; do
    echo -n "Testing $map: "
    ./so_long "$map"
    if [ $? -eq 1 ]; then
        echo -e "${GREEN}OK${NC}"
    else
        echo -e "${RED}KO${NC}"
    fi
done 