typedef const struct Interface* interface;

struct Interface
{
    void (*add)(int, int);
};