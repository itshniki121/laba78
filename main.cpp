#include <stdio.h>
#include <math.h>

enum confectionery {
    cake,
    brownie,
    candy
};

int main() {
    printf("%d \n", candy);

    struct parameters {
        int x1, x2, x3, x4;
        int y1, y2, y3, y4;
        float p;
    };

    struct parameters figure;

    figure.x1 = 1;
    figure.y1 = 1;
    figure.x2 = 1;
    figure.y2 = 4;
    figure.x3 = 7;
    figure.y3 = 4;
    figure.x4 = 7;
    figure.y4 = 1;
    float AB = sqrt(pow((figure.x2 - figure.x1), 2) + pow((figure.y2 - figure.y1), 2));
    float BC = sqrt(pow((figure.x3 - figure.x2), 2) + pow((figure.y3 - figure.y2), 2));
    figure.p = 2 * (AB + BC);
    printf("Perimeter ABCD = %f\n", figure.p);

    struct bitfield{
        unsigned int play :1;
        unsigned int pause :1;
        unsigned int record :2;
    };

    union x
    {
        struct bitfield bitf;
        unsigned int i;
    };
    union x y;
    scanf("%x",&y.i);
    printf("play %s\n",(y.bitf.play==1)?"On":"Off");
    printf("pause %s\n",(y.bitf.pause==1)?"On":"Off");
    printf("record %s\n",(y.bitf.record==1)?"On":"Off");
    return 0;
}
