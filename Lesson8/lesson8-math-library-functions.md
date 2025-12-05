# Programming 1
---

# Lesson 8

## C Math Library Functions

| Function | Description | Example |
|----------|-------------|---------|
| `sqrt(x)` | square root of *x* | `sqrt(900.0)` is `30.0`<br>`sqrt(9.0)` is `3.0` |
| `cbrt(x)` | cube root of *x* (C99 and C11 only) | `cbrt(27.0)` is `3.0`<br>`cbrt(-8.0)` is `-2.0` |
| `exp(x)` | exponential function *e<sup>x</sup>* | `exp(1.0)` is `2.718282`<br>`exp(2.0)` is `7.389056` |
| `log(x)` | natural logarithm of *x* (base *e*) | `log(2.718282)` is `1.0`<br>`log(7.389056)` is `2.0` |
| `log10(x)` | logarithm of *x* (base 10) | `log10(1.0)` is `0.0`<br>`log10(10.0)` is `1.0`<br>`log10(100.0)` is `2.0` |
| `fabs(x)` | absolute value of *x* as a floating-point number | `fabs(13.5)` is `13.5`<br>`fabs(0.0)` is `0.0`<br>`fabs(-13.5)` is `13.5` |
| `ceil(x)` | rounds *x* to the smallest integer not less than *x* | `ceil(9.2)` is `10.0`<br>`ceil(-9.8)` is `-9.0` |
| `floor(x)` | rounds *x* to the largest integer not greater than *x* | `floor(9.2)` is `9.0`<br>`floor(-9.8)` is `-10.0` |
| `pow(x, y)` | *x* raised to power *y* (*x<sup>y</sup>*) | `pow(2, 7)` is `128.0`<br>`pow(9, .5)` is `3.0` |
