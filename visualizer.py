import sys
import subprocess
import time
import os

# Set of valid operations to parse from output
VALID_OPS = {'sa', 'sb', 'ss', 'pa', 'pb', 'ra', 'rb', 'rr', 'rra', 'rrb', 'rrr'}

def print_stacks(a, b, op, step):
    # Determine height
    h = max(len(a), len(b))
    
    # ANSI Colors
    RED = '\033[91m'
    GREEN = '\033[92m'
    RESET = '\033[0m'
    
    os.system('clear')
    print(f"Step {step}: {GREEN}{op}{RESET}")
    print("-" * 50)
    print(f"{'Stack A':<20} | {'Stack B':<20}")
    print("-" * 50)
    
    for i in range(h):
        val_a = str(a[i]) if i < len(a) else ""
        val_b = str(b[i]) if i < len(b) else ""
        print(f"{val_a:<20} | {val_b:<20}")
    
    print("-" * 50)
    # Pause for animation effect
    time.sleep(0.1)

def run_visualizer(arg_str):
    # Parse initial numbers
    try:
        a = [int(x) for x in arg_str.split()]
    except ValueError:
        print("Error: Arguments must be integers.")
        return
    b = []
    
    target_sorted = sorted(a)

    print("Running push_swap...")
    # Run push_swap and capture output
    try:
        proc = subprocess.Popen(['./push_swap'] + arg_str.split(), stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        stdout, stderr = proc.communicate()
    except FileNotFoundError:
        print("Error: ./push_swap not found. Compile it first.")
        return

    # Filter only valid operations (ignores debug prints)
    ops = [line.strip() for line in stdout.split('\n') if line.strip() in VALID_OPS]
    
    print(f"captured {len(ops)} operations. Starting visualization in 2 seconds...")
    time.sleep(2)
    
    step = 0
    print_stacks(a, b, "START", step)
    
    for op in ops:
        step += 1
        if op == 'sa' and len(a) > 1:
            a[0], a[1] = a[1], a[0]
        elif op == 'sb' and len(b) > 1:
            b[0], b[1] = b[1], b[0]
        elif op == 'ss':
            if len(a) > 1: a[0], a[1] = a[1], a[0]
            if len(b) > 1: b[0], b[1] = b[1], b[0]
        elif op == 'pa' and b:
            a.insert(0, b.pop(0))
        elif op == 'pb' and a:
            b.insert(0, a.pop(0))
        elif op == 'ra' and len(a) > 1:
            a.append(a.pop(0))
        elif op == 'rb' and len(b) > 1:
            b.append(b.pop(0))
        elif op == 'rr':
            if len(a) > 1: a.append(a.pop(0))
            if len(b) > 1: b.append(b.pop(0))
        elif op == 'rra' and len(a) > 1:
            a.insert(0, a.pop())
        elif op == 'rrb' and len(b) > 1:
            b.insert(0, b.pop())
        elif op == 'rrr':
            if len(a) > 1: a.insert(0, a.pop())
            if len(b) > 1: b.insert(0, b.pop())
            
        print_stacks(a, b, op, step)

    if a == target_sorted and not b:
        print("\n\033[92mOK: Stack sorted!\033[0m")
    else:
        print("\n\033[91mKO: Not sorted properly.\033[0m")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        # Default test case if none provided
        args = "10 42 5 1 9"
    else:
        args = sys.argv[1]
    
    run_visualizer(args)
