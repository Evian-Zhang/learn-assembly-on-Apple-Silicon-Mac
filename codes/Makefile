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

9-div: 9-div.s
	$(AS) 9-div.s -o 9-div.o
	$(LD) $(LDFLAGS) 9-div.o -o 9-div

10-alignment: 10-alignment.c
	$(CC) 10-alignment.c -o 10-alignment

11-likely: 11-likely.c
	$(CC) 11-likely.c -O1 -S -o 11-likely.s

11-switch: 11-switch.c
	$(CC) 11-switch.c -S -o 11-switch.s

12-stack-overflow: 12-stack-overflow.c
	$(CC) 12-stack-overflow.c -o 12-stack-overflow

12-argument-passing: 12-argument-passing.c
	$(CC) 12-argument-passing.c -S -o 12-argument-passing.s

12-fibonacci: 12-fibonacci.s
	$(AS) 12-fibonacci.s -o 12-fibonacci.o
	$(LD) $(LDFLAGS) 12-fibonacci.o -o 12-fibonacci

13-hello-world: 13-hello-world.s
	$(AS) 13-hello-world.s -o 13-hello-world.o
	$(LD) $(LDFLAGS) 13-hello-world.o -o 13-hello-world

14-foo1.o: 14-foo1.s
	$(AS) 14-foo1.s -o 14-foo1.o

14-foo2.o: 14-foo2.s
	$(AS) 14-foo2.s -o 14-foo2.o

lib14-foo-static.a: 14-foo1.o 14-foo2.o
	$(AR) rcs lib14-foo-static.a 14-foo1.o 14-foo2.o

lib14-foo-dynamic.dylib: 14-foo1.o 14-foo2.o
	$(LD) $(LDFLAGS) 14-foo1.o 14-foo2.o -dylib -o lib14-foo-dynamic.dylib

14-main.o: 14-main.s
	$(AS) 14-main.s -o 14-main.o

14-main-static: 14-main.o lib14-foo-static.a
	$(LD) $(LDFLAGS) -L. 14-main.o -l14-foo-static -o 14-main-static

14-main-dynamic: 14-main.o lib14-foo-dynamic.dylib
	$(LD) $(LDFLAGS) -L. 14-main.o -l14-foo-dynamic -o 14-main-dynamic

15-swap: 15-swap.c
	$(CC) 15-swap.c -o 15-swap

all: \
	2-floating-precision \
	2-special-numbers \
	3-endianness \
	4-aslr \
	4-memory-access \
	5-basic \
	7-alias-instructions \
	7-zero-register \
	8-ldr-pseudo-instruction \
	9-div \
	10-alignment \
	11-likely \
	11-switch \
	12-stack-overflow \
	12-argument-passing \
	12-fibonacci \
	13-hello-world \
	14-main-static \
	14-main-dynamic \
	15-swap

clean:
	rm *.o *.a *.dylib \
		2-floating-precision \
		2-special-numbers \
		3-endianness \
		4-aslr \
		4-memory-access \
		5-basic \
		7-alias-instructions \
		7-zero-register \
		8-ldr-pseudo-instruction \
		9-div \
		10-alignment \
		11-likely.s \
		11-switch.s \
		12-stack-overflow \
		12-argument-passing.s \
		12-fibonacci \
		13-hello-world \
		14-main-static \
		14-main-dynamic \
		15-swap
