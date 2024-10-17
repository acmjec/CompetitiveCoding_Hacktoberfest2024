

```markdown
## Coding Problem: FizzBuzz

**Problem Statement:**

Write a program that prints the numbers from 1 to 100. But for multiples of three, print "Fizz" instead of the number, and for the multiples of five, print "Buzz". For numbers which are multiples of both three and five, print "FizzBuzz".

**Example Output:**
```
1
2
Fizz
4
Buzz
Fizz
7
8
Fizz
Buzz
11
Fizz
13
14
FizzBuzz
...
```

### Solution

Here is a simple solution in Python:

```python
def fizzbuzz(n):
    for i in range(1, n + 1):
        if i % 3 == 0 and i % 5 == 0:
            print("FizzBuzz")
        elif i % 3 == 0:
            print("Fizz")
        elif i % 5 == 0:
            print("Buzz")
        else:
            print(i)

# Call the function
fizzbuzz(100)
```

### Explanation

1. We define a function `fizzbuzz` that takes an integer `n` as an argument.
2. We loop through all numbers from 1 to `n`.
3. For each number, we check:
   - If it is divisible by both 3 and 5, we print "FizzBuzz".
   - If it is only divisible by 3, we print "Fizz".
   - If it is only divisible by 5, we print "Buzz".
   - Otherwise, we print the number itself.
```

