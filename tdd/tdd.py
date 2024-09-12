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

print("point point minus")
from _07_point_point_minus.point_point_minus import point_point_minus
_status = point_point_minus()
if _status != 0:
	status = 1

print("point vector minus")
from _08_point_vector_minus.point_vector_minus import point_vector_minus
_status = point_vector_minus()
if _status != 0:
	status = 1

print("vector vector minus")
from _09_vector_vector_minus.vector_vector_minus import vector_vector_minus
_status = vector_vector_minus()
if _status != 0:
	status = 1

print("tuple neg")
from _10_tuple_neg.tuple_neg import tuple_neg
_status = tuple_neg()
if _status != 0:
	status = 1

print("tuple scalar mult div")
from _11_tuple_scalar_mult_div.tuple_scalar_mult_div import tuple_scalar_mult_div
_status = tuple_scalar_mult_div()
if _status != 0:
	status = 1

print("magnitude")
from _12_magnitude.magnitude import magnitude
_status = magnitude()
if _status != 0:
	status = 1

print("normalize")
from _13_normalize.normalize import normalize
_status = normalize()
if _status != 0:
	status = 1

print("dot prod")
from _14_dot_prod.dot_prod import dot_prod
_status = dot_prod()
if _status != 0:
	status = 1

print("cross dot")
from _15_cross_prod.cross_prod import cross_prod
_status = cross_prod()
if _status != 0:
	status = 1

print("color operatioon")
from color_operation.color_operation import color_operation
_status = color_operation()
if _status != 0:
	status = 1
print(f"status: {status}\n")
exit(status)
