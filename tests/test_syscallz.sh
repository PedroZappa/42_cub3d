#!/usr/bin/env bash
# set -euo pipefail

# Color Codes
B=$(tput bold)
RED=$(tput setaf 1)
GRN=$(tput setaf 2)
YEL=$(tput setaf 3)
D=$(tput sgr0)

SYS_ENV_LIST=(MALLOC_FAIL)
# SYS_ENV_LIST=(MALLOC_FAIL FREE_FAIL OPEN_FAIL CLOSE_FAIL)

EXEC="./cub3D"
ARG="./maps/subject.cub"
VAL_ARGS="--leak-check=full --show-leak-kinds=all --track-origins=yes"

# Function to unset list of env vars
clear_sys_env_list() {
    for var in "${SYS_ENV_LIST[@]}"; do
        unset $var
    done
    unset "SYS_CALL"
}

# Count malloc occurrences in SRC/ folder 
# Array to store malloc locations
declare -a malloc_locations

malloc_count=0
for file in src/*.c; do
    if [[ $(basename "$file") == "test_syscallz.c" ]]; then
        continue
    fi
    line_number=0
    while IFS= read -r line; do
        ((line_number++))
        if [[ $line == *"malloc("* ]]; then
            ((malloc_count++))
            malloc_locations+=("$file:$line_number")
        fi
    done < "$file"
done

echo "${B}Total malloc() occurrences: $malloc_count${D}"

# Sets env vars for each function to be tested
# and increment call counter.
test_fail() {
    local env_var=$1
    local number=$2

    export "$env_var"=1
    export SYS_CALL=$number
}


### TESTS ###

# Clean env from previous tests
clear_sys_env_list

## MALLOC_FAIL
# Setup vars & Test for failures on each malloc call
for ((i=0; i < malloc_count; i++)); do
    call_number=$((i + 1))
    location=${malloc_locations[$i]}
    file=$(echo $location | cut -d':' -f1)
    line=$(echo $location | cut -d':' -f2)
    
    echo "${B}Testing ${YEL}MALLOC_FAIL${D} for call number ${GRN}$call_number${D}"
    echo "On file ${GRN}$file${D} at line ${GRN}$line${D}"
    
    test_fail MALLOC_FAIL $call_number
    CMD="valgrind $VAL_ARGS $EXEC $ARG"
    echo $CMD
    eval $CMD
    clear_sys_env_list
done
