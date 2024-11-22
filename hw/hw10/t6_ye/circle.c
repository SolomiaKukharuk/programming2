#include <stdio.h>
#include "circle.h"


void input_circle(Circle *c) {
    printf("Введіть радіус кола: ");
    scanf("%lf", &c->radius);

    printf("Введіть координати центру кола (x і y): ");
    scanf("%lf %lf", &c->x, &c->y);
}


void output_circle(const Circle *c) {
    printf("Коло: радіус = %.2lf, центр = (%.2lf, %.2lf)\n", c->radius, c->x, c->y);
}
