#!/usr/bin/env python3

import os
import subprocess
from numpy import sqrt

def matrix_transpose():
	exit_status = 0
	
	# Ensure the script runs from its own directory
	os.chdir(os.path.dirname(os.path.abspath(__file__)))

	# Constant args
	program = ["./miniRT"]
	valgrind = ["valgrind", "--leak-check=full", "--show-leak-kinds=all", "--track-origins=yes"]
	valgrind_check = "All heap blocks were freed -- no leaks are possible"

	# Colours
	GREEN = "\033[32;1m"
	RED = "\033[31;1m"
	COLOR_LIMITER = "\033[0m"
	colours = [GREEN, RED, COLOR_LIMITER]

	# make re
	make_re = ["make", "re"]
	subprocess.run(make_re, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

	# Creating args
	# battery = ["str on list", "dup on list", "max on list", "nothing on list"]
	arg_list = [["3", "3", "1 2 3 4 5 6 7 8 9"]]
	stdout_ref_list = ["1.000000 4.000000 7.000000 \n2.000000 5.000000 8.000000 \n3.000000 6.000000 9.000000 \n"]
	stderr_ref_list = [""]

	arg_list.append(["4", "3", "1 2 3 4 5 6 7 8 9 10 11 12"])
	stdout_ref_list.append("1.000000 4.000000 7.000000 10.000000 \n2.000000 5.000000 8.000000 11.000000 \n3.000000 6.000000 9.000000 12.000000 \n")
	stderr_ref_list.append("")

	arg_list.append(["2", "2", "1 2 3 4"])
	stdout_ref_list.append("1.000000 3.000000 \n2.000000 4.000000 \n")
	stderr_ref_list.append("")

	# Runing and collecting output and error
	stdout_list = []
	stderr_list = []
	stderr_val_list = []
	for arg in arg_list:
		cmd = program + arg
		if arg[0] == "noarg":
			cmd = program
		output = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
		cmd_val = valgrind + cmd
		output_val = subprocess.run(cmd_val, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
		stdout_list.append(output.stdout)
		stderr_list.append(output.stderr)
		stderr_val_list.append(output_val.stderr)

	# Printing test check
	i = 0
	for stdout, stderr, err_val in zip(stdout_list, stderr_list, stderr_val_list):
		# print(f"{battery[i].upper()}")
		if (stderr == stderr_ref_list[i] and stdout == stdout_ref_list[i]):
			print(f"{colours[0]}{i + 1}/{len(arg_list)}.	OK{colours[2]}")
		else:
			print(f"{colours[1]}{i + 1}/{len(arg_list)}.	KO{colours[2]}")
			exit_status = 1
		if valgrind_check in err_val:
			print(f"{colours[0]}	MOK\n{colours[2]}")
		else:
			print(f"{colours[1]}	MKO\n{colours[2]}")
			exit_status = 1
		i = i + 1

	# clean = ["make", "fclean"]
	# subprocess.run(clean, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
	return exit_status

if __name__ == '__main__':
	exit_status = matrix_transpose()
	print(f"exit_status: {exit_status}")
	exit(exit_status)