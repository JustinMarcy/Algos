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

<H3>IEEE-754:</H3>
<H4>How to interpret a single precision float (32-bit) in IEEE-754:</H4>
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
