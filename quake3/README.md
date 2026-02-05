<H1>Analysis of the Quake-III-Areana Fast Inverse Square Root</H1>
<H2>Overview</H2>
<p>The famous quake3 algorithm is an approximation of the inverse square root of a number x (where x is a positive real number). </p>

$$f(x) = {1 \over \sqrt{x}}$$
$$\{x \in \mathbb{R} \mid x > 0\}$$

<H2>Computer Graphics Background</H2>

<H2>Key Concepts</H2>
  <ol>
    <li>Normalised numbers in IEEE 754.</li>
    <li>Mathematical approximations in binary</li>
    <li>Bit manipulation in the C-language.</li>
    <li>Take advantage of contraints (input will always be positive and the result will always be between 0 and 1).</li>
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
  <p>The value stored in the 32-bit memory does not represent the final float number. The sign, exponent and mantissa stored in the float must be interpreted as the standard defines. The equation is as follows: <br>

  $$float_{10}= (-1)^{Sign} * (1 + {Mantissa\over 2^{23} } ) * 2^{Exponent-127}$$
  </p>

<H4>Offset Binary Notation in IEEE-754:</H4>
<H4>The mathematical approximation:</H4>
<H4>Bit Manipulation:</H4>

<H2>Example</H2>

<H2>Results</H2>
<H3>Percent Difference:</H3>
<H3>Complexity Difference:</H3>
<H3>Deriving the best constant (0x5F375A86):</H3>
<H3>Does this work with 64 Bits?:</H3>

<H2>Conclusion & Relevance Today</H2>

<H2>References</H2>
