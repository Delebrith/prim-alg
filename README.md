## Comparison of Python and C++ implementations of Prim's algorithm

### Structure

The project consists of 3 modules:  
- cpp_prim contains C++ implementation of Prim's algorithm
- py_prim containts Python implementation
- test contains jupyter notebooks with performance tests and results

### Setup

first, install requirements:

	python -m pip install -r requirements.txt

run setup\setup.py script to:

- Download libraries and tools. Full list is given in downlaod_libraries.py script
- Confiure python module build

If libraries are already in libs directory, they will not be downloaded. This is determined by checking if their subdirectories exist.

