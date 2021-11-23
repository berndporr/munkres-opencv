munkres-opencv
===========

An implementation of the Kuhn–Munkres algorithm by from John Weaver
adapted for openCV

https://thereaderwiki.com/en/Munkres%27_assignment_algorithm



Usage
-----

You have to have OPENCV 2.4 or above installed to use this.

run `cmake .` and `make`

Basic usage can be referred from `demo.cpp`

Provide the assignment matrix and it will provide the minimum cost by marking the
found matrix elements with a 0 and anything else with -1 in the
output matrix.



License
-------

Port to OPENCV by Shen Yiming 2014
cmake by Bernd Porr 2021

Copyright (c) 2007-2013 John Weaver and contributors.

https://github.com/saebyn/munkres-cpp

Licensed under the GPLv2. See the file COPYING for details.
