#include <stdio.h>

int jumps = 0;
/*
 * d = slip amount
 * u = jump
 * height_from_top = current pos on the wall
 */
void frog_jump(int u, int d, int height_from_top) {
    // The frog can jump free this time
    if (u >= height_from_top) {
        jumps++;
        printf("%d. The froggy jumps the rest of the way!\n", jumps);
        return;
    }
    // New height_from_top = current height_from_top - jump + slip
    jumps++;
    int new_height = height_from_top - u + d;

    printf("%d. The froggy jumps %d, slips %d, and is %d away\n", jumps, u, d, new_height);
    frog_jump(u, d, new_height);
}

int main() {
    frog_jump(5, 3, 10);
    return 0;
}
