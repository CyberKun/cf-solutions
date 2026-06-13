import random
import sys

def generate_test_cases():
    T = 100
    MAX_SUM_N = 200000
    MAX_A = 10**9

    # Step 1: Distribute the sum of 'n' across exactly 100 test cases
    # Start with n=1 for every test case to ensure no empty arrays
    n_array = [1] * T
    remaining_n = MAX_SUM_N - T

    # Bias the distribution so we get a few massive arrays and many small ones
    for _ in range(remaining_n):
        if random.random() < 0.15:
            # 15% of the time, add to one of the first 5 arrays (creates heavy max-load tests)
            idx = random.randint(0, 4)
        else:
            # Otherwise, distribute among the remaining 95 arrays
            idx = random.randint(5, T - 1)
        n_array[idx] += 1

    # Shuffle to hide the pattern of where the large test cases are
    random.shuffle(n_array)

    # Step 2: Generate the file content
    output = []
    output.append(str(T))

    for i in range(T):
        n = n_array[i]
        output.append(str(n))
        
        # Determine the type of test case we want to generate
        case_type = random.randint(1, 4)
        
        a = []
        if case_type == 1:
            # Pure Random
            a = [random.randint(1, MAX_A) for _ in range(n)]
            
        elif case_type == 2:
            # Maximums (Stress Test)
            a = [MAX_A for _ in range(n)]
            
        elif case_type == 3:
            # Minimums (1s and 2s)
            a = [random.randint(1, 2) for _ in range(n)]
            
        elif case_type == 4:
            # Bitwise Trickery (Powers of 2 and Powers of 2 minus 1)
            for _ in range(n):
                power = random.randint(1, 29) # 2^29 is ~5.3 * 10^8
                val = (1 << power)
                if random.random() < 0.5:
                    val -= 1
                a.append(val)
                
        # Join the array elements with a space
        output.append(" ".join(map(str, a)))

    # Step 3: Write to a file
    file_name = "input.txt"
    with open(file_name, "w") as f:
        f.write("\n".join(output) + "\n")
        
    print(f"Successfully generated {T} test cases into '{file_name}'")
    print(f"Total sum of n across all test cases: {sum(n_array)}")

if __name__ == "__main__":
    generate_test_cases()