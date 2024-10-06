global get_video_memory_back_image_pointer

section .text
bits 64

get_video_memory_back_image_pointer:
  mov rax, video_memory_back_img
  ret

section .bss
video_memory_back_img:
resb (25*80*2)