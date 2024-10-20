#ifndef CIRCLE_H
#define CIRCLE_H

typedef struct {
    double radius;
    double x;
    double y;
} Circle;


void input_circle(Circle *c);
void output_circle(const Circle *c);

#endif
