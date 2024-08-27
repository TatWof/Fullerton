#include <stdio.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    time_t currentTime = time(NULL);
    struct tm *humanTime = localtime(&currentTime);

    
    printf("Welcome to Euclidean Triangles.\n",
        "This software was built by and maintained by Systems Programmer Billy Leong\n");
    
    return 0;
}
