#!/usr/bin/env python3

print("\nTEST DRIVEN DEVELOPMENT\n")

status = 0

print("point vector add")
from _04_point_vector_add.point_vector_add import point_vector_add
_status = point_vector_add()
if _status != 0:
	status = 1

print("vector vector add")
from _05_vector_vector_add.vector_vector_add import vector_vector_add
_status = vector_vector_add()
if _status != 0:
	status = 1

print("point point add")
from _06_point_point_add.point_point_add import point_point_add
_status = point_point_add()
if _status != 0:
	status = 1

print(f"status: {status}\n")
exit(status)