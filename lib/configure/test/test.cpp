/***********************************************************
 * Copyright: zhaodongwei@nanjing university
 * author: zhaodongwei(joodaw@gmail.com)
 * 
 * file: test.cpp
 * date: 2012-11-19
 * desc: test of configure
 ***********************************************************/

#include <stdio.h>

#include "configure.h"

int main() {
	configure::Configure conf("./conf/configure.conf");
	fprintf(stdout, "[test]input: %s\n", conf["input"].to_cstr());
	fprintf(stdout, "[test]array: %s\n", conf["array"][1][1].to_cstr());
	return 0;
}

