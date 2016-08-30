
int main(){
  char buf[40];
  buf[0] = 0xA;
  buf[3] = 0xD;
  buf[39] = 42;

  return 0xb100d;
}