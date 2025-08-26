import heapq
import itertools
import operator

def forward(n, x):
    a = downsample(conv0(n, x, h))
    d = downsample(conv0(n, x, g))
    return a, d


def backward(n, a, d):
    ar = conv1(n, upsample(n, a), rh)
    dr = conv1(n, upsample(n, d), rg)
    return merge(ar, dr)


def conv0(n, x, h):
    offset = F // 2 - 1  # TODO
    ans = [0] * n
    for j in range(n):
        for k in range(F):
            i = (j + k + n - offset) % n
            ans[j] += x[i] * h[k]
    return ans


def conv1(n, x, h):
    offset = F // 2 + 1  # TODO
    ans = [0] * n
    for j in range(n):
        for k in range(F):
            i = (j + k + n - offset) % n
            ans[j] += x[i] * h[k]
    return ans


def downsample(x):
    return x[1::2]


def upsample(n, x):
    ans = [0] * n
    ans[::2] = x
    return ans


def merge(a, b):
    return [a + b for a, b in zip(a, b)]


def qmf(h):
    return [(-1)**k * h[F - 1 - k] for k in range(F)]


def str(x):
    return "[" + " ".join(f"{x: .2f}" for x in x) + "]"


with open("ecg.dat") as f:
    x = list(map(float, f))
h = [
    0.48296291314453414337487159986, 0.83651630373780790557529378092,
    0.22414386804201338102597276224, -0.12940952255126038117444941881
]
F = len(h)
g = qmf(h)
rh = h[::-1]
rg = g[::-1]

n = len(x)
wav = []
a = x
while True:
    if n == 1:
        wav.extend(a)
        break
    a, d = forward(n, a)
    n >>= 1
    wav.extend(d[::-1])
wav.reverse()
with open("wav.dat", "w") as f:
    for w in wav:
        f.write("%+.16e\n" % w)
