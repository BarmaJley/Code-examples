import numpy as np
import scipy as sc
import matplotlib.pyplot as plt
import math
import pandas as pd
import sympy as sp
from openpyxl import load_workbook
from scipy.optimize import LinearConstraint, minimize
from scipy.stats import norm
from sympy import *
from scipy import *


def exp2(y):
    return exp(-(y * y) / 2)


def F(x):
    return ((1 / math.sqrt(2)) * integrate.quad(exp2, float('-inf'), x)[0])


def fn(x, K):
    return max(x - K, 0)


# Аналитический метод
S0 = 5
K = 5
r = 0.1
sigma = 0.2
T = 1

C = S0 * F((ln(S0 / K) + T * (r + ((sigma * sigma) / 2))) / sigma * sqrt(T)) \
    - K * exp(-r * T) * \
    F((ln(S0 / K) + T * (r + ((sigma * sigma) / 2))) / sigma * sqrt(T))
print("Аналитический: C = {}".format(C))

# Метод Монте-Карло
M = 1000
N = 100
h = T / N
eps = np.zeros((M, N))

S = np.zeros(M)
f = np.zeros(M)

s_eps = np.zeros(M)
s_f = 0

for i in range(M):
    for j in range(N):
        eps[i][j] = np.random.normal(loc=0, scale=1, size=None)
        s_eps[i] += eps[i][j]

for i in range(M):
    S[i] = S0 * exp((r - (sigma * sigma / 2)) * T + sigma * sqrt(h) * s_eps[i])
    f[i] = max(S[i] - K, 0)
    s_f += f[i]

C = (1 / M) * s_f
print("Метод Монте-Карло: C = {} ".format(C))


#Метод дискретной аппроксимации
h = T / 10
Cn = np.zeros(N)
s_fn = 0
N = 10
for n in range(10):
    Cn[n] = factorial(10) / (factorial(n) * factorial(10 - n))

for n in range(N):
    s_fn += fn(S0 * (1 + r * h + sigma * sqrt(h)) ** n * (1 + r * h - sigma * sqrt(h)) ** (10 - n), K) * Cn[n]
C = 1 / 2 ** 10 * s_fn
print("Метод дискретной аппроксимации:C = {}".format(C))
