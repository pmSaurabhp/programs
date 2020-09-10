int main()
{
    unsigned int i=10;
    while(i-- >= 0)
        printf("%u ",i);
// 0 >= 0. At this time, condition is met and i is decremented. Since i is unsigned integer,
//  the roll-over happens and i takes the value of the highest +ve value an unsigned int can take.
// So i is never negative. Therefore, it becomes infinite while loop.
    return 0;
}
