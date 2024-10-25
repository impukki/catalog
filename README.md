The input consists of:
Number of roots (n): Total number of points provided.
Minimum roots required (k): The minimum number of points needed to determine the polynomial's coefficients.
Roots: Each root is given in a specific format:
A base (e.g., base 10, base 2)
A value which is encoded in that base
For each root:
Convert the encoded value from its specified base to a decimal integer.
For example, if the base is 2 and the value is "111", you convert "111" from binary to decimal, which equals 7.
Store these decoded values as y values.
The x values are typically just the indices of the roots:
For example, if you have four roots, your 
x values would be [1, 2, 3, 4].
To find the constant term c
Use Lagrange interpolation or another interpolation method:
This method allows you to compute a polynomial that passes through the given points.
The constant term c can be found by evaluating this polynomial at x=0.
After calculating c, print or return this value as your result.
