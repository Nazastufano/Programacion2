
/* 1. Describir lo que imprime el siguiente fragmento de código:
    int *p, a = 4; b = 5;
    p = &b;
    *p *= 2;
    printf("b=%d *p=%d\n", b, *p); _________________ a)
    printf("&b=%p p=%p &p=%p\n", &b, p, &p); _________________ b)
    b = *p *3;
    printf("b=%d *p=%d\n", b, *p); _________________ c)
    printf("&b=%p p=%p\n", &b, p); _________________ d)
    a = b; 
    p = &a; 
    (*p)++; 
    printf("b=%d a=%d *p=%d\n", b, a, *p); _________________ e)
    printf("&b=%p &a=%p p=%p &p=%p\n", &b, &a, p, &p); ________________________ f)


a) b=10 *p=10
b) &b=0000002415fff97c p=0000002415fff97c &p=0000002415fff980 
c) b=30 *p=30
d) &b=0000002415fff97c p=0000002415fff97c
e) b=30 a=31 *p=31
f) &b=0000002415fff97c &a=0000000b10dffea4 p=0000000b10dffea4 &p=0000002415fff980

*/


