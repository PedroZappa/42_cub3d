#!/bin/bash

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

# Sets env vars for each function to be tested
# and increment call counter.
test_fail() {
    local env_var=$1
    local number=$2

    export "$env_var"=1
    export SYS_CALL=$number
}

### TESTS ###
# 1. Tests for failures on first call
# Clean env from previous tests
clear_sys_env_list
# Setup vars & test
for var in "${SYS_ENV_LIST[@]}"; do
    echo "Testing $var"
    test_fail $var 2
    CMD="valgrind $VAL_ARGS $EXEC $ARG"
    echo $CMD
    eval $CMD
    unset $var
done
