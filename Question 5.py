def evaluate_polynomial(coefficients, x):
    result = 0
    for i, coefficient in enumerate(coefficients):
        result += coefficient * (x ** i)
    return result

# Example polynomial: f(x) = 4x^2 + 2x + 9
coefficients = [4, 2, 9]
x = 5
result = evaluate_polynomial(coefficients, x)
print("f({}) = {}".format(x, result))
