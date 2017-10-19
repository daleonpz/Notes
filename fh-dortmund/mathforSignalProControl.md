---
course: Mathematics for Signal Processing and ControlTheory
professor: Prof. Dr. Andreas Becker
semester: Winter 2017
---

# Real Valued functions
## Defintion and types
* Function def:  $$ f: D \rightarrow \mathbb{R} $$, where $D$ is the domain. 
* Injective: $f: X \rightarrow Y$ is injective **if and only if**  
$\forall a,b \in X$ and $f(a), f(b) \in Y$  
 if $a \neq b \rightarrow  f(a) \neq f(b)$
* If a continuous function $f(x)$ is strictly increasing or decreasing over an interval N, then it is injective over N.
* Limits: right-hand $x^+$ and left-hand $x^-$   
 $$ \lim\limits_{n \rightarrow 0^+}{\frac{1}{x}} = \infty $$  
 $$ \lim\limits_{n \rightarrow 0^-}{\frac{1}{x}} = -\infty $$ 

* Continuous function: at some point $c$ of **its domain** $D$ if $f(x=c)$ exists:  
$$ \lim\limits_{x \rightarrow c}{x} = f(c) $$ 

* **Algebraic function** of degree n in one variable x is a function $y = f ( x )$ that satisfies a polynomial equation:
$$ a_{n}(x)y^{n}+a_{n-1}(x)y^{n-1}+\cdots +a_{0}(x)=0 $$

* Rational function: A function $f(x)$ is called a rational function if and only if it can be written in the form: 

$$ f(x)={\frac {P(x)}{Q(x)}} $$  

where $P$ and $Q$ are polynomials in $x$ and $Q$ is not the zero polynomial. The domain of $f$ is the set of all points $x$ for which the denominator $Q(x)$ is not zero.

* Strictly proper rational function is the degree of $Q$ is greater than the degree of $P$. Any strictly proper rational function can be expressed as a sum of simpler functions whose demonitators are linear and irreducible quadratic functions.

* A denominator factor is irreducible if it has complex or irrational roots.

* Transcendental functions: Any function that cannot be solved through arithmetic operations. (exponential, logarithmic , trigonometrics)

## Differential Calculus
* Derivative: $f'(a)=\lim _{h\to 0}{\frac {f(a+h)-f(a)}{h}}$

* $f$ is **smooth** if $f: D \rightarrow \mathbb{R}$ has **continuous** derivatives of all orders in all points of $D$
