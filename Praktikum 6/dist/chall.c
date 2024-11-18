// gcc -static -Os -o chall chall.c

#include <sys/mman.h>
#include <unistd.h>

int main()
{
    void register (*shellcode)() = mmap(0, 0x1000, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    write(1, "Enter shellcode: ", 0x11);
    read(0, shellcode, 0x20);
    mprotect(shellcode, 0x20, PROT_READ | PROT_EXEC);
    shellcode();
}
