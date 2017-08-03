---
Week: 02
---

# Lesson 2.1: Signal Processing and vector space
We need a common framework: vector space
## Vector space
* same framework for different classes of signals
* same framework for continuous-time signals
* easy explanation of the Fourier Transform
* easy explanation of sampling and interpolation
* useful in approximation and compression
* fundamental in communication system design

Vector spaces are very general objects and are defined by their properties and not by the shape of the vector they contain. Once you meet all the requeriments you can use vector spaces.

# Lesson 2.2: Vector spaces
Vectors can be functions. Some vector spaces can be represented graphically. 
* Ingrendients: set of vectors and scalars
* We at least have to be able to resize vectors and combine vectors together

## Formal properties 
For $x$, $y$, $z \in V$ and $\alpha , \beta \in \mathbb{C}$

* $x+y = y+x$
* $(x + y) + z = x + (y + z)$
* $\alpha (x + y) = \alpha x + \alpha y$
* $(\alpha + \beta )x = \alpha x + \beta x$
* $\alpha (\beta x) = (\alpha \beta ) x$
* $\exists 0 \in V | x + 0 = 0 + x = x$
* $\forall x \in V \exists(-x) | x + (-x) = 0$

## Inner product
* measure of similarity between vector
* if it is zero then vectors are orthogonal, maximally different

Finite-lenght and periodic signals live in $\mathbb{C}^N$.
The inner product for signals is defined as: 

$$
\langle x,y \rangle = \sum_{n=0}^{N-1} x^*[n]y[n]
$$

For infinite-lenght signals, the sum may explode since $N=\infty$. To prevent this to happen, we should define a vector space that all sequences in the vector space must be **square-summable** or **finite energy**.
 
Completeness of a vector space, means that a linear combination of the vectors must result in a vector that also lives in that vector space.
The following example shows incompleteness in a set of rational numbers :

$$
\begin{aligned}
x_n &=  \sum_{k=0}^{n} \frac{1}{k!} \in \mathbb{Q} \\
\lim_{n \to \infty} x_n &= e \notin \mathbb{Q}
\end{aligned}
$$ 

## Hilbert space 
* a vector space $H(V, \mathbb{C}$
* an inner product $\langle , \rangle : V \times V \to \mathbb{C}$
* completeness

# Lesson 2.3: Bases
A basis is a vector space's "skeleton", so to speak. It gives the space structure and allows us to decompose any element in the space into a linear combination of simple building blocks, namely, the basis vectors. 

