<H1>Analysis of the Quake-III-Areana Fast Inverse Square Root</H1>
<H2>Overview</H2>
<p>The famous quake3 algorithm is an approximation of the inverse square root of a number x (where x is a positive real number). </p>

$$f(x) = {1 \over \sqrt{x}}$$
$$\{x \in \mathbb{R} \mid x > 0\}$$

<H2>Computer Graphics Background</H2>

<H2>Key Concepts</H2>
  <ol>
    <li>Normalized numbers in IEEE 754.</li>
    <li>Mathematical approximations in binary.</li>
    <li>Bit manipulation in the C-language.</li>
    <li>Take advantage of constraints (input will always be positive and the result will always be between 0 and 1).</li>
  </ol>

<H3>IEEE-754</H3>
  <p>A single precision float in IEEE-754 (also called binary32) is defined in the table below:
  </p>
<!-- <style>
  .custom-table td
  {
    border-left: 1px solid;
    border-right: 1px solid;
    border-top: 1px solid;
    border-bottom: 1px solid;
  }
</style> -->
<table class="custom-table">
  <tr>
    <td></td>
    <td style="border-left: 1px solid;">Sign Bit (1-bit)</td>
    <td colspan="8"style="text-align:center;
                          border-left: 1px solid;">
        Exponent (8-bit) <br>
    </td>
    <td colspan="23" style="text-align:center;
                            border-left: 1px solid;
                            border-right: 1px solid;
                            ">
        Mantissa (23-bit)</td>
  </tr>
  <tr>
    <td>Bit Position</td>
    <td>31 (MSB)</td>
    <td>30</td>
    <td>29</td>
    <td>28</td>
    <td>27</td>
    <td>26</td>
    <td>25</td>
    <td>24</td>
    <td>23</td>
    <td>22</td>
    <td>21</td>
    <td>20</td>
    <td>19</td>
    <td>18</td>
    <td>17</td>
    <td>16</td>
    <td>15</td>
    <td>14</td>
    <td>13</td>
    <td>12</td>
    <td>11</td>
    <td>10</td>
    <td>9</td>
    <td>8</td>
    <td>7</td>
    <td>6</td>
    <td>5</td>
    <td>4</td>
    <td>3</td>
    <td>2</td>
    <td>1</td>
    <td>0 (LSB)</td>
  </tr>
  <tr>
    <td>Decimal Range</td>
    <td style="text-align:center; border-left: 1px solid;"> 0 to 1 (1-bit)</td>
    <td colspan="8" style="text-align:center; border-left: 1px solid;">
        0 to 255 (8-bit unsigned number) <br>
        [255 reserved for -infinity, infinity, NaN]
    </td>
    <td colspan="23" style="text-align:center; border-left: 1px solid; border-right: 1px solid;">
        0 to 8388607 (23-bit unsigned number)
    </td>
  </tr>
</table>

<H4>How to interpret a single precision float (32-bit) in IEEE-754:</H4>
  <p>The value stored in the 32-bit memory does not represent the decimal float. The sign, exponent and mantissa stored in the float must be interpreted as the standard defines. The equation is as follows: <br>

  $$float_{10}= (-1)^{Sign} * (1 + {Mantissa\over 2^{23} } ) * 2^{Exponent-Bias}$$
  </p>

<H4>Offset Binary Notation in IEEE-754:</H4>
  <p>In IEEE-754, the exponent is interpreted differently than it is stored. The standard uses a "bias" to interpret the stored exponent value. The bias essentially makes the value signed, splitting the range into negative and positive values. So for a 32-bit float, the 8-bit exponent has it's decimal range is shifted from (0 to 255) to (-126 to 127). This offset is also referred to as "excess-127". Just remember that the offset changes depending on the size of the float and therefore the number of bits in the exponent. For example, a 64-bit float would use excess-1023. This is the equation to find the bias:
  
  $$ bias = 2^{bits-1}-1$$

  Moreover, the standard reserves 0 and 255 for special cases (0, -inf, +inf, NaN). This affects the range of the possible unsigned integers to go from (0, 255) to (1, 254). We can represent the decimal range of possible integers as follows:

  $$ [1-bias, (2^{bits}-2) - bias] $$
  which simplifies to:
  $$ [1-bias, bias]$$

  The standard was designed with this bias for a few reasons:</p>
  <ol type="1">
    <li>"If you use exponents to show both integer (n >= 0) and fractional (n < 0) values you have the problem that you need one exponent for 2^0 = 1. So the remaining range is odd, giving you either the choice of choosing the bigger range for fractions or for integers. For single precision we have 256 values, 255 without the 0 exponent. Now IEEE754 reserved the highest exponent (255) for special values: +- Infinity and NaNs (Not a Number) to indicate failure. So we are back to even numbers again (254 for both sides, integer and fractional) but with a lower bias."[2](#References)</li>
    <li>"The second reason is gradual underflow. The Standard declares that normally all numbers are normalized, meaning that the exponent indicates the position of the first bit. To increase the number of bits the first bit is normally not set but assumed (hidden bit): The first bit after the exponent bit is the second bit of the number, the first is always a binary 1. If you enforce normalization you encounter the problem that you cannot encode zero and even if you encode zero as special value, the numerical accuracy is hampered. +-Infinity (the highest exponent) makes it clear that something is wrong, but underflow to zero for too small numbers is perfectly normal and therefore easily to overlook as a possible problem. So Kahan, the designer of the standard, decided that denormalized numbers or subnormals should be introduced and they should include 1/MAX_FLOAT."[2](#References)</li>
    <li> To allow faster comparisons between floats. The exponent must allow for negative and positive values. However, adding a sign bit using two's compliment representation would make comparisons slower because you need to consider the sign bit and potentially perform a subtraction operation to compare order. A sign bit would also reduce the range of possible exponent values. With an offset binary, your lowest value starts at zero and increases normally in binary, so binary comparisons are fast and lexicographical.[3](#References) Additionally, when comparing equality of two floats, the exponent will be checked before the mantissa. This means you can save time checking equality if the exponents do not match.</li>
    <li> Why not add another sign bit that is separate like the mantissa? I believe this is because you would lose another bit of accuracy in the mantissa, which is prioritized over the exponent range.</li>
  </ol>
<H3>The mathematical approximation:</H3>
<H3>Bit Manipulation:</H3>

<H2>Example</H2>

<H2>Results</H2>
<H3>Percent Difference:</H3>
<H3>Complexity Difference:</H3>
<H3>Deriving the best constant (0x5F375A86):</H3>
<H3>Does this work with 64 Bits?:</H3>

<H2>Conclusion & Relevance Today</H2>

<H2>References</H2>
  <ol>
    <li>https://www.youtube.com/watch?v=p8u_k2LIZyo</li>
    <li>https://stackoverflow.com/questions/8909841/why-does-the-ieee-754-standard-use-a-127-bias</li>
    <li>https://stackoverflow.com/questions/19864749/why-do-we-bias-the-exponent-of-a-floating-point-number</li>
    <li>https://lomont.org/papers/2003/InvSqrt.pdf</li>
  </ol>