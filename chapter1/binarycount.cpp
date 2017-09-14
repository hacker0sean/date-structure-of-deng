int countOnes(unsigned int n)//O£¨logn£©
{
    int ones=0;
    while(n>0)
    {
        ones+=(1&n);
        n>>=1;
    }
    return ones;
}

int countOnes(unsigned int n)//O£¨countones£¨n£©£©
{
    int ones=0;
    while(0<n)
        ones++;
    n&=n-1;
    return ones;
}

#define POW(c)(1<<(c))
#define MASK(c)  (((unsigned long)-1)/(POW(POW(c))+1)
#define ROUND(n,c) (((n) & MASK(c))+((n)>>POW(c) & MASK(c)))
int countOnes(unsigned int n)//O(log2W)
{
    n=ROUND(n,0);
    n=ROUND(n,2);
    n=ROUND(n,3);
    n=ROUND(n,4);
    n=ROUND(n,5);
    return n;
}
