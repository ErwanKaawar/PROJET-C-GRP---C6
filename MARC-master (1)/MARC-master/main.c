#include <stdio.h>
#include "map.h"
#include "loc.h"
#include "moves.h"

int main() {

    t_map map;

    // The following preprocessor directive checks if the code is being compiled on a Windows system.
    // If either _WIN32 or _WIN64 is defined, it means we are on a Windows platform.
    // On Windows, file paths use backslashes (\), hence we use the appropriate file path for Windows.
#if defined(_WIN32) || defined(_WIN64)
    map = createMapFromFile("..\\maps\\example1.map");
#else
    map = createMapFromFile("../maps/example1.map");
#endif

    printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%d ", map.soils[i][j]);
        }
        printf("\n");
    }
    // printf the costs, aligned left 5 digits
    for (int i = 0; i < map.y_max; i++)
    {
        for (int j = 0; j < map.x_max; j++)
        {
            printf("%-5d ", map.costs[i][j]);
        }
        printf("\n");
    }
    displayMap(map);

    char* a = getMoveAsString(0);
    printf("%s\n", a);

    t_localisation loc = loc_init(1, 1, NORTH);
    printf("loc.x: %d\n", loc.pos.x);
    printf("loc.y: %d\n", loc.pos.y);

    t_localisation b = move(loc, F_10);
    printf("x: %d\n", b.pos.x);
    printf("y: %d\n", b.pos.y);

    updateLocalisation(&b, F_30);
    updateLocalisation(&b, F_30);
    updateLocalisation(&b, F_30);
    printf("x: %d\n", b.pos.x);
    printf("y: %d\n", b.pos.y);
    printf("orie : %s\n", _orie[b.ori]);

    return 0;
}
