int charint(int input)
{
    int ret = 0;
    while (input != 0)
    {
        ret *= 10;
        ret += (char)(input % 256 ) - (char)'0';
        input /= 256;
        printf("%d, %d\n", ret, input);
    }
    return ret;
}