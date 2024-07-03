decision_table = [
    {"credit_score": "Good", "income_level": "High", "collateral": "Yes", "expected_result": "Approve loan"},
    {"credit_score": "Good", "income_level": "High", "collateral": "No", "expected_result": "Approve loan"},
    {"credit_score": "Good", "income_level": "Low", "collateral": "Yes", "expected_result": "Approve loan"},
    {"credit_score": "Good", "income_level": "Low", "collateral": "No", "expected_result": "Deny loan"},
    {"credit_score": "Bad", "income_level": "High", "collateral": "Yes", "expected_result": "Approve loan"},
    {"credit_score": "Bad", "income_level": "High", "collateral": "No", "expected_result": "Deny loan"},
    {"credit_score": "Bad", "income_level": "Low", "collateral": "Yes", "expected_result": "Deny loan"},
    {"credit_score": "Bad", "income_level": "Low", "collateral": "No", "expected_result": "Deny loan"},
]

# Step 2: Define a function that simulates the loan approval process
def loan_approval_system(credit_score, income_level, collateral):
    if credit_score == "Good" and (income_level == "High" or collateral == "Yes"):
        return "Approve loan"
    elif credit_score == "Bad" and income_level == "High" and collateral == "Yes":
        return "Approve loan"
    else:
        return "Deny loan"

# Step 3: Generate and execute test cases
def run_test_cases(decision_table):
    for i, test_case in enumerate(decision_table):
        credit_score = test_case["credit_score"]
        income_level = test_case["income_level"]
        collateral = test_case["collateral"]
        expected_result = test_case["expected_result"]
        
        # Get the actual result from the loan approval system
        actual_result = loan_approval_system(credit_score, income_level, collateral)
        
        # Check if the actual result matches the expected result
        if actual_result == expected_result:
            print(f"Test Case {i+1} PASSED")
        else:
            print(f"Test Case {i+1} FAILED: expected {expected_result} but got {actual_result}")

# Run the test cases
run_test_cases(decision_table)