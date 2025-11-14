def sum_of_digits(n):
    if n == 0:
        return 0
    return abs(n % 10) + sum_of_digits(n // 10)
