#!/usr/bin/env python3

print("\nTEST DRIVEN DEVELOPMENT\n")

status = 0

print("point vector add")
from point_vector_add.point_vector_add import point_vector_add
_status = point_vector_add()
if _status != 0:
	status = 1

print("vector vector add")
from vector_vector_add.vector_vector_add import vector_vector_add
_status = vector_vector_add()
if _status != 0:
	status = 1

print("point point add")
from point_point_add.point_point_add import point_point_add
_status = point_point_add()
if _status != 0:
	status = 1

print("point point minus")
from point_point_minus.point_point_minus import point_point_minus
_status = point_point_minus()
if _status != 0:
	status = 1

print("point vector minus")
from point_vector_minus.point_vector_minus import point_vector_minus
_status = point_vector_minus()
if _status != 0:
	status = 1

print("vector vector minus")
from vector_vector_minus.vector_vector_minus import vector_vector_minus
_status = vector_vector_minus()
if _status != 0:
	status = 1

print("tuple neg")
from tuple_neg.tuple_neg import tuple_neg
_status = tuple_neg()
if _status != 0:
	status = 1

print("tuple scalar mult div")
from tuple_scalar_mult_div.tuple_scalar_mult_div import tuple_scalar_mult_div
_status = tuple_scalar_mult_div()
if _status != 0:
	status = 1

print("magnitude")
from magnitude.magnitude import magnitude
_status = magnitude()
if _status != 0:
	status = 1

print("normalize")
from normalize.normalize import normalize
_status = normalize()
if _status != 0:
	status = 1

print("dot prod")
from dot_prod.dot_prod import dot_prod
_status = dot_prod()
if _status != 0:
	status = 1

print("cross dot")
from cross_prod.cross_prod import cross_prod
_status = cross_prod()
if _status != 0:
	status = 1

print("color operation")
from color_operation.color_operation import color_operation
_status = color_operation()
if _status != 0:
	status = 1

print("matrix operation")
from matrix_operation.matrix_operation import matrix_operation
_status = matrix_operation()
if _status != 0:
	status = 1

print("matrix equal")
from matrix_equal.matrix_equal import matrix_equal
_status = matrix_equal()
if _status != 0:
	status = 1

print("matrix mult")
from matrix_mult.matrix_mult import matrix_mult
_status = matrix_mult()
if _status != 0:
	status = 1

print("matrix identity")
from matrix_identity.matrix_identity import matrix_identity
_status = matrix_identity()
if _status != 0:
	status = 1

print("matrix transpose")
from matrix_transpose.matrix_transpose import matrix_transpose
_status = matrix_transpose()
if _status != 0:
	status = 1

print("submatrix")
from submatrix.submatrix import submatrix
_status = submatrix()
if _status != 0:
	status = 1

print("determinant")
from determinant.determinant import determinant
_status = determinant()
if _status != 0:
	status = 1

print(f"status: {status}\n")
exit(status)
