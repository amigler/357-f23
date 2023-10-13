#include <stdio.h>
#include <stdlib.h>

// declare struct types

struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point makepoint(int x, int y);

int main(int argc, char *argv[]) {

    struct rect the_rect;
    struct point middle;
    
    the_rect.pt1 = makepoint(0,0);
    the_rect.pt2 = makepoint(1024, 512);
    middle = makepoint((the_rect.pt1.x + the_rect.pt2.x)/2,
                       (the_rect.pt1.y + the_rect.pt2.y)/2);


    printf("the_rect: (%d, %d) (%d, %d) \n", the_rect.pt1.x, the_rect.pt1.y, the_rect.pt2.x, the_rect.pt2.y);
    printf("middle: (%d, %d) \n", middle.x, middle.y);
    
    return EXIT_SUCCESS;
}


// makepoint: make a point from x and y components 
struct point makepoint(int x, int y) {
    struct point temp;
    temp.x = x; temp.y = y;
    return temp;
}

// addpoints: add two points
struct point addpoint(struct point p1, struct point p2) {
    p1.x += p2.x; p1.y += p2.y;
    return p1;
}

// ptinrect: return 1 if p in r, 0 if not 
int ptinrect(struct point p, struct rect r) {
    return p.x >= r.pt1.x && p.x < r.pt2.x
        && p.y >= r.pt1.y && p.y < r.pt2.y;
}
