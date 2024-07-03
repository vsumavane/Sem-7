# Define the function
def is_valid_age(age):
    if 18 <= age <= 60:
        return "Valid"
    else:
        return "Invalid"

# Define test cases using Equivalence Class Partitioning
test_cases = [
    (30, "Valid"),  # Valid range middle value
    (17, "Invalid"),  # Just below the valid range
    (10, "Invalid"),  # Well below the valid range
    (61, "Invalid"),  # Just above the valid range
    (70, "Invalid"),  # Well above the valid range
]

# Run test cases
for i, (age, expected) in enumerate(test_cases):
    result = is_valid_age(age)
    assert result == expected, f"Test case {i+1} failed: age={age}, expected={expected}, got={result}"
    print(f"Test case {i+1} passed: age={age}, expected={expected}, got={result}")

print("All test cases passed!")