---
Week: 03
--

This module is concerned with understanding spectra and the Fourier transform. Fourier proposed to decompose any well-behaved function into a sum of harmonic sines and cosines.  The idea of Fourier that sines and cosines can be used to decompose functions is still fundamental in many areas, and not only in signal processing but also all over applied sciences and physics.

# Lesson 3.1: Introduction to Fourier analysis
Why should we use sines and cosines to describe a signals?
* Oscillations are everywhere.
* sustainable dynamic systems exhibit oscillatory behavior

Oscillations are very easy to describe.

## Analysis
* from time domain to frequency domain
* find the contribution of different frequencies
* discover "hidden" signal properties

## Synthesis
* from frequency to time domain
* create signals with known frequency content
* fit signals to specific frequency regions

## Mathematical setup
* let's start with finite length signals
* Fourier analysis is a simple change of basis

## Fourier Basis for $\mathbb{C}^N$
$$
w_k[n] = exp(j\frac{2\pi}{N}nk) \quad n,k = 0,1,...,N-1
$$   

is an orthogonal basis in $\mathbb{C}$, k is the index of the signal such that $\omega = 2\pi k/N$

In order to be orthonormal the vectors should be normalized by a factor of $1/\sqrt{N}$

# Lesson 3.2: Discrete fourier transform
## Analysis Formula
$$
 X_k = \langle \mathbf{w}^{(k)}, \mathbf{x}\rangle
$$

Or in matrix notation:
$$
\mathbf{X} = \mathbf{W} \mathbf{x}
$$
## Synthesis Formula
$$
\mathbf{x} = \frac{1}{N} \sum_{k=0}^{N-1} X_k \mathbf{w}^{(k)}
$$

Or in matrix form:
$$
\mathbf{x} = \frac{1}{N} \mathbf{W}^H \mathbf{X}
$$

$1/N$ is the normalization factor that comes from the orthonormal normalization.

* Energy is perserved accross different bases (Parseval's theorem)
* In general terms, the magnitude of the DFT is "symmetric"
* We will only need $\lfloor N/2 \rfloor +1$ coefficients to specify the magnitude of the DFT of a real signal of length N

# Lesson 3.3: DFT in Practice
* The fastest positive frequency is $\omega = \pi$
* sinusoid at $\omega = \pi$  needs two samples to do a full revolution
* time between samples $T_s = 1/F_s$ seconds
* real-world period for fastest sinusoid is $2T_s$ seconds
* real-world frequency for fastest sinusoid $F_s/2$ Hz

# Lesson 3.4: The short-time Fourier Transform

