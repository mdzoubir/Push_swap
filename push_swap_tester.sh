#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Configuration
PUSH_SWAP="./push_swap"
CHECKER="./checker"

# Check if push_swap exists
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}Error: push_swap not found!${NC}"
    echo "Please compile your push_swap first."
    exit 1
fi

# Check if checker exists
if [ ! -f "$CHECKER" ]; then
    echo -e "${YELLOW}Warning: checker not found!${NC}"
    echo "Download it from: https://github.com/42-cursus/push_swap_tester"
    CHECKER=""
fi

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}     PUSH_SWAP TESTER${NC}"
echo -e "${BLUE}========================================${NC}\n"

# Function to test and count operations
test_case() {
    local numbers="$1"
    local description="$2"
    local max_ops="$3"
    
    echo -e "${YELLOW}Testing: $description${NC}"
    echo "Numbers: $numbers"
    
    # Get operations
    operations=$($PUSH_SWAP $numbers)
    op_count=$(echo "$operations" | wc -l)
    
    # Check if empty output
    if [ -z "$operations" ]; then
        op_count=0
    fi
    
    echo "Operations: $op_count"
    
    # Check with checker if available
    if [ -n "$CHECKER" ]; then
        result=$(echo "$operations" | $CHECKER $numbers)
        if [ "$result" = "OK" ]; then
            echo -e "${GREEN}✓ Sorted correctly${NC}"
        else
            echo -e "${RED}✗ NOT SORTED!${NC}"
            echo "Operations used:"
            echo "$operations"
        fi
    fi
    
    # Check operation count
    if [ -n "$max_ops" ] && [ "$op_count" -le "$max_ops" ]; then
        echo -e "${GREEN}✓ Operations within limit ($op_count/$max_ops)${NC}"
    elif [ -n "$max_ops" ]; then
        echo -e "${RED}✗ Too many operations ($op_count/$max_ops)${NC}"
    fi
    
    echo ""
}

# Function to generate random numbers
generate_random() {
    local count=$1
    shuf -i 0-$((count * 10)) -n $count | tr '\n' ' '
}

echo -e "${BLUE}--- Basic Tests ---${NC}\n"

# Identity (already sorted)
test_case "1 2 3 4 5" "Already sorted (5 numbers)" 0

# Simple cases
test_case "2 1" "2 numbers" 1
test_case "3 2 1" "3 numbers reverse" 3
test_case "2 1 3" "3 numbers" 3

echo -e "${BLUE}--- Small Stack Tests (3 numbers) ---${NC}\n"
for i in {1..5}; do
    nums=$(generate_random 3)
    test_case "$nums" "Random 3 numbers #$i" 3
done

echo -e "${BLUE}--- Medium Stack Tests (5 numbers) ---${NC}\n"
for i in {1..5}; do
    nums=$(generate_random 5)
    test_case "$nums" "Random 5 numbers #$i" 12
done

echo -e "${BLUE}--- Stack Tests (100 numbers) ---${NC}\n"
for i in {1..5}; do
    nums=$(generate_random 100)
    test_case "$nums" "Random 100 numbers #$i" 700
done

echo -e "${BLUE}--- Stack Tests (500 numbers) ---${NC}\n"
for i in {1..3}; do
    nums=$(generate_random 500)
    test_case "$nums" "Random 500 numbers #$i" 5500
done

echo -e "${BLUE}--- Edge Cases ---${NC}\n"

# Single number
test_case "42" "Single number" 0

# Duplicates (should error)
echo -e "${YELLOW}Testing: Duplicates (should error)${NC}"
$PUSH_SWAP 1 2 3 2 5 2>/dev/null
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ Correctly handles duplicates${NC}\n"
else
    echo -e "${RED}✗ Should error on duplicates${NC}\n"
fi

# Invalid input
echo -e "${YELLOW}Testing: Invalid input (should error)${NC}"
$PUSH_SWAP 1 2 abc 4 2>/dev/null
if [ $? -ne 0 ]; then
    echo -e "${GREEN}✓ Correctly handles invalid input${NC}\n"
else
    echo -e "${RED}✗ Should error on invalid input${NC}\n"
fi

# Large numbers
echo -e "${YELLOW}Testing: Max int${NC}"
$PUSH_SWAP 2147483647 0 -2147483648 2>/dev/null
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ Handles INT_MAX and INT_MIN${NC}\n"
else
    echo -e "${RED}✗ Failed with INT limits${NC}\n"
fi

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}     STATISTICS SUMMARY${NC}"
echo -e "${BLUE}========================================${NC}\n"

# Run 100 tests for statistics
echo "Running 100 random tests for each size..."
echo ""

for size in 3 5 100 500; do
    total=0
    max=0
    min=999999
    
    for i in {1..100}; do
        nums=$(generate_random $size)
        ops=$($PUSH_SWAP $nums | wc -l)
        total=$((total + ops))
        [ $ops -gt $max ] && max=$ops
        [ $ops -lt $min ] && min=$ops
    done
    
    avg=$((total / 100))
    
    echo -e "${YELLOW}Size $size:${NC}"
    echo "  Average: $avg operations"
    echo "  Min: $min operations"
    echo "  Max: $max operations"
    echo ""
done

echo -e "${GREEN}Testing complete!${NC}"