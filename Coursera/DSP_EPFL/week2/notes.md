---
Week: 02
---
# Vector Spaces

## Lesson 2.1: Signal Processing and vector space
We need a common framework: vector space
### Vector space
* same framework for different classes of signals
* same framework for continuous-time signals
* easy explanation of the Fourier Transform
* easy explanation of sampling and interpolation
* useful in approximation and compression
* fundamental in communication system design

Vector spaces are very general objects and are defined by their properties and not by the shape of the vector they contain. Once you meet all the requeriments you can use vector spaces.

## Lesson 2.2: Vector spaces
Vectors can be functions. Some vector spaces can be represented graphically. 
* Ingrendients: set of vectors and scalars
* We at least have to be able to resize vectors and combine vectors together

### Formal properties 
For $x$, $y$, $z \in V$ and $\alpha , \beta \in \mathbb{C}$

* $x+y = y+x$
* $(x + y) + z = x + (y + z)$
* $\alpha (x + y) = \alpha x + \alpha y$
* $(\alpha + \beta )x = \alpha x + \beta x$
* $\alpha (\beta x) = (\alpha \beta ) x$
* $\exists 0 \in V | x + 0 = 0 + x = x$
* $\forall x \in V \exists(-x) | x + (-x) = 0$

### Inner product
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

### Hilbert space 
* a vector space $H(V, \mathbb{C}$
* an inner product $\langle , \rangle : V \times V \to \mathbb{C}$
* completeness

### Some properties inner product
* scaling property with respect to scalar multiplication:
$$
\begin{aligned}
\langle x, \alpha y  \rangle =& \alpha \langle x, y\rangle \\
\langle \alpha x, y \rangle =& \alpha^* \langle x, y \rangle
\end{aligned}
$$

* communtative within complex conjugation
$$\langle x, y \rangle = \langle y, x\rangle ^*$$

## Lesson 2.3: Bases
A basis is a vector space's "skeleton", so to speak. It gives the space structure and allows us to decompose any element in the space into a linear combination of simple building blocks, namely, the basis vectors. 

Linear combination is the basic operation in vector spaces. 

Canonical $\mathbb{R}^2$ basis: 
$$
    e^{(0)} = [1 \ 0]^T \qquad e^{(1)} = [0\ 1]^T  
$$

### Formal definiton
Given:
* a vector space H
* a set of K vectors from H: $W = \{ w^{(k)} \} k = 0,1,2, ..., K-1$

W is a basis for H if:

1. we can write for all $\mathbf{x} \in H$:
$$
\mathbf{x} = \sum_{k=0}^{K-1} \alpha _k \mathbf{w}^{(k)}, \alpha _k \in \mathbb{C}
$$
2. coefficients $\alpha _k$ are unique

### Special bases
* Orthogonal basis: $\langle \mathbf{w}^{(k)} \mathbf{w}^{(n)}\rangle = 0$
* Orthonormal basis: orthogonal vectors of norm equal to one are called orthonormal bases
 $\langle \mathbf{w}^{(k)} \mathbf{w}^{(n)}\rangle = \delta [n-k]$

We can always orthonormalize a basis via the Gram-Schmidt algorithm (iterative). 
Given an orthogonal basis, you can define an orthonormal basis by dividing each basis vector by its norm.

### Lesons 2.4: Subspaces and approximation
One of the beneficts of dsp in the possibilty of making approximations of the signals.

* vector subspace is a subset of vectors closed under addition and scalar multiplication. For example, $\mathbb{R}^2 \subset \mathbb{R}^3$.

* subspaces have their own basis

* In finite dimensions, once we find a full set of orthogonal vectors, we are sure that the set spans the space.

  
### Approximation
Problem:

* vector $\mathbf{x} \in V$
* subspaces $S \subseteq V$
* approximate $\mathbf{x}$ in $S$

### Least squares approximation
Since the inner product is dependent on the angular separation between the vectors, it represents a first rough measure of similarity between x and y; in broad terms, it provides a measure of the difference in shape between vectors.

It will be called **filtering**, when we are trying to approximate or modify a signal or it will be called **correlation** when we are trying to detect one particular signal amongst many. In any case inner product will allow us to measure the similarity (euclidean distance).


Orthogonal projection is the "best" approximation over $S$, because:

* has the minimun-norm error: $$arg \min_{y \in S} \|x-y\| = \hat{x}$$
* error is orthogonal to approximation: $$ \langle x-\hat{x}, \hat{x}\rangle = 0$$




