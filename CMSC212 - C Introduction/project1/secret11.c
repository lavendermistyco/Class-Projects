/**
 * CMSC 212, 2008 Fall, Project #1
 * Secret Test #11, secret11.c
 * Calls relocate_program() with a program that contains li, sw, lw, and blt
 *   instructions
 */

#include <stdio.h>
#include "machine.h"

#define PROG_LEN (sizeof(program1) / sizeof(Memory_word))

int main() {
  int retval;
  Memory_word program1[]= { 0x34050a78, 0x380543f8, 0x3c0ec75a, 0x400f0747 };
  Memory_word program2[PROG_LEN];
  Memory_word correct2[]= { 0x34050a78, 0x380583f8, 0x3c0f075a, 0x400f4747 };
  int i, mismatches;

  retval= relocate_program(program1, program2, PROG_LEN, 0x0004);
  if (retval != 1) {
    printf("relocate_program() returned %d!\n", retval);
    printf("Test failed\n");
  }

  mismatches= 0;
  for (i= 0; i < PROG_LEN; i++) {
    if (program2[i] != correct2[i]) {
      if (! mismatches++)
        printf("Error found in relocate_program() execution!\n");
      printf("  Instruction %d is 0x%08x, should be 0x%08x\n", i,
          program2[i], correct2[i]);
    }
  }
  if (mismatches) {
    printf("Test failed\n");
    return 0;
  }

  printf("Test finished!\n");
  return 0;
}
