#include<stdio.h>
#include<unistd.h>
int main(){
  printf("hello");
  fork();
  fork();
  fork();
  printf("Heloo DJ");
return 0;
}
