section .multiboot_header
header_start:
  ; magic number
  dd 0x0e85250d6 ; multiboot2
  ; architecture
  dd 0 ; protected i386
  ; header size
  dd (header_end - header_start)
  ; checksum
  dd 0x100000000 - ((0x0e85250d6)+(0)+(header_end-header_start))

  ; end tag
  dw 0, 0
  dd 8
header_end: