#!/usr/bin/env python3

import os
import subprocess
from numpy import sqrt

def color_operation():
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
	arg_list = [["1.0", "0.2", "0.4", "0.9", "1.0", "0.1"]]
	stdout_ref_list = ["0.900000 \n0.200000 \n0.040000 \n1.900000 \n1.200000 \n0.500000 \n0.100000 \n-0.800000 \n0.300000 \n"]
	stderr_ref_list = [""]

	# arg_list.append(["1.0", "0.2", "0.4", "0.9", "1.0", "0.1"])
	# stdout_ref_list.append("(1.900000, 1.200000, 0.500000, 2)\n")
	# stderr_ref_list.append("")

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
	exit_status = color_operation()
	print(f"exit_status: {exit_status}")
	exit(exit_status)