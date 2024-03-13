#include <stdio.h>
#include <stdlib.h>

void* aligned_malloc(size_t size, size_t alignment) {
  printf("aligned_malloc: size = %lx, alignment = %lx\n", size, alignment);
  void* ptr = malloc(size + alignment);
  void* newPtr = (void*)((size_t)ptr + (alignment - (size_t)ptr % alignment));
  printf("ptr address = %p ~ %lx \n", ptr, (size_t)ptr + size + alignment);
  printf("new ptr address = %p ~ %lx\n", newPtr, (size_t)newPtr + size);
  void* ptrAddr = (void*)((size_t)newPtr - sizeof(size_t));
  printf(" ptrAddr address = %p\n", ptrAddr);
  *((size_t *)ptrAddr) = (size_t)ptr;
  return newPtr;
}

void aligned_free(void* newPtr) {
  printf("aligned_free: newPtr = %p\n", newPtr);
  void* ptrAddr = (void*)((size_t)newPtr - sizeof(newPtr));
  printf(" ptrAddr address = %p\n", ptrAddr);
  void* ptr = (void*) (*(size_t *)ptrAddr);
  printf("ptr address = %p\n", ptr);
  free(ptr);
} 

int main() {
  void* ptr = malloc(1000);
  printf("test address = %p\n\n", ptr);
  free(ptr);

  ptr = aligned_malloc(1000, 128);
  printf("test2 address = %p\n", ptr);
  aligned_free(ptr);
  return 0;
}
