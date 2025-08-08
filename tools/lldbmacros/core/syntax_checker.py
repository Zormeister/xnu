#!/usr/bin/env python3

helpdoc = """
A simple utility that verifies the syntax for python scripts.
The checks it does are :
  * Check for 'tab' characters in .py files
  * Compile errors in py sources
Usage:
  python syntax_checker.py <python_source_file> [<python_source_file> ..] 
"""
import py_compile
import sys
import os
import re

tabs_search_rex = re.compile("[^\s]*\t+",re.MULTILINE|re.DOTALL)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Error: Unknown arguments", file=sys.stderr)
        print(helpdoc)
        sys.exit(1)
    for fname in sys.argv[1:]:
        if not os.path.exists(fname):
            print(f"Error: Cannot recognize {fname} as a file", file=sys.stderr)
            sys.exit(1)
        if fname.split('.')[-1] != 'py':
            print("Note: %s is not a valid python file. Skipping.", fname)
            continue
        fh = open(fname)
        strdata = fh.readlines()
        lineno = 0
        tab_check_status = True
        for linedata in strdata:
            lineno += 1
            if len(tabs_search_rex.findall(linedata)) > 0 :
                print(f"Error: Found a TAB character at {fname}:{lineno}", file=sys.stderr)
                tab_check_status = False
        if tab_check_status == False:
            print("Error: Syntax check failed. Please fix the errors and try again.", file=sys.stderr)
            sys.exit(1)
        #now check for error in compilation
        try:
            compile_result = py_compile.compile(fname, cfile=None, doraise=True)
        except py_compile.PyCompileError as exc:
            print(str(exc), file=sys.stderr)
            print("Error: Compilation failed. Please fix the errors and try again.", file=sys.stderr)
            sys.exit(1)
        print(f"Success: Checked {fname}. No syntax errors found.")
    sys.exit(0)

