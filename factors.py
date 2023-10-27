#!/usr/bin/env python3
import subprocess
import sys


def check_factor(args):
    if len(args) != 3:
        count = 0
        num2 = 1

        for a in args:
            if count > 1:
                num2 *= int(a)
            count += 1
    else:
        num2 = int(args[2])

    num1 = int(args[1])
    num = args[0].replace(':', '=')

    result = 1 if num2 > num1 else 0
    if result == 1:
        num1, num2 = num2, num1

    print(f"{num}{num1}*{num2}")


if len(sys.argv) != 2:
    print('Usage: ./script.py <file>')
    sys.exit(1)
else:
    with open(sys.argv[1], 'r') as file:
        for line in file:
            result = subprocess.check_output(['factor', line.strip()]
                                             ).decode('utf-8').split()
            check_factor(result)
