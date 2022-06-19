SDKROOT := $(shell /usr/bin/xcrun --show-sdk-path -sdk macosx)
LDFLAGS = -lSystem -L $(SDKROOT)/usr/lib

2-floating-precision: 2-floating-precision.c
	$(CC) 2-floating-precision.c -o 2-floating-precision

2-special-numbers: 2-special-numbers.c
	$(CC) 2-special-numbers.c -o 2-special-numbers

3-endianness: 3-endianness.c
	$(CC) 3-endianness.c -o 3-endianness

4-aslr: 4-aslr.c
	$(CC) 4-aslr.c -o 4-aslr

4-memory-access: 4-memory-access.c
	$(CC) 4-memory-access.c -o 4-memory-access

5-basic: 5-basic.s
	$(AS) 5-basic.s -o 5-basic.o
	$(LD) $(LDFLAGS) 5-basic.o -o 5-basic

7-alias-instructions: 7-alias-instructions.s
	$(AS) 7-alias-instructions.s -o 7-alias-instructions.o
	$(LD) $(LDFLAGS) 7-alias-instructions.o -o 7-alias-instructions

7-zero-register: 7-zero-register.s
	$(AS) 7-zero-register.s -o 7-zero-register.o
	$(LD) $(LDFLAGS) 7-zero-register.o -o 7-zero-register

8-ldr-pseudo-instruction: 8-ldr-pseudo-instruction.s
	$(AS) 8-ldr-pseudo-instruction.s -o 8-ldr-pseudo-instruction.o
	$(LD) $(LDFLAGS) 8-ldr-pseudo-instruction.o -o 8-ldr-pseudo-instruction

all: \
	2-floating-precision \
	2-special-numbers \
	3-endianness \
	4-aslr \
	4-memory-access \
	5-basic \
	7-alias-instructions \
	7-zero-register \
	8-ldr-pseudo-instruction
clean:
	rm *.o \
		2-floating-precision \
		2-special-numbers \
		3-endianness \
		4-aslr \
		4-memory-access \
		5-basic \
		7-alias-instructions \
		7-zero-register \
		8-ldr-pseudo-instruction
