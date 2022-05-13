#include <stdio.h>

struct point {
    int x, y;
};

/* No logical concern when avoiding pointer members, and no performance concerns
 * when avoiding large structs. */
void swap(struct point *a, struct point *b, int index) {
    struct point tmp;
    tmp = *a;
    *a = b[index];
    if (index == 0) {
        b[index] = b[3] = tmp;
    }
    else {
        b[index] = tmp;
    }
}

/*
 * double area(triangle) - return the area of a triangle
 *
 *  where triangle is an array of 4 points, the fourth being a duplicate of the first.
 */
double area(struct point *triangle) {
    double area = 0;
    for (int i = 0; i < 3; i++) {
        area += triangle[i].x * triangle[i + 1].y - (triangle[i + 1].x * triangle[i].y);
    }
    return area / 2;
}

// debug
void print_triangle(struct point *triangle) {
    for (int i = 0; i < 4; i++) {
        printf("\t\t%d %d\n", triangle[i].x, triangle[i].y);
    }
}

/*
 * int in_bounds(point, triangle) - determine whether a point lies within a triangle
 */
int in_bounds(struct point *p, struct point *triangle) {
    // TODO loop this and _actually_ pay attention to indices this time
    int sign = 0;
    swap(p, triangle, 0);
    triangle[3] = triangle[0];
    sign = area(triangle) > 0;
    swap(p, triangle, 0);
    triangle[3] = triangle[0];
    swap(p, triangle, 1);
    if (sign != (area(triangle) > 0)) {
        //printf("a > 0: %d\n", area(triangle) > 0);
        goto fail;
    }
    swap(p, triangle, 1);
    swap(p, triangle, 2);
    if (sign != (area(triangle) > 0)) {
        //printf("a > 0: %d\n", area(triangle) > 0);
        goto fail;
    }
    swap(p, triangle, 2);

    if (0) {
fail:
            return 0;
    }
    return 1;
}

int main() {
    struct point triangle[4];
    struct point p;
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &triangle[i].x, &triangle[i].y);
    }
    triangle[3] = triangle[0];
    printf("area: %lf\n", area(triangle));
    scanf("%d %d", &p.x, &p.y);
    printf("%d\n", in_bounds(&p, triangle));
    return 0;
}
