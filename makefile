kernel_source_files := $(shell find src/kernel -name *.c)
kernel_object_files := $(patsubst src/kernel/%.c, build/kernel/%.o, $(kernel_source_files))

c_source_files := $(shell find src/c -name *.c)
c_object_files := $(patsubst src/c/%.c, build/c/%.o, $(c_source_files))

asm_source_files := $(shell find src/boot -name *.asm)
asm_object_files := $(patsubst src/boot/%.asm, build/boot/%.o, $(asm_source_files))

object_files := $(c_object_files) $(asm_object_files)

.PHONY: build clear all

all: build

$(kernel_object_files): build/kernel/%.o : src/kernel/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/lib -ffreestanding $(patsubst build/kernel/%.o, src/kernel/%.c, $@) -o $@

$(c_object_files): build/c/%.o : src/c/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/lib -ffreestanding $(patsubst build/c/%.o, src/c/%.c, $@) -o $@

$(asm_object_files): build/boot/%.o : src/boot/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/boot/%.o, src/boot/%.asm, $@) -o $@

build: $(kernel_object_files) $(object_files)
	mkdir -p dist && \
	x86_64-elf-ld -n -o dist/kernel.bin -T linker.ld $(kernel_object_files) $(object_files) && \
	cp dist/kernel.bin iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o dist/kernel.iso iso

clear:
	rm -f -r build dist
	rm -f iso/boot/kernel.bin