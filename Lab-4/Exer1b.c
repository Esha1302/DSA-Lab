#include <stdio.h>

int bits;

void p(){
    int pilani;
    printf("%u\n",&pilani);
    p();
}

void g(){
    int goa;
    printf("%u\n",&goa);
}

void h(){
    int hyd;
    printf("%u\n",&hyd);
}

void d(){
    int dub;
    printf("%u\n",&dub);
}

int main(){
   p();
   g();
   h();
   d();


}