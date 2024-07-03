def is_valid_age(age):
    if 18 <= age <= 60:
        return "Valid"
    else:
        return "Invalid"

# Define test cases
test_cases = [
    (18, "Valid"),  # Minimum boundary
    (17, "Invalid"),  # Just below minimum boundary
    (19, "Valid"),  # Just above minimum boundary
    (59, "Valid"),  # Just below maximum boundary
    (60, "Valid"),  # Maximum boundary
    (61, "Invalid")  # Just above maximum boundary
]

# Run test cases
for i, (age, expected) in enumerate(test_cases):
    result = is_valid_age(age)
    assert result == expected, f"Test case {i+1} failed: age={age}, expected={expected}, got={result}"
    print(f"Test case {i+1} passed: age={age}, expected={expected}, got={result}")

print("All test cases passed!")
