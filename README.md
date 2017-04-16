# algorithms

This repository contains files generated during my algorithms study.

The primary goal of this repository is not be a lib to use in production.
The author goal is study algorithms and general and play with C++.

The hackerrank directory contains the source files used to solve hackerrank.com
challenges.

### Build

```
export GYP_GENERATORS=ninja <= tells gyp to generate ninja build files
gyp build.gyp --depth=.
ninja -C out/Release>
```

References:
- [Introduction to Algorithms, 3rd Edition](http://www.amazon.com/Introduction-Algorithms-Edition-Thomas-Cormen/dp/0262033844)
