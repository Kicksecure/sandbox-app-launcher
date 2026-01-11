/*

W^X - mprotect(), pkey_mprotect()

An attacker can write arbitrary code to a writable memory mapping and then make the
mapping executable via mprotect(). This can bypass any mmap() restrictions.

This attempts to create a writable memory mapping then mprotect() it to executable.
This also tests for pkey_mprotect() (an alternative to mprotect()).

The seccomp filter enforces strict W^X restrictions that should prevent this.

Expected output:

Bad system call (core dumped)

*/

#include <sys/mman.h>
#include <stdlib.h>

int main() {
  char* test = malloc(128);
  mmap(test, 128, PROT_WRITE, MAP_PRIVATE, -1, 0);
  test[0] = '\xcc';
  mprotect(test, 128, PROT_READ|PROT_EXEC);
  pkey_mprotect(test, 128, PROT_READ|PROT_EXEC);
}
