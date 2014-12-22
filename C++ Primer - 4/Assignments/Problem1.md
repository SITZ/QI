Problem
-------

Given a huge list of M x N integers, find maximum of each of the M rows.
Try to solve this in following ways:
	- Serial: Simple looping through each row. Print maximum of each row.
	- Parallel: Create different threads for each row, and find maximum of each row concurrently.

Hint
----
Multithreading

Input
-----

1  2  100 7
50 75 20  9

Output
------

100
75
