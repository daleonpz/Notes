---
Week: 04
---
# Part 2 - Advanced Fourier Analysis

In the following lessons, we will explore how Fourier analysis applies to the three different classes of signals that we have introduced in the course, namely finite-length signals, periodic signals and infinite-length signals.

Fourier representation for signal classes:

* N-point finite-length: DFT (discrete fourier transform)
* N-point periodic: DFS (discrete fourier series)
* infinite-lenght: DTFT (discrete time fourier transform)


## Lesson 3.5: Discrete Fourier Series
DFS is the DFT with periodicty explicit. 

* the DFS maps an N periodic signal onto an N-periodic sequence of Fourier coefficients 
* the inverse DFS maps an N-periodic sequence of Fourier coefficients onto a periodic signal
* the DFS of an N-periodic signal is mathematically equivalent to the DFT of one period

Helps us understand how to define time shifts for finite-length signals. The shifts for finite-length signals are "naturally" circular.

For an N-point signal $x[n]$:

* x[n-M] is not __well defined__
* build $\hat{x} = x[n \ mod\ N] \rightarrow \hat{X}[k] = X[k]$
* $IDFS\{ \hat{X}[k] \} = IDFT\{ X[k]\} = \hat{x}[n-M] = x[(n-M) \ mod \ N]$

DFT of L periods:
$$
\begin{aligned}
X_L[k] = \left\{ \begin{array}{cc} 
                L\hat{X}[k/L] & \hspace{5mm} k = 0,L,2L,... \\
                0 & \hspace{5mm} otherwise
                \end{array} \right.
\end{aligned}
$$

Thus,

* All the spectral information for a periodic signal is contained in the DFT coefficients of a single period
* to stress the periodicity of the underlying signal, we use the term DFS

## Lesson 3.6: The discrete-time Fourier Transform
Formal definition:

* $x[n] \in l_2$, finite energy
* define the function of $\omega \in \mathbb{R}$ 
$$
F(\omega) = \sum_{n=-\infty}^{\infty} x[n]e^{-j\omega n}
$$
* inversion if $F(\omega)$ exists
$$
x[n] = \frac{1}{2\pi}\int_{-\pi}^{\pi} F(\omega)e^{j\omega n}d\omega
$$

Periodicity and notation:

* $F(\omega)$ is $2\pi$-periodic
* to strees periodicity we will write:
$$
X(e^{j\omega}) = \sum_{n=-\infty}^{\infty} x[n]e^{-j\omega n}
$$
* by convention, $X(e^{j\omega})$ is represented over $\big[-\pi, \pi\big]$

A formal change of Basis:

* formally DTFT is an inner product in $\mathbb{C}^\infty$
$$
\sum_{n=-\infty}^{\infty} x[n] e^{-j\omega n} = \langle e^{j\omega n}, x[n] \rangle
$$
* "basis" is an infinite, uncountable basis $\{e^{j\omega n}\}_{\omega \in \mathbb{R}}$

Some particular cases:

* if $x[n]$ is symmetric, the DTFT is symmetric
* if $x[n]$ is real, the DTFT is Hermitian-symmetric

