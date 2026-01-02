#!/bin/bash

PUSH_SWAP=./push_swap
CHECKER=./checker_linux # Change if needed
ITERATIONS=100

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Thresholds
LIMIT_100=700
LIMIT_500=5500

function run_test() {
    COUNT=$1
    LIMIT=$2
    TOTAL_OPS=0
    MAX_OPS=0
    MIN_OPS=100000
    FAIL=0

    echo -e "\n${BLUE}=== RUNNING $ITERATIONS TESTS WITH $COUNT NUMBERS ===${NC}"
    echo -e "Target: < $LIMIT instructions"

    for ((i=1; i<=ITERATIONS; i++)); do
        # Generate random numbers (Linux shuf)
        ARG=$(shuf -i 1-1000 -n $COUNT | tr '\n' ' ')
        
        # Run Push Swap
        OPS=$($PUSH_SWAP $ARG | wc -l)
        RESULT=$($PUSH_SWAP $ARG | $CHECKER $ARG)

        # Check Validity
        if [ "$RESULT" != "OK" ]; then
            echo -e "${RED}[FAIL]${NC} Test $i: Sorting Failed (KO)"
            echo "Args: $ARG"
            exit 1
        fi

        # Update Stats
        TOTAL_OPS=$((TOTAL_OPS + OPS))
        if [ $OPS -gt $MAX_OPS ]; then MAX_OPS=$OPS; fi
        if [ $OPS -lt $MIN_OPS ]; then MIN_OPS=$OPS; fi

        # Check Threshold
        if [ $OPS -gt $LIMIT ]; then
            echo -e "${RED}[FAIL]${NC} Test $i: $OPS ops (Limit: $LIMIT)"
            FAIL=$((FAIL + 1))
        else
            # Simple progress bar
            echo -n "."
        fi
    done

    AVG=$((TOTAL_OPS / ITERATIONS))

    echo -e "\n"
    echo -e "------------------------------------------------"
    if [ $FAIL -eq 0 ]; then
        echo -e "${GREEN}STATUS: PASSED (100/100)${NC}"
    else
        echo -e "${RED}STATUS: FAILED ($FAIL/$ITERATIONS spikes)${NC}"
    fi
    echo -e "------------------------------------------------"
    echo -e "Average: $AVG"
    echo -e "Min:     $MIN_OPS"
    echo -e "Max:     $MAX_OPS"
    
    # Grading Check
    if [ $COUNT -eq 100 ]; then
        if [ $AVG -lt 700 ]; then echo -e "Grade:   ${GREEN}5/5${NC}"; else echo -e "Grade:   ${RED}Risk${NC}"; fi
    elif [ $COUNT -eq 500 ]; then
        if [ $AVG -lt 5500 ]; then echo -e "Grade:   ${GREEN}5/5${NC}"; else echo -e "Grade:   ${RED}Risk${NC}"; fi
    fi
}

# --- THE WORST CASE CHECK ---
echo -e "${YELLOW}=== CHECKING WORST CASE (REVERSE SORTED) ===${NC}"
# 100 Reverse
ARG_REV_100=$(seq 100 -1 1 | tr '\n' ' ')
OPS_REV_100=$($PUSH_SWAP $ARG_REV_100 | wc -l)
echo -n "100 Reverse: $OPS_REV_100 ops... "
if [ $OPS_REV_100 -lt 700 ]; then echo -e "${GREEN}OK${NC}"; else echo -e "${RED}KO${NC}"; fi

# 500 Reverse
ARG_REV_500=$(seq 500 -1 1 | tr '\n' ' ')
OPS_REV_500=$($PUSH_SWAP $ARG_REV_500 | wc -l)
echo -n "500 Reverse: $OPS_REV_500 ops... "
if [ $OPS_REV_500 -lt 5500 ]; then echo -e "${GREEN}OK${NC}"; else echo -e "${RED}KO${NC}"; fi

# --- RUN THE LOOPS ---
run_test 100 $LIMIT_100
run_test 500 $LIMIT_500