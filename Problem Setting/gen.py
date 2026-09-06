import sys
import random

def main():
    if len(sys.argv) < 5:
        sys.exit(1)

    random.seed(sys.argv[1])
    t = int(sys.argv[2])
    sum_n = int(sys.argv[3])
    test_type = sys.argv[4]

    print(t)

    ns = [1] * t
    remaining_n = sum_n - t
    for _ in range(remaining_n):
        ns[random.randint(0, t - 1)] += 1

    for n in ns:
        k = random.randint(1, n)
        
        if test_type == "small_k":
            k = random.randint(1, min(n, 5))
        elif test_type == "large_k":
            k = random.randint(max(1, n - 5), n)
            
        print(f"{n} {k}")
        
        a = []
        for _ in range(n):
            if test_type == "missing_zero":
                # Never generates 0, so MEX is always 0
                a.append(random.randint(1, n))
            elif test_type == "binary":
                # Only 0s and 1s
                a.append(random.randint(0, 1))
            elif test_type == "dense":
                # High chance of contiguous numbers starting from 0
                a.append(random.randint(0, min(n, 10)))
            else:
                # Completely random
                a.append(random.randint(0, n))
        
        print(*(a))

if __name__ == "__main__":
    main()